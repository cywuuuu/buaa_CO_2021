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
    input clk,                       // ʱ���ź�
    input reset,                     // ͬ����λ�ź�
    input interrupt,                 // �ⲿ�ж��ź�
    output [31:0] macroscopic_pc,    // ��� PC�������ģ�

    output [31:0] i_inst_addr,       // ȡָ PC
    input  [31:0] i_inst_rdata,      // i_inst_addr ��Ӧ�� 32 λָ��

    output [31:0] m_data_addr,       // ���ݴ洢����д���ַ
    input  [31:0] m_data_rdata,      // m_data_addr ��Ӧ�� 32 λ����
    output [31:0] m_data_wdata,      // ���ݴ洢����д������
    output [3 :0] m_data_byteen,     // �ֽ�ʹ���ź�

    output [31:0] m_inst_addr,       // M ��PC

    output w_grf_we,                 // grf дʹ���ź�
    output [4 :0] w_grf_addr,        // grf ��д��Ĵ������
    output [31:0] w_grf_wdata,       // grf ��д������

    output [31:0] w_inst_addr        // W �� PC
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
	.i_inst_rdata(i_inst_rdata), //��ȡim����
	.m_data_addr(m_data_addr_tmp), //ȡ��ַ
	.m_data_wdata(m_data_wdata),//д����
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
P7 ����� P6 �Ķ���ģ�������������ӿڣ�

macroscopic_pc[31:0]����� PC����Ӧ������� CP0 Э�������½ڡ����Ǳ�֤������������� macroscopic_pc[31:0] ������Ѱ�� CPU ���ܵ�"����"״̬���Դ�Ϊ���ݲ����ж��źš�

interrupt������ϵͳ����ж��źţ�ÿ���ж��źŻ�������������� 0x7F20 д��ֵΪֹ(���Բο����Ǹ����� tb ���)��������ж��źŵķ�ʽ�봦���ڲ� timer ģ����ж��ź���ΪӦ����һ�¡�
д 0x7F20 ����Ϊ�� CPU Ӳ����ɣ������������ɣ�����ָ�������г���д 0x7F20 ����ΪӦ������Ӧ���쳣��Ϊ����ͬѧ�Ǹ��õ���⣬�γ����ṩ��һ����Ӧ�ⲿ�жϵ�ʾ�����������ӡ�

Ϊ���ڽ��в��ԣ���������� 0x417C ֱ��ǰ���� 0x4180����������� CPU ��Ϊ�� P6 һ�£���Ӧ���ж���Ӧ��������Ϊ��
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
