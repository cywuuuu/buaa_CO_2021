`timescale 1ns / 1ps
`include "const.v"
`default_nettype wire

module EXT(
	input [15:0] imm16,
	input [2:0] EXT_op,
	output reg [31:0] EXTout
	);

	always @(*) begin
		case(EXT_op) 
			`EXT_unsigned:	EXTout = {{16{1'b0}}, imm16};
			`EXT_signed: EXTout = {{16{imm16[15]}}, imm16};
			`EXT_lui: EXTout = {imm16, {16{1'b0}}};
			default: EXTout = 0;
		endcase
	end
	
endmodule
