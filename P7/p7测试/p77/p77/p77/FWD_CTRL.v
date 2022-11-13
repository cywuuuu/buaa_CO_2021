`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    07:42:39 11/19/2021 
// Design Name: 
// Module Name:    FWD_CTRL 
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
module FWD_CTRL(
		output [1:0]  D_RD1_fwd_ctrl,
		output [1:0]  D_RD2_fwd_ctrl,
		output [1:0]  E_RD1_fwd_ctrl,
		output [1:0]  E_RD2_fwd_ctrl,
		output [1:0]  M_RD2_fwd_ctrl,
		input [4:0] D_A1, 
		input [4:0] D_A2, 
		input [4:0] D_A3, 
		input [4:0] E_A1, 
		input [4:0] E_A2, 
		input [4:0] E_A3, 
		input [4:0] M_A1, 
		input [4:0] M_A2, 
		input [4:0] M_A3, 
		input [4:0] W_A1, 
		input [4:0] W_A2, 
		input [4:0] W_A3
    );
	 //����ת������������������ת���� ���Ǽ��дʹ�ܡ�д��0�Ĵ�����ת����������
	 //stall�������ų����޷�ת����
	 //���඼�ǿ���ת����
	 //ת����ʱ��㲢����Ҫ�� ֻҪ�����󷽵�����׶�����֮ǰת���ü���
	 //����ת�����ڣ�����ָ��һ����ˮ�ߣ� �Ϳ�ʼ���ת���� һ��������ǰת��������ת���� ������������ʱ������ǰ�Ķ���ظ�ת��
	 //������ʱ������ǰ���ظ�ת����û�б�Ҫ�����ǲ���Ӱ������Ҳ���Լ�ת���߼�������ô�ɣ�
	assign D_RD1_fwd_ctrl = (D_A1 === 0) ? 0 :
									(D_A1 === E_A3) ? `D_RD1_fwd_E : 
									(D_A1 === M_A3) ? `D_RD1_fwd_M :
									0;
	
	assign D_RD2_fwd_ctrl = (D_A2 === 0) ? 0 : 
									(D_A2 === E_A3) ? `D_RD2_fwd_E : 
									(D_A2 === M_A3) ? `D_RD2_fwd_M :
									0;
									
	assign E_RD1_fwd_ctrl = (E_A1 === 0) ? 0 :
									(E_A1 === M_A3) ? `E_RD1_fwd_M : 
									(E_A1 === W_A3) ? `E_RD1_fwd_W :
									0;
	assign E_RD2_fwd_ctrl = (E_A2 === 0) ? 0 :
									(E_A2 === M_A3) ? `E_RD2_fwd_M : 
									(E_A2 === W_A3) ? `E_RD2_fwd_W :
									0;	
	assign M_RD2_fwd_ctrl = (M_A2 === 0) ? 0 :
									(M_A2 === W_A3) ? `M_RD2_fwd_W :
									0;	
endmodule
