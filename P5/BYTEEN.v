`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    08:37:59 11/25/2021 
// Design Name: 
// Module Name:    BYTEEN 
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
module BYTEEN(
    input [31:0] A,
	 input WE,
	 input [1:0]LS_op, 
    output reg[3:0] byte_en
    );
/*
		else if(WE)begin
			if(LS_op == `LS_w)data_memory[A[`DM_HIGH:2]] <= WD;
			else if(LS_op == `LS_h) begin
				if(A[1]==1'b0)data_memory[A[`DM_HIGH:2]][15:0] <= WD[15:0];
				else data_memory[A[`DM_HIGH:2]][31:16] <= WD[15:0];
			end
			else begin 
				if(A[1:0] == 2'b00)data_memory[A[`DM_HIGH:2]][7:0] <= WD[7:0];
				else if(A[1:0] == 2'b01)data_memory[A[`DM_HIGH:2]][15:8] <= WD[7:0];
				else if(A[1:0] == 2'b10)data_memory[A[`DM_HIGH:2]][23:16] <= WD[7:0];
				else data_memory[A[`DM_HIGH:2]][31:24] <= WD[7:0];
			end
*/
	always  @ (*)begin
		if(WE) begin
			if(LS_op == `LS_w) byte_en = 4'b1111;
			else if(LS_op == `LS_h) begin
				if(A[1] == 1'b0)  byte_en = 4'b0011;
				else if(A[1] == 1'b1) byte_en = 4'b1100;
			end
			else if(LS_op == `LS_b)begin
				if(A[1:0] == 2'b00) byte_en = 4'b0001;
				else if(A[1:0] == 2'b01) byte_en = 4'b0010;
				else if(A[1:0] == 2'b10) byte_en = 4'b0100;
				else if(A[1:0] == 2'b11) byte_en = 4'b1000;
			end
		end
		else begin
			byte_en = 4'b0000;
		end

	end








endmodule
