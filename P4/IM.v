`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    09:10:23 10/25/2021 
// Design Name: 
// Module Name:    IM 
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
module IM(
    input [31:0] PC,
	 input clk,
    output [31:0] instr
    );
	reg [31:0] instr_memory[`IM_SIZE-1:0];
	integer i;
	initial begin
		for(i = 0; i < `IM_SIZE; i = i + 1)begin
			instr_memory[i] = 0;
		end
		$readmemh("code.txt", instr_memory);
		  //$display("0x00: %h", instr_memory[8'h00]);
        //$display("0x01: %h", instr_memory[8'h01]);
        //$display("0x55: %h", instr_memory[8'h55]);
        //$display("0x56: %h", instr_memory[8'h56]);
		  //$display("%h:%h", PC,instr_memory[PC[11:2]]);
	end
	assign instr = instr_memory[PC[`IM_HIGH:2]];

endmodule
