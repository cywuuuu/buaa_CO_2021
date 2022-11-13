`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    08:41:16 11/02/2021 
// Design Name: 
// Module Name:    EXT 
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
module EXT(
    input [15:0] imm16,
    input sign,
    output [31:0] ext_imm32
    );
	
	assign ext_imm32 = (sign == `ext_zero) ? ({{16{1'b0}}, imm16}) : 
							 (sign == `ext_sign) ? ({{16{imm16[15]}}, imm16}) : 
							 0;
	
endmodule
