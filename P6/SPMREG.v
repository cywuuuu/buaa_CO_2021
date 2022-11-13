`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:16:21 11/17/2021 
// Design Name: 
// Module Name:    SPMREG 
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
module SPMREG(
    input [31:0] instr,
    input [31:0] PC,
	 input [31:0] RD2,
	 input [31:0] CAL_res,
	 input [2:0] M_fwd_src_sel,
	 input [1:0] cmp, 
	 input [1:0] zero,
	 output reg[31:0] M_CAL_res,
	 output reg[31:0] M_RD2,
    output reg[31:0] M_PC,
    output reg[31:0] M_instr,
	 output reg[1:0] M_cmp,
	 output reg[1:0] M_zero,
	 output [31:0] M_fwd_src,
    input en,
    input reset,
    input clk
    );
	 always @ (posedge clk)begin
		if(reset)begin
			M_PC <= 0;
			M_instr <= 0;
			M_CAL_res <= 0;
			M_RD2 <= 0;
			M_zero <= 0;
			M_cmp <= 0;
		end
		else if (en)begin
			M_PC <= PC;
			M_instr <= instr;
			M_RD2 <= RD2;
			M_CAL_res <= CAL_res;
			M_zero <= zero;
			M_cmp <= cmp;
		end
	 end
	assign M_fwd_src = (M_fwd_src_sel == `fwd_src_CALres)  ? M_CAL_res : 
							 (M_fwd_src_sel == `fwd_src_DM_RD)   ? 0 :
							 (M_fwd_src_sel == `fwd_src_PC8)     ? M_PC+8 : 
							 0;
endmodule
