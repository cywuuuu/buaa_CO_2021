`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    08:50:11 11/25/2021 
// Design Name: 
// Module Name:    DATA_EXT 
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
module DATA_EXT(
    input [31:0] A,
    input [31:0] RDin,
    input [1:0] LS_op,
	 input DM_sign, 
    output reg[31:0] RDout
    );
	 always @ (*)begin
		case(LS_op)
		`LS_w: RDout = RDin;
		`LS_h: begin
			if(DM_sign) begin
				if(A[1] == 0) RDout = {{16{RDin[15]}},RDin[15:0]};
				else RDout = {{16{RDin[31]}},RDin[31:16]};
			end
			else  begin
				if(A[1] == 0) RDout = {16'b0,RDin[15:0]};
				else RDout = {16'b0,RDin[31:16]};
			end
		end
		`LS_b: begin
			if(DM_sign) begin
				if(A[1:0] == 2'b00) RDout = {{24{RDin[7]}}, RDin[7:0]};
				else if(A[1:0] == 2'b01) RDout = {{24{RDin[15]}}, RDin[15:8]};
				else if(A[1:0] == 2'b10) RDout = {{24{RDin[23]}}, RDin[23:16]};
				else RDout = {{24{RDin[31]}}, RDin[31:24]};
			end
			else begin
				if(A[1:0] == 2'b00) RDout = {24'b0, RDin[7:0]};
				else if(A[1:0] == 2'b01) RDout = {24'b0, RDin[15:8]};
				else if(A[1:0] == 2'b10) RDout = {24'b0, RDin[23:16]};
				else RDout = {24'b0, RDin[31:24]};				
			end
		end
		endcase
	 end
/*
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

*/

endmodule
