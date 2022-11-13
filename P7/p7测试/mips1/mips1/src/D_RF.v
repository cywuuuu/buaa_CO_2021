`timescale 1ns / 1ps
`default_nettype wire

module RF(
	input [4:0] A1,
	input [4:0] A2,
	input [4:0] A3,
	input [31:0] WD,
	input [31:0] PC,
	input [31:0] Instr,
	input reset,
	input RF_wr,
	input clk,
	output [31:0] RD1,
	output [31:0] RD2,
	output reg w_grf_we,
	output reg [4:0] w_grf_addr,
   output reg [31:0] w_grf_wdata,
	output reg [31:0] w_inst_addr
	);

	reg [31:0] rf[31:0];
	integer i, fp;
	
	initial begin
		for(i=0; i<32; i=i+1) begin
			rf[i] <= 0;
		end
	end
	
	//********************temp_GRF
	always @(*) begin
		w_grf_addr <= A3;
		w_grf_wdata <= WD;
		w_inst_addr	<= PC;
		w_grf_we <= (RF_wr && A3);
	end
	
	always @(posedge clk or posedge reset) begin
		if(reset) begin
			for(i=0; i<32; i=i+1) begin
				rf[i] <= 0;
			end
		end
		else begin
			if(RF_wr && A3) begin
				rf[A3] <= WD;
				//$display("%h @%h: $%d <= %h", Instr, PC, A3, WD);
				//$fdisplay(fp,"%b",Instr);
			end
		end
	end

	assign RD1 = (A1==0)? 0:
					 (A1==A3&&RF_wr)? WD:
					 rf[A1];
	assign RD2 = (A2==0)? 0:
					 (A2==A3&&RF_wr)? WD:
					 rf[A2];
	
endmodule