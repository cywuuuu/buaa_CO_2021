`timescale 1ns / 1ps
`include "const.v"
`default_nettype wire

module F2D(
	input [31:0] F_Instr,
	input [31:0] F_PC,
	input F2D_en,
	input F2D_flush,
	input clk,
	input req,
	input reset,
	output reg [31:0] D_Instr,
	output reg [31:0] D_PC,
	
	input [4:0] F_excode,
	input F_db,
	output reg [4:0] D_excode,
	output reg D_db
	);

	always @(posedge clk) begin
		if(reset||F2D_flush||req) begin
			D_Instr <= 0;
			D_PC <= (F2D_flush)? F_PC: (req? 32'h00004180: 0);
			D_excode <= 0;
			D_db <= (F2D_flush)? F_db: 0;
		end
		else if(F2D_en) begin
			D_Instr <= F_Instr;
			D_PC <= F_PC;
			D_excode <= F_excode;
			D_db <= F_db;
		end
	end

endmodule
