`timescale 1ns / 1ps
`include "const.v"
`default_nettype wire

module DM(
	input [31:0] A,
	input [31:0] WD,
	input [31:0] PC,
	input [31:0] Instr,
	input [31:0] m_data_rdata,
	input [5:0] itr,
	input [4:0] excode,
	input [2:0] DM_op,
	input clk,
	input req,
	input reset,
	input DM_wr,
	input adel_en,
	input ades_en,
	input itr_out,
	output adel,
	output ades,
	output reg [31:0] DMout,
	output reg [3:0] m_data_byteen,
	output reg [31:0] m_data_addr,
	output reg [31:0] m_data_wdata,
	output reg [31:0] m_inst_addr
	);
	
	function [31:0] unsigned_b;
		input [7:0] in;
		begin
			unsigned_b = {{24{1'b0}}, in};
		end
	endfunction
	
	function [31:0] unsigned_h;
		input [15:0] in;
		begin
			unsigned_h = {{16{1'b0}}, in};
		end
	endfunction
	
	function [31:0] signed_b;
		input [7:0] in;
		begin
			signed_b = {{24{in[7]}}, in};
		end
	endfunction
	
	function [31:0] signed_h;
		input [15:0] in;
		begin
			signed_h = {{16{in[15]}}, in};
		end
	endfunction
	
	wire [11:0] addr = A[13:2];
	reg [31:0] mem [4095:0];
	integer i, fp;
		
	initial begin
		for(i=0; i<4095; i=i+1) mem[i] <= 0;
	end
	
	//***************************************************************temp_byteen
	always @(*) begin
		m_data_byteen = 0;
		m_inst_addr = PC;
		if(itr_out) begin
			m_data_addr = 32'h7f20;
			m_data_byteen = 4'b1111;
			m_data_wdata = 0;
		end
		else if(DM_wr&&(!ades)&&(!req)) begin
			m_data_addr = A;
			case(DM_op)
				`DM_w: begin
					m_data_byteen = 4'b1111;
					m_data_wdata = WD;
				end
				`DM_h: begin
					m_data_byteen[A[1:0]+1 -:2] = 2'b11;
					m_data_wdata[15+16*A[1] -:16] = WD[15:0];
				end
				`DM_b: begin
					m_data_byteen[A[1:0]] = 1'b1;
					m_data_wdata[7+8*A[1:0] -:8] = WD[7:0];
				end
				default: begin
					m_data_byteen = 0;
					m_data_wdata = 0;
				end
			endcase
		end
		else begin
			m_data_addr = A;
		end
	end
	
	//***************************************************************DM
	always @(posedge clk or posedge reset) begin
		if(reset) begin
			for(i=0; i<4095; i=i+1) mem[i] <= 0;
		end
		else if(DM_wr&&(A>=`ADDR_DMs&&A<=`ADDR_DMt)&&(!ades)&&(!req)) begin
			case(DM_op)
				`DM_w: begin
					mem[addr] <= WD;
					//$display("%h @%h: *%h <= %h", Instr, PC, A, WD);
				end
				`DM_h: begin
					mem[addr][15+16*A[1] -:16] <= WD[15:0];
					//$display("%h @%h: *%h <= %h", Instr, PC, A, {{16{1'b0}}, WD[15:0]});
				end
				`DM_b: begin
					mem[addr][7+8*A[1:0] -:8] <= WD[7:0];
					//$display("%h @%h: *%h <= %h", Instr, PC, A, {{24{1'b0}}, WD[7:0]});
				end
			endcase
		end
	end
	
	always @(*) begin
		if(A>=`ADDR_DMs&&A<=`ADDR_DMt) begin
			case(DM_op)
				`DM_w:	DMout <= mem[addr];
				`DM_h:	DMout <= signed_h(mem[addr][15+16*A[1] -:16]);
				`DM_hu:	DMout <= unsigned_h(mem[addr][15+16*A[1] -:16]);
				`DM_b:	DMout <= signed_b(mem[addr][7+8*A[1:0] -:8]);
				`DM_bu:	DMout <= unsigned_b(mem[addr][7+8*A[1:0] -:8]);
				default:	DMout <= 0;
			endcase
		end
		else DMout <= m_data_rdata;
	end
	
	//***************************************************************EXC_handler
	
	wire exc_align		= (DM_op==`DM_w && A[1:0]!=0)||
							  ((DM_op==`DM_h||DM_op==`DM_hu)&&A[0]);
	wire exc_timer_hb	= (A>=`ADDR_T0s && DM_op!=`DM_w);
	wire exc_timer_sc	= (A==32'h7f08 || A==32'h7f18);
	wire exc_range		= !((A>=`ADDR_DMs&&A<=`ADDR_DMt)||
							  (A>=`ADDR_T0s&&A<=`ADDR_T0t)||
							  (A>=`ADDR_T1s&&A<=`ADDR_T1t));
							  
	assign adel = adel_en&&(exc_align|exc_timer_hb|exc_range);
	assign ades = ades_en&&(exc_align|exc_timer_hb|exc_range|exc_timer_sc);
	
endmodule
