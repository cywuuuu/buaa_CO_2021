`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    08:25:53 10/25/2021 
// Design Name: 
// Module Name:    DM 
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
module DM(
    input clk,
    input WE,
	 input [31:0] PC,
	 input [1:0] LS_op,
    output reg[31:0] RD,
    input [31:0] A,
    input [31:0] WD,
	 input reset
    );
	 reg [31:0] data_memory[`DM_SIZE-1:0];// 4个字一个地址
	 integer i;
	 initial begin
		for(i = 0; i < `DM_SIZE; i = i+1)begin
			data_memory[i] = 0;
		end
	 end
	 always @ (posedge clk)begin
		if(reset)begin
			for(i = 0; i < `DM_SIZE; i = i+1)begin
				data_memory[i] = 0;
			end
		end
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
			$display("%d@%h: *%h <= %h", $time, PC, A, WD);
		end
	 end
	 
	always @ (*)begin
			if(LS_op == `LS_w)RD = data_memory[A[`DM_HIGH:2]];
			else if(LS_op == `LS_h) begin
				if(A[1]==1'b0)RD = data_memory[A[`DM_HIGH:2]][15:0];
				else RD = data_memory[A[`DM_HIGH:2]][31:16];
			end
			else begin 
				if(A[1:0] == 2'b00)RD = data_memory[A[`DM_HIGH:2]][7:0];
				else if(A[1:0] == 2'b01)RD = data_memory[A[`DM_HIGH:2]][15:8];
				else if(A[1:0] == 2'b10)RD = data_memory[A[`DM_HIGH:2]][23:16];
				else RD = data_memory[A[`DM_HIGH:2]][31:24] <= WD[7:0];
			end
	end

endmodule
