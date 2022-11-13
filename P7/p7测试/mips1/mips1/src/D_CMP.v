`timescale 1ns / 1ps
`include "const.v"
`default_nettype wire

module CMP(
	input [31:0] A,
	input [31:0] B,
	input [4:0] CMP_op,
	output reg cmp
	);
	always @(*) begin
		case(CMP_op)
			`CMP_eq: cmp = (A==B)? 1:0;
			`CMP_ne: cmp = (A!=B)? 1:0;
			`CMP_gtz: cmp = (!A[31] && A!=0)? 1:0;
			`CMP_gez: cmp = (!A[31])? 1:0;
			`CMP_ltz: cmp = (A[31] && A!=0)? 1:0;
			`CMP_lez: cmp = (A[31] || A==0)? 1:0;
			`CMP_rtez: cmp = (B==0)? 1:0;
			`CMP_rtnez: cmp = (B!=0)? 1:0;
			default: cmp = 0;
		endcase
	end
endmodule
