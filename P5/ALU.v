`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    08:52:41 11/01/2021 
// Design Name: 
// Module Name:    ALU 
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
// lui ÄØ
/*
// ALU control
// define ²»ÄÜ; Syntax error near ";"
`define ALU_add 5'b00000
`define ALU_sub 5'b00001
`define ALU_and 5'b00010
`define ALU_or  5'b00011
`define ALU_sll 5'b00100
`define ALU_slt 5'b00101
`define ALU_lui 5'b00110
`define ALU_sla 5'b00111
`define ALU_sllv 5'b01000
*/
module ALU(
    input [4:0] ctrl,
	 output overflow,
    input [31:0] A,
    input [31:0] B,
    input [4:0] shamt,
    output [31:0] result
    );
	 assign cmp =  (A == B)? `cmp_eq: 
						(A > B) ? `cmp_gt:
						(A < B) ? `cmp_lt:
						2'b00;
	 
	 assign zero = (A == 0) ? `zero_eq:
						(A > 0)  ? `zero_gt:
						(A < 0)  ? `zero_lt:
						2'b00;
	 /*
	`define ALU_xor 5'b01001
	`define ALU_nor 5'b01010
	 */
	 assign result = (ctrl == `ALU_add) ?  (A+B) :
						  (ctrl == `ALU_sub) ?  (A-B) :
						  (ctrl == `ALU_and) ?  (A&B) :
						  (ctrl == `ALU_or)  ?  (A|B) :
						  (ctrl == `ALU_sll) ?  (B<<shamt):
						  (ctrl == `ALU_sllv) ? (B<<A[4:0]) :
						  (ctrl == `ALU_slt) ?  ($signed(A)<$signed(B)) : 
						  (ctrl == `ALU_sltu) ? (A<B) :
						  (ctrl == `ALU_lui) ? 	({B[15:0], 16'h0}) :
						  (ctrl == `ALU_xor) ?  (A^B) : 
						  (ctrl == `ALU_nor) ?  (~(A|B)) :
						  (ctrl == `ALU_srl) ?  (B>>shamt):
						  (ctrl == `ALU_sra) ? 	$signed($signed(B) >>> $signed(shamt)):
						  (ctrl == `ALU_srlv) ? (B>>A[4:0]):
						  (ctrl == `ALU_srav) ? $signed($signed(B) >>> $signed(A[4:0])):
						  32'h23333;

//ori,andi 0ext(not done), branch imm26 signext(done),slti sign_ext(not done), sh/sw sign_ext(done)
//addi s_ext(not done),   
endmodule
