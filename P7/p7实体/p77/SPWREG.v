`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:48:20 11/17/2021 
// Design Name: 
// Module Name:    SPWREG 
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
module SPWREG(
    input [31:0] PC,
    input [31:0] instr,
    input [31:0] CAL_res,
    input [31:0] DM_RD,
	 input [31:0] RD2,
	 input [2:0] W_fwd_src_sel,	
	 input [1:0] cmp,
	 input [1:0] zero,
	 input [31:0] CP0_RD,
	 input int_exc_req, 
    output reg[31:0] W_PC,
    output reg[31:0] W_instr,
    output reg[31:0] W_CAL_res,
    output reg[31:0] W_DM_RD,
	 output reg[31:0] W_RD2,
	 output reg[1:0] W_cmp,
	 output reg[1:0] W_zero,
	 output reg [31:0] W_CP0_RD, 
	 output [31:0] W_fwd_src,
	 
    input clk,
    input en,
    input reset
    );
	always @(posedge clk)begin
		if(reset) begin
			W_PC <= 0;
			W_instr <= 0;
			W_CAL_res  <= 0;
			W_DM_RD <= 0;
			W_zero <= 0;
			W_cmp <= 0;
			W_RD2 <= 0;
			W_CP0_RD <= 0;
		end
		else if(int_exc_req)begin
			W_PC <= `PC_kernel;
			W_instr <= 0;
			W_CAL_res  <= 0;
			W_DM_RD <= 0;
			W_zero <= 0;
			W_cmp <= 0;
			W_RD2 <= 0;
			W_CP0_RD <= 0; 
		end
		else if(en)begin
			W_PC <= PC;
			W_instr <= instr;
			W_CAL_res <= CAL_res;
			W_DM_RD <= DM_RD;
			W_zero <= zero;
			W_cmp <= cmp;
			W_RD2 <= RD2;
			W_CP0_RD <= CP0_RD; 
		end
	end
	assign W_fwd_src = (W_fwd_src_sel == `fwd_src_CALres)  ? W_CAL_res : 
							 (W_fwd_src_sel == `fwd_src_DM_RD)   ? W_DM_RD :
							 (W_fwd_src_sel == `fwd_src_RD2)		 ? W_RD2 :
							 (W_fwd_src_sel == `fwd_src_PC8)     ? W_PC+8 : 
							 (W_fwd_src_sel == `fwd_src_CP0) ? W_CP0_RD : 
							 0;
endmodule
