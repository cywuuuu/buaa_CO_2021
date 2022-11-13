`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    23:03:59 10/24/2021 
// Design Name: 
// Module Name:    GRF 
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
module GRF(
    input clk,
    input WE,
    input reset,
    input [4:0] A1,
    input [4:0] A2,
    input [4:0] A3,
    input [31:0] WD3,
	 input [31:0] PC,
    output [31:0] RD1,
    output [31:0] RD2
    );
	 reg [31:0] register_file [31:0];
	 integer i;
	 initial begin
		for(i = 0; i < 32; i = i + 1)begin
			register_file[i] = 32'h0; 
		end
	 end
	 always@(posedge clk)begin
		if(reset) begin
			for( i = 0; i < 32; i = i + 1)begin
				register_file[i] = 32'h0; 
			end
		end
		else begin
			if(WE)begin
				if(A3 != 0)begin
					register_file[A3] <= WD3;
					end
				$display("@%h: $%d <= %h", PC, A3, WD3);
			end
			else begin
				register_file[0] <= 32'h0;
			end
		end
	 end
	 assign RD1 = register_file[A1];
	 assign RD2 = register_file[A2];
	 //assign register_file[0] = 0;


endmodule
