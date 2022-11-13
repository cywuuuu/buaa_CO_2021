`timescale 1ns / 1ps
`default_nettype wire
`define itr_mask sr[15:10]
`define itr_en sr[0]
`define in_req	sr[1]

module CP0(
	input [31:0] WD,
	input [31:0] PC,
	input [5:0] itr,
	input [4:0] M_rd,
	input [4:0] excode,
	input db,
	input clk,
	input reset,
	input eret,
	input CP0_wr,
	output req,
	output reg itr_out,
	output [31:0] EPC,
	output [31:0] CP0_OUT
);
	
	reg [31:0] sr, cause, epc, prid;
	wire [31:0] temp_epc;
	
	wire req_itr	= (((itr&`itr_mask)!=0) && `itr_en && (!`in_req));
	//wire req_exc	= (excode!=0) && (!`in_req);
	wire req_exc	= (excode!=0)&&(!req_itr);
	
	assign req = (req_exc||req_itr);
	always @(posedge clk) begin
		itr_out <= req_itr&&(itr[2] & sr[12]);
	end
	
	/*always @(*) begin
		cause[15:10] = itr;
	end*/
	
	always @(posedge clk or posedge reset) begin
		if(reset) begin
			sr		<= 0;
			cause <= 0;
			epc	<= 0;
			prid	<= 32'h1937_3189;
		end
		else begin
			cause[15:10] <= itr;
			if(eret) `in_req <= 0;
			
			if(req) begin
				`in_req <= 1;
				cause[6:2] <= (req_itr)?0: excode; 
				cause[31] <= db;
				epc <= temp_epc;
			end
			else if(CP0_wr) begin
				if(M_rd==12) sr <= WD;
				else if(M_rd==14) epc <= WD;
			end
		end
	end
	
	assign temp_epc = (req)? (db? PC-4: PC): epc;
	assign EPC = {temp_epc[31:2], 2'b0};
	assign CP0_OUT = (M_rd==12)? sr:
						  (M_rd==13)? cause: 
						  (M_rd==14)? temp_epc: //or temp_epc??
						  (M_rd==15)? prid: 0;

endmodule
