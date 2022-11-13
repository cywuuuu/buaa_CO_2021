`timescale 1ns / 1ps
`include "const.v"
`default_nettype wire

module IFU(
	input clk,
	input reset,
	input req,
	input D_eret,
	input IFU_en,
	input [31:0] NPC,
	input [31:0] EPC,
	input [31:0] i_inst_rdata,
   output [31:0] i_inst_addr,
	output [31:0] PC,
	output [31:0] Instr,
	output F_adel
	);
	
	integer i;
	reg [31:0] pc;
	reg [31:0] im [5119:0];
	
	initial begin
		for(i=0;i<4096;i=i+1) im[i] = 0;
		pc = 32'h00003000;
		$readmemh("code.txt", im);
		$readmemh("code_handler.txt", im, 1120, 2047);
	end
	
	always @(posedge clk) begin
		if(reset) pc <= 32'h00003000;
		else if(IFU_en|req) pc <= NPC;
	end
	
	assign F_adel = !D_eret && (PC[1:0]!=0||PC<32'h3000||PC>32'h6fff);
	
	assign PC = (D_eret)? EPC: pc;
	//what if exception handler is very short
	assign i_inst_addr = PC;
	assign Instr = (F_adel)? 0: i_inst_rdata;

endmodule
