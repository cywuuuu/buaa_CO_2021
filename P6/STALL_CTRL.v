`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    08:07:02 11/19/2021 
// Design Name: 
// Module Name:    STALL_CTRL 
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
module STALL_CTRL(
		input D_tuse_rs_1,
		input D_tuse_rs_0,
		input D_tuse_rt_2, 
		input D_tuse_rt_1,
		input D_tuse_rt_0,
		//input [1:0]D_new_at,
		input E_real_busy, 
		input [4:0]D_MDU_op,
		input [2:0]E_new_at,
		input [2:0]M_new_at,
		//input [1:0]W_new_at,
		input [4:0] D_A1, 
		input [4:0] D_A2, 
		input [4:0] D_A3, 
		//input [4:0] E_A1, 
		//input [4:0] E_A2, 
		input [4:0] E_A3, 
		//input [4:0] M_A1, 
		//input [4:0] M_A2, 
		input [4:0] M_A3, 
		//input [4:0] W_A1, 
		//input [4:0] W_A2, 
		input [4:0] W_A3, 
		output stall
    );
	 //��ָ��ʱֻ���޸�newat
	 //վ��D���ӽ�˼��, Dtuse < E/M/W'stnew ��DҪ�ڲ������֮ǰ�õ�������ôstall, 
	 wire stall_rs_tuse0_e, stall_rs_tuse0_m , stall_rt_tuse0_e, stall_rt_tuse0_m, stall_rs_tuse1_e, stall_rt_tuse1_e;
	 assign stall_rs_tuse0_e = (D_tuse_rs_0) && (E_new_at == `new_at_CAL || E_new_at == `new_at_DM) && (D_A1 == E_A3) && D_A1;	 
	 //stall_rs_tuse0_e ��D��Ҫrightnow������E����ָ�����������ALU\DM�Ķ�̫����,
	 //������ڻ�û�ѽ���浽��һ���Ĵ����أ���զת��
	 assign stall_rs_tuse0_m = (D_tuse_rs_0) && (M_new_at == `new_at_DM) && (D_A1 == M_A3) && D_A1;
	 
	 assign stall_rt_tuse0_e = (D_tuse_rt_0) && (E_new_at == `new_at_CAL || E_new_at == `new_at_DM) && (D_A2 == E_A3) && D_A2;
	 assign stall_rt_tuse0_m = (D_tuse_rs_0) && (M_new_at == `new_at_DM) && (D_A2 == M_A3) && D_A2;
	 
	 //***
	 
	 assign stall_rs_tuse1_e = (D_tuse_rs_1) && (E_new_at == `new_at_DM) && (D_A1 == E_A3) && D_A1; //����ǲ�дtnew�Ļ���,�����ظ����˽�����
 	 
	 assign stall_rt_tuse1_e = (D_tuse_rt_1) && (E_new_at == `new_at_DM) && (D_A2 == E_A3) && D_A2;//E��lw tnew = 2�̣� M��tnew = 1�� 
	 
	 //***
	 
	  //stall_rt_tuse2_m = 0;tuse�����������
	 assign stall = stall_rs_tuse0_e || stall_rs_tuse0_m || stall_rt_tuse0_e || stall_rt_tuse0_m || stall_rs_tuse1_e || stall_rt_tuse1_e || (D_MDU_op != 0 && E_real_busy);
	//(E_new_at == `new_at_DM) == (tnew = 2)
	// M_new_at == `new_at_DM  == (tnew = 1)
	// E_new_at == `new_at_ALU == (tnew = 1)
	//...
endmodule
