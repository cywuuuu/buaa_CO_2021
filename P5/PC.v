`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    08:52:40 10/25/2021 
// Design Name: 
// Module Name:    PC 
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
module PC(
    input clk,
    input [31:0] NPC,
    output reg [31:0] PC,
    input reset,
	 input en
    );

	 initial begin
		PC <= `PC_default;
	 end
	 always@(posedge clk)begin
		if(reset)begin
			PC <= `PC_default;
		end
		else if(en)begin
			PC <= NPC;
		end
	end

endmodule
