`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    08:52:40 10/25/2021 
// Design Name: 
// Module Name:    PC 
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
`include "./header.v"
module PC(
    input clk,
    input [31:0] NPC,
	 input [31:0] EPC,
	 input D_iseret,
	 output exc_AdEL, 
    output [31:0] PC,
    input reset,
	 input en
    );
//���������п��ܳ��� eret ָ��������һ���� nop ָ��������������Ӧ�ñ�֤ eret �ĺ���ָ���ִ�С�
// eret ����ʹ�������� ͬʱ����ӳٲ�

//����AdEL ʱ�� ��ָ��ֱ�ӱ��0����������; ��PC������ˮ������������
	 initial begin
		fake_PC <= `PC_default;
	 end
	 reg[31:0] fake_PC;
	 //�����л���ʡ����nop�ˣ� ֱ�ӻ���
	 assign PC = D_iseret ? EPC : fake_PC; 
	 always@(posedge clk)begin
		if(reset)begin
			fake_PC <= `PC_default;
		end
		else if(en)begin
			fake_PC <= NPC;
		end
	end//���Ǻ��Ե�eret��EPC���ܲ������쳣��eret��EPCӦ�ò����쳣
	assign exc_AdEL = ((|PC[1:0]) | (PC < `im_addr_begin) | (PC > `im_addr_end)) && (~D_iseret);  //&& ~D_iseret; //�������ˣ�eret�պ�
endmodule
