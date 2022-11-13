`timescale 1ns / 1ps
`include "const.v"
`default_nettype wire

module mips(
	input clk,
	input reset,
	input interrupt,
   input [31:0] i_inst_rdata,
   input [31:0] m_data_rdata,
	output [31:0] macroscopic_pc,
   output [31:0] i_inst_addr,
   output [31:0] m_data_addr,
   output [31:0] m_data_wdata,
   output [3 :0] m_data_byteen,
   output [31:0] m_inst_addr,
   output w_grf_we,
   output [4:0] w_grf_addr,
   output [31:0] w_grf_wdata,
   output [31:0] w_inst_addr
);

	assign macroscopic_pc = m_inst_addr;
	wire [31:0] T0_OUT, T1_OUT, mips_RD;
	wire [5:0] itr;
	wire T0_itr, T1_itr;
		
	CPU cpu (
    .clk(clk), 
    .reset(reset), 
	 .itr(itr),
    .i_inst_rdata(i_inst_rdata), 
    .m_data_rdata(mips_RD), 
    .i_inst_addr(i_inst_addr), 
    .m_data_addr(m_data_addr), 
    .m_data_wdata(m_data_wdata), 
    .m_data_byteen(m_data_byteen), 
    .m_inst_addr(m_inst_addr), 
    .w_grf_we(w_grf_we), 
    .w_grf_addr(w_grf_addr), 
    .w_grf_wdata(w_grf_wdata), 
    .w_inst_addr(w_inst_addr)
   );
	
	wire T0_en = (m_data_addr>=`ADDR_T0s&&m_data_addr<=`ADDR_T0t);
	wire T1_en = (m_data_addr>=`ADDR_T1s&&m_data_addr<=`ADDR_T1t);
	wire T_wr = (|m_data_byteen);
	wire T0_wr = T0_en&T_wr;
	wire T1_wr = T1_en&T_wr;
	
	assign mips_RD = (T0_en)? T0_OUT:
						  (T1_en)? T1_OUT: m_data_rdata;
	assign itr		= {3'b0, interrupt, T1_itr, T0_itr};
	
	TC T0 (
    .clk(clk), 
    .reset(reset), 
    .Addr(m_data_addr), 
    .PC(m_inst_addr), 
    .WE(T0_wr), 
    .Din(m_data_wdata), 
    .Dout(T0_OUT), 
    .IRQ(T0_itr)
   );
	
	TC T1 (
    .clk(clk), 
    .reset(reset), 
    .Addr(m_data_addr), 
    .PC(m_inst_addr), 
    .WE(T1_wr), 
    .Din(m_data_wdata), 
    .Dout(T1_OUT), 
    .IRQ(T1_itr)
   );
	
endmodule