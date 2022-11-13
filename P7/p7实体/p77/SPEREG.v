`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:09:05 11/17/2021 
// Design Name: 
// Module Name:    SPEREG 
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
module SPEREG(
    input [31:0] instr,
    input [31:0] PC,
	 input [31:0] RD1, 
	 input [31:0] RD2,
	 input [31:0] ext_imm32,
	 input [2:0] E_fwd_src_sel,
	 input [1:0] cmp, 
	 input [1:0] zero,
	 input DB,
	 input [4:0]exc_code,
	 input stall,
	 output reg[31:0] E_RD1, 
	 output reg[31:0] E_RD2,
	 output reg[31:0] E_ext_imm32,
    output reg[31:0] E_PC,
    output reg[31:0] E_instr,
	 output reg[1:0] E_cmp,
	 output reg[1:0] E_zero,
	 output reg E_DB, 
	 output reg [4:0] E_exc_code, 
	 output [31:0]E_fwd_src,
    input en,
    input reset,
	 input int_exc_req, 
    input clk
    );
	always @ (posedge clk) begin
		if(reset)begin
			E_PC <= `PC_default;
			E_instr <= 0;
			E_RD1 <= 0;
			E_RD2 <= 0;
			E_ext_imm32 <= 0;
			E_cmp <= 0;
			E_zero <= 0;
			E_exc_code <= 0;
			E_DB <= 0; 
		end
		else if(int_exc_req)begin
			E_PC <= `PC_kernel;
			E_instr <= 0;
			E_RD1 <= 0;
			E_RD2 <= 0;
			E_ext_imm32 <= 0;
			E_cmp <= 0;
			E_zero <= 0;
			E_exc_code <= 0;
			E_DB <= 0; 
		end
		else if(stall)begin
			E_PC <= PC;//should be D_PC
			E_instr <= 0;
			E_RD1 <= 0;
			E_RD2 <= 0;
			E_ext_imm32 <= 0;
			E_cmp <= 0;
			E_zero <= 0;
			E_exc_code <= 0;
			E_DB <= DB; //1. DB如果stall时,也要跟着之前的，也算nop中断也算是延迟槽中断
		end
		else begin
			if(en)begin
				E_PC <= PC;
				E_instr <= exc_code ? 0 : instr;
				E_RD1 <= RD1;
				E_RD2 <= RD2;
				E_ext_imm32 <= ext_imm32;
				E_cmp <= cmp;
				E_zero <= zero;
				E_exc_code <= exc_code;
				E_DB <= DB;
			end
		end
	end
	/*
	`define fwd_src_ALUres 3'b011
`define fwd_src_DM_RD 3'b010
`define fwd_src_PC8 3'b001
	*/
	assign E_fwd_src = (E_fwd_src_sel == `fwd_src_CALres)  ? 0 : 
							 (E_fwd_src_sel == `fwd_src_DM_RD)   ? 0 :
							 (E_fwd_src_sel == `fwd_src_PC8)     ? E_PC+8 : 
							 0;
endmodule
