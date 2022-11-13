`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    00:15:47 12/11/2021 
// Design Name: 
// Module Name:    BRG 
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
module BRG(
    input [31:0] PrAddr,
    output [31:0] PrRD,//
    input [31:0] PrWD,
	 input PrWE, 
    output [31:0] DEV_Addr,//
    input [31:0] DEV0_RD,
    input [31:0] DEV1_RD,	 
	 output DEV0_WE,//
	 output DEV1_WE, //
    output [31:0] DEV_WD
    );
	 
	assign DEV_Addr = PrAddr;
	assign PrRD = (PrAddr <= `dev0_addr_end && PrAddr >= `dev0_addr_begin) ? DEV0_RD : 
					  (PrAddr <= `dev1_addr_end && PrAddr >= `dev1_addr_begin) ? DEV1_RD : 
					  32'h23333;
	assign DEV0_WE = (PrAddr <= `dev0_addr_end && PrAddr >= `dev0_addr_begin) && PrWE;
	assign DEV1_WE = (PrAddr <= `dev1_addr_end && PrAddr >= `dev1_addr_begin) && PrWE;	
	assign DEV_WD = PrWD;
endmodule
