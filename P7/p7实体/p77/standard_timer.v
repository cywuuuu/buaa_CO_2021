`timescale 1ns / 1ps
`define IDLE 2'b00
`define LOAD 2'b01
`define CNT  2'b10
`define INT  2'b11

`define ctrl   mem[0]//���ƼĴ���
`define preset mem[1]//��ֵ�Ĵ���
`define count  mem[2]//�����Ĵ���
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:43:39 12/28/2017 
// Design Name: 
// Module Name:    TC 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module TC(
    input clk,
    input reset,
    input [31:2] Addr,
    input WE,
    input [31:0] Din,
    output [31:0] Dout,
    output IRQ
    );

	reg [1:0] state;
	reg [31:0] mem [2:0];
	
	reg _IRQ;///ģʽ0�¼������Ĵ���ֵΪ0
	assign IRQ = `ctrl[3] & _IRQ;//���ж����������ж�����
	
	assign Dout = mem[Addr[3:2]];//���which�Ĵ���
	//����addr����00-0b�ĵ�ַ����ֻȡ [3:2] ��Ϊ
	// [00]00, [01]00, [10]00, �ֱ����������4byte�Ĵ����ĳ�ʼ��ַѡ��
	wire [31:0] load = Addr[3:2] == 0 ? {28'h0, Din[3:0]} : Din;
	// ��ȡctrl, 00�Ĵ���δ����λ������,
	// ��Ϊд��ctrl�Ĵ���ʱ��δ����λ31��4������
	/*
		Reserved 31:4 ���� �� 0
		IM 3
		�ж�����
		0����ֹ�ж�
		1�������ж�
		///////
		Mode 2:1
		ģʽѡ��
		00����ʽ 0
		01����ʽ 1
		10��δ����
		11��δ����
		///////
		Enable 0
		������ʹ��
		0��ֹͣ����
		1���������
		R/W 
	*/
	integer i;
	always @(posedge clk) begin
		if(reset) begin
			state <= 0; 
			for(i = 0; i < 3; i = i+1) mem[i] <= 0;
			_IRQ <= 0;
		end
		else if(WE) begin
			// $display("%d@: *%h <= %h", $time, {Addr, 2'b00}, load);
			mem[Addr[3:2]] <= load;//д��Ĵ���
		end
		else begin
			case(state)
				`IDLE : if(`ctrl[0]) begin//ctrl[0] enable ����
					state <= `LOAD;
					_IRQ <= 1'b0;//��û�ж�
				end
				`LOAD : begin
					`count <= `preset;//��ʼ�����ֵ
					state <= `CNT;
				end
				`CNT  : 
					if(`ctrl[0]) begin//enable = 1������ʼ
						if(`count > 1) `count <= `count-1;
						else begin//��ʱ�ѵ�
							`count <= 0;//��������Ĵ���
							state <= `INT;
							_IRQ <= 1'b1;//��ʼ�жϣ����ж�����
						end
					end
					else state <= `IDLE;//ͻȻenableֹͣ������������״���� ����idle
				default : begin
					if(`ctrl[2:1] == 2'b00) `ctrl[0] <= 1'b0;//�ж�̬ ��ģʽ0 ֹͣ����������һֱ�ж�
					else _IRQ <= 1'b0;//ģʽ1 �ص���ֵ
					state <= `IDLE;
				end
			endcase
		end
	end

endmodule
