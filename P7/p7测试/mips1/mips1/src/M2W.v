`timescale 1ns / 1ps
`include "const.v"
`default_nettype wire

module M2W(
	input [31:0] M_Instr,
	input [31:0] M_PC,
	input [31:0] M_PC8,
	input [31:0] M_RS,
	input [31:0] M_RT,
	input [31:0] M_ALU_C,
	input [31:0] M_MDU_OUT,
	input [31:0] M_EXT_OUT,
	input [31:0] M_CP0_OUT,
	input [31:0] M_DM_OUT,
	input M_cmp,
	input M_chk,
	input M2W_en,
	input clk,
	input req,
	input reset,
	output reg [31:0] W_Instr,
	output reg [31:0] W_PC,
	output reg [31:0] W_PC8,
	output reg [31:0] W_RS,
	output reg [31:0] W_RT,
	output reg [31:0] W_ALU_C,
	output reg [31:0] W_MDU_OUT,
	output reg [31:0] W_EXT_OUT,
	output reg [31:0] W_CP0_OUT,
	output reg [31:0] W_DM_OUT,
	output reg W_cmp,
	output reg W_chk
	);

	always @(posedge clk) begin
		if(reset||req) begin
			W_Instr	<= 0;
			W_PC		<= (req)? 32'h4180: 0;
			W_PC8		<= 0;
			W_RS		<= 0;
			W_RT		<= 0;
			W_ALU_C	<= 0;
			W_MDU_OUT <= 0;
			W_EXT_OUT <= 0;
			W_CP0_OUT <= 0;
			W_DM_OUT	<= 0;
			W_cmp		<= 0;
			W_chk		<= 0;
		end
		else if(M2W_en) begin
			W_Instr	<= M_Instr;
			W_PC		<= M_PC;
			W_PC8		<= M_PC8;
			W_RS 		<= M_RS;
			W_RT		<= M_RT;
			W_ALU_C	<= M_ALU_C;
			W_MDU_OUT <= M_MDU_OUT;
			W_EXT_OUT <= M_EXT_OUT;
			W_CP0_OUT <= M_CP0_OUT;
			W_DM_OUT	<= M_DM_OUT;
			W_cmp		<= M_cmp;
			W_chk		<= M_chk;
		end
	end

endmodule
