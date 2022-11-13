`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    13:05:31 12/08/2021 
// Design Name: 
// Module Name:    shishi 
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
module shishi(
    input [31:0] A,
    output [31:0] cnt
    );

	assign cnt = +A[31:0];
endmodule
