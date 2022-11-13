`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    13:55:34 11/17/2021 
// Design Name: 
// Module Name:    SPDREG 
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
`include "header.v"
module SPDREG(
    input [31:0] instr,
    input [31:0] PC,
    output reg[31:0] D_PC,
    output reg[31:0] D_instr,
    input en,
    input reset,
    input clk
    );
	 always @ (posedge clk)begin
		if(reset) begin
			D_PC <= `PC_default;
			D_instr <= 0;
		end
		else begin
			if(en)begin
				D_PC <= PC;
				D_instr <= instr;
			end
		end
	 end


endmodule
