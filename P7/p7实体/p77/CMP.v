     `timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    08:24:04 11/18/2021 
// Design Name: 
// Module Name:    CMP 
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
module CMP(
    input [31:0] A,
    input [31:0] B,
    output [1:0] cmp,
    output [1:0] zero
    );
		 assign cmp =  ($signed(A) == $signed(B))? `cmp_eq: 
						($signed(A) > $signed(B)) ? `cmp_gt:
						($signed(A) < $signed(B)) ? `cmp_lt:
						2'b00;
	 
	 assign zero = ($signed(A) == $signed(0)) ? `zero_eq:
						($signed(A) > $signed(0))  ? `zero_gt:
						($signed(A) < $signed(0))  ? `zero_lt:
						2'b00;

endmodule
