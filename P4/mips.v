`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:17:17 11/11/2021 
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
module mips(
    input clk,
    input reset
    );
	 /*
	 module CTRL(
    input [5:0] opcode,
    input [5:0] func,
	 input [1:0] cmp,
	 input [1:0] zero, 
	 input [4:0] rt,
    output reg_write,
    output [2:0] reg_dst,
    output [2:0] which_to_reg,
	 output [1:0] ALU_src,
    output mem_write,
	 output [2:0] NPCop,
	 output sign,
	 output [4:0] ALU_op
    );
	 */
	 wire [5:0] opcode;
	 wire [5:0] func;
	 wire [1:0] cmp;
    wire [1:0] zero; 
	 wire [4:0] rt; 
	 wire [2:0] reg_dst;
	 wire [2:0] which_to_reg;
	 wire [1:0] ALU_src;
	 wire [2:0] NPCop;
	 wire [4:0] ALU_op;
	 wire [1:0] LS_op;
	 wire reg_write, mem_write, sign;
		CTRL i_ctrl 	(.opcode(opcode), .func(func), .cmp(cmp), .zero(zero), .rt(rt), 
							.reg_write(reg_write), .reg_dst(reg_dst), .which_to_reg(which_to_reg), 
							.ALU_src(ALU_src), .mem_write(mem_write), .NPCop(NPCop), .sign(sign), .ALU_op(ALU_op), .LS_op(LS_op));
	 /*
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
	 output [5:0]opcode, 
	 output [5:0]func,
	 output [1:0]zero,
	 output [1:0]cmp,
	 output [4:0]rt
    );
	 */
	DATAPATH i_datapath	(.clk(clk), .reset(reset), .NPCop(NPCop), 
								.reg_write(reg_write), .reg_dst(reg_dst), .which_to_reg(which_to_reg), 
								.ALU_src(ALU_src), .ALU_op(ALU_op), .mem_write(mem_write), 
								.opcode(opcode), .func(func), .zero(zero), .cmp(cmp), .rt(rt), .sign(sign), .LS_op(LS_op));

endmodule
