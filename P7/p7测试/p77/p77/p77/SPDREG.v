`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    13:55:34 11/17/2021 
// Design Name: 
// Module Name:    SPDREG 
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
module SPDREG(
    input [31:0] instr,
    input [31:0] PC,
	 input DB,
	 input [4:0]exc_code, 
	 input D_null_slot, 
    output reg[31:0] D_PC,
    output reg[31:0] D_instr,
	 output reg D_DB, 
	 output reg [4:0]D_exc_code, 
    input en,
    input reset,
	 input int_exc_req,
    input clk
    );
	 always @ (posedge clk)begin
		if(reset) begin
			D_PC <= `PC_default;
			D_DB <= 0;
			D_exc_code <= 0;
			D_instr <= 0;
		end
		else if(int_exc_req)begin
			D_PC <= `PC_kernel; //��ֹ���PC�Ҵ�, ���Ǳ�֤������������� macroscopic_pc[31:0] ������Ѱ�� CPU ���ܵ�"����"״̬���Դ�Ϊ���ݲ����ж��ź�
			D_DB <= 0; 
			D_exc_code <= 0;
			D_instr <= 0;
		end
		else if(D_null_slot)begin
			D_instr <= 0;
		end
		else begin
			if(en)begin
				D_PC <= PC;
				D_instr <= exc_code ? 0 : instr;
				D_DB <= DB;
				D_exc_code <= exc_code; //interrupt > ���� > ��һ��,
			end
		end
	 end


endmodule
