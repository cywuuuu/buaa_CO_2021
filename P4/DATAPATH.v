`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    23:09:20 11/02/2021 
// Design Name: 
// Module Name:    mips 
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
module DATAPATH(
    input clk,
    input reset,
	 input [2:0]NPCop,
	 input reg_write,
	 input [2:0]reg_dst,
	 input [2:0]which_to_reg,
	 input [1:0]ALU_src, 
	 input [4:0]ALU_op,
	 input mem_write, 
	 input sign,
	 input [1:0]LS_op,
	 output [5:0]opcode, 
	 output [5:0]func,
	 output [1:0]zero,
	 output [1:0]cmp,
	 output [4:0]rt
    );
	
	//wire reg_write, alu_src, branch, mem_write, jr, j, sign;
	//wire [2:0] reg_dst, which_to_reg;
	//wire [4:0] alu_op;
	wire [31:0] NPC;
	wire [31:0] PC;
	wire [4:0] rs, rd;
	wire [25:0] imm26;
	wire [15:0] imm16;
	wire [4:0] shamt;
	wire [31:0] jreg = grf_RD1;	
	wire [4:0] A3;
	wire [31:0] RD1;
	wire [31:0] A;
	//splitter 
	wire [31:0] instr;
	assign opcode = instr[31:26];
	assign func = instr[5:0];
	assign rs = instr[25:21];
	assign rt = instr[20:16];
	assign rd = instr[15:11];
	assign imm26 = instr[25:0];
	assign shamt = instr[10:6];
	assign imm16 = instr[15:0];
	//
	wire [31:0]ALU_res, dm_RD, grf_RD1, grf_RD2;
	PC i_pc		(.clk(clk), .reset(reset), .NPC(NPC), 
				    .PC(PC));
				

	//NPC

	NPC i_npc 	(.PC(PC), .imm26(imm26), .jreg(grf_RD1), .NPCop(NPCop),
				    .NPC(NPC));
	//IM
	 
	IM i_im		(.PC(PC), .clk(clk), 
	             .instr(instr));





	// A3_in MUX special name because mux, always give output a parts.name
	wire [4:0] grf_A3_mux = (reg_dst == `sel_rd) ? rd : 
						(reg_dst == `sel_rt) ? rt :
						(reg_dst == `sel_31) ? 31 : 
						23;// default 23
	// WD_in MUX

	wire [31:0] grf_WD3_mux = (which_to_reg == `sel_PC4) ?  (PC+4) :
						(which_to_reg == `sel_res) ?  ALU_res : 
						(which_to_reg == `sel_dm)  ?  dm_RD :
						233333;
						
	GRF i_grf 	(.clk(clk), .WE(reg_write), .reset(reset), .PC(PC), .A1(rs), .A2(rt), 
					 .A3(grf_A3_mux), .WD3(grf_WD3_mux), 
					 .RD1(grf_RD1),  .RD2(grf_RD2));

/*
module EXT(
    input [15:0] imm16,
    input sign,
    output [31:0] ext_imm32
    );
*/

	wire [31:0] ext_imm32;
	EXT i_ext (.imm16(imm16), .sign(sign), .ext_imm32(ext_imm32));
	
	/*
	// sel ALU_srcB
	`define sel_RD2   2'b00
	`define sel_imm32 2'b01
	*/
	wire [31:0] ALU_B_mux = 	(ALU_src == `sel_RD2) ? grf_RD2:
										(ALU_src == `sel_imm32) ? ext_imm32:
										32'h233333;
/*
module ALU(
    input [4:0] ctrl,
	 output overflow,
    input [31:0] A,
    input [31:0] B,
    input [4:0] shamt,
    output [1:0] zero,
	 output [1:0] cmp,
    output [31:0] result
    );
*/
	ALU i_alu   (.ctrl(ALU_op), .overflow(overflow), 
		.A(grf_RD1), .B(ALU_B_mux), .zero(zero), .cmp(cmp), .result(ALU_res), .shamt(shamt));

	DM  i_dm		(.clk(clk), .reset(reset), .WE(mem_write), .PC(PC), 
				 .A(ALU_res), .WD(grf_RD2), .RD(dm_RD), .LS_op(LS_op));
/*
module DASM (
	input [31:0] pc,
    input [31:0] instr,
	input reg_name,
	input imm_as_dec,
    output [32*8-1:0] asm
);
*/
	wire [32*8-1:0]asm;
	//DASM i_dasm	(.pc(PC), .instr(instr), .reg_name(1'b1), .imm_as_dec(1'b0), .asm(asm));
endmodule
