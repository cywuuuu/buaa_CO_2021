`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    08:26:17 12/11/2021 
// Design Name: 
// Module Name:    mips 
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
module mips(
    input clk,                       // 时钟信号
    input reset,                     // 同步复位信号
    input interrupt,                 // 外部中断信号
    output [31:0] macroscopic_pc,    // 宏观 PC（见下文）

    output [31:0] i_inst_addr,       // 取指 PC
    input  [31:0] i_inst_rdata,      // i_inst_addr 对应的 32 位指令

    output [31:0] m_data_addr,       // 数据存储器待写入地址
    input  [31:0] m_data_rdata,      // m_data_addr 对应的 32 位数据
    output [31:0] m_data_wdata,      // 数据存储器待写入数据
    output [3 :0] m_data_byteen,     // 字节使能信号

    output [31:0] m_inst_addr,       // M 级PC

    output w_grf_we,                 // grf 写使能信号
    output [4 :0] w_grf_addr,        // grf 待写入寄存器编号
    output [31:0] w_grf_wdata,       // grf 待写入数据

    output [31:0] w_inst_addr        // W 级 PC
);

/*
	input clk,
	input reset,
	 input [31:0] i_inst_rdata,
    input [31:0] m_data_rdata,
    output [31:0] i_inst_addr,
    output [31:0] m_data_addr,
    output [31:0] m_data_wdata,
    output [3 :0] m_data_byteen,
    output [31:0] m_inst_addr,
    output w_grf_we,
    output [4:0] w_grf_addr,
    output [31:0] w_grf_wdata,
    output [31:0] w_inst_addr
*/
wire intt_req; 
wire [31:0]m_data_addr_tmp; 
wire [3:0]m_data_byteen_tmp;
reg inttt_req;
CPU i_cpu (
	.clk(clk),
	.reset(reset),
	.i_inst_addr(i_inst_addr),// im addr
	.i_inst_rdata(i_inst_rdata), //获取im数据
	.m_data_addr(m_data_addr_tmp), //取地址
	.m_data_wdata(m_data_wdata),//写数据
	.m_data_byteen(m_data_byteen_tmp),// 
	.m_data_rdata(m_data_rdata_cpu),//into cpu
	.w_grf_we(w_grf_we),
	.w_grf_addr(w_grf_addr),
	.w_grf_wdata(w_grf_wdata),
	.w_inst_addr(w_inst_addr), 
	.macroscopic_pc(macroscopic_pc), 
	.m_inst_addr(m_inst_addr), 
	.HW_int({3'b0, interrupt, IRQ1, IRQ0}), 
	.intt_req(intt_req)
); 

always @(posedge clk)begin
	inttt_req <= intt_req;
end
assign m_data_addr = inttt_req ?(32'h7F20) : m_data_addr_tmp;
assign m_data_byteen = inttt_req ?(4'b1111) : m_data_byteen_tmp;
/*
P7 相对于 P6 的顶层模块新增了两个接口：

macroscopic_pc[31:0]：宏观 PC，相应概念详见 CP0 协处理器章节。我们保证，在评测过程中 macroscopic_pc[31:0] 仅用于寻找 CPU 可能的"薄弱"状态并以此为依据产生中断信号。

interrupt：来自系统外的中断信号，每次中断信号会持续到处理器向 0x7F20 写入值为止(可以参考我们给出的 tb 理解)，处理该中断信号的方式与处理内部 timer 模拟的中断信号行为应保持一致。
写 0x7F20 的行为由 CPU 硬件完成，而非由软件完成，测试指令序列中出现写 0x7F20 的行为应触发相应的异常，为帮助同学们更好地理解，课程组提供了一个响应外部中断的示例：下载链接。

为便于进行测试，我们允许从 0x417C 直接前进到 0x4180，此种情况下 CPU 行为与 P6 一致，不应有中断响应等其他行为。
*/


wire PrWE = (m_data_byteen != 0);
wire [31:0]DEV_Addr; 
wire [31:0]DEV0_RD, DEV1_RD, DEV_WD; 
wire DEV0_WE, DEV1_WE, IRQ0, IRQ1;
wire [31:0]m_data_rdata_timer;
wire [31:0]m_data_rdata_cpu = 
((m_data_addr <= `dev0_addr_end && m_data_addr >= `dev0_addr_begin)||
(m_data_addr <= `dev1_addr_end && m_data_addr >= `dev1_addr_begin)) ?  m_data_rdata_timer : m_data_rdata; 
BRG i_bridge(
	.PrAddr(m_data_addr),
	.PrRD(m_data_rdata_timer),//out to cpu
	.PrWD(m_data_wdata), 
	.PrWE(PrWE),
	.DEV_Addr(DEV_Addr),
	.DEV0_RD(DEV0_RD),
	.DEV1_RD(DEV1_RD),
	.DEV0_WE(DEV0_WE),
	.DEV1_WE(DEV1_WE),
	.DEV_WD(DEV_WD)
);

TC tc0(
	.clk(clk),
	.reset(reset), 
	.Addr(DEV_Addr[31:2]),//[31:2] Addr,
	.WE(DEV0_WE),
	.Din(DEV_WD),
	.Dout(DEV0_RD),
	.IRQ(IRQ0)
);
TC tc1(
	.clk(clk),
	.reset(reset), 
	.Addr(DEV_Addr[31:2]),
	.WE(DEV1_WE),
	.Din(DEV_WD),
	.Dout(DEV1_RD),
	.IRQ(IRQ1)
);


endmodule
