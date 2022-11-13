`timescale 1ns / 1ps
`include "const.v"
`default_nettype wire

module E2M(
	input [31:0] E_Instr,
	input [31:0] E_PC,
	input [31:0] E_PC8,
	input [31:0] E_RS,
	input [31:0] E_RT,
	input [31:0] E_ALU_C,
	input [31:0] E_MDU_OUT,
	input [31:0] E_EXT_OUT,
	input E_cmp,
	input E2M_en,
	input clk,
	input req,
	input reset,
	input E2M_flush,
	output reg [31:0] M_Instr,
	output reg [31:0] M_PC,
	output reg [31:0] M_PC8,
	output reg [31:0] M_RS,
	output reg [31:0] M_RT,
	output reg [31:0] M_ALU_C,
	output reg [31:0] M_MDU_OUT,
	output reg [31:0] M_EXT_OUT,
	output reg M_cmp,
	
	input [4:0] E_excode,
	input E_db,
	output reg [4:0] M_excode,
	output reg M_db
	);
	
	always @(posedge clk) begin
		if(reset||E2M_flush||req) begin
			M_Instr	<= 0;
			M_PC8		<= 0;
			M_RS		<= 0;
			M_RT		<= 0;
			M_ALU_C	<= 0;
			M_MDU_OUT <= 0;
			M_EXT_OUT <= 0;
			M_cmp		<= 0;
			
			M_PC <= (E2M_flush)? E_PC: (req? 32'h00004180: 0);
			M_excode <= 0;
			M_db <= (E2M_flush)? E_db: 0;
		end
		else if(E2M_en) begin
			M_Instr	<= E_Instr;
			M_PC		<= E_PC;
			M_PC8		<= E_PC8;
			M_RS 		<= E_RS;
			M_RT		<= E_RT;
			M_ALU_C	<= E_ALU_C;
			M_MDU_OUT <= E_MDU_OUT;
			M_EXT_OUT <= E_EXT_OUT;
			M_cmp		<= E_cmp;
			M_excode	<= E_excode;
			M_db		<= E_db;
		end
	end

endmodule
