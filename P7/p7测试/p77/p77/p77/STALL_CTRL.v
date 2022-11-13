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
		input lrm_in_pip, 
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
		input D_iseret,
		input E_ismtc0, 
		input M_ismtc0,
		input [31:0]E_mtc0_dst, 
		input [31:0]M_mtc0_dst,
		output stall
    );
	 //改指令时只用修改newat
	 //站在D的视角思考, Dtuse < E/M/W'stnew （D要在产生结果之前用到它）那么stall, 
	 wire stall_rs_tuse0_e, stall_rs_tuse0_m , stall_rt_tuse0_e, stall_rt_tuse0_m, stall_rs_tuse1_e, stall_rt_tuse1_e;
	 
	 assign stall_rs_tuse0_e = (D_tuse_rs_0) && (E_new_at == `new_at_CAL || E_new_at == `new_at_DM) && 
										(lrm_in_pip ? (D_A1):(D_A1 == E_A3)) && D_A1;	 
	 
	 //stall_rs_tuse0_e 在D就要rightnow！所在E级的指令，其结果产生在ALU\DM的都太晚啦,
	 //这个周期还没把结果存到下一级寄存器呢，我咋转发
	 assign stall_rs_tuse0_m = (D_tuse_rs_0) && (M_new_at == `new_at_DM) && 
										(lrm_in_pip ? (D_A1):(D_A1 == M_A3)) && D_A1;
	 
	 assign stall_rt_tuse0_e = (D_tuse_rt_0) && (E_new_at == `new_at_CAL || E_new_at == `new_at_DM) && 
										(lrm_in_pip ? (D_A2):(D_A2 == E_A3)) && D_A2;
	 assign stall_rt_tuse0_m = (D_tuse_rs_0) && (M_new_at == `new_at_DM) && 
										(lrm_in_pip ? (D_A2):(D_A2 == M_A3)) && D_A2;
	 
	 //***
	 
	 assign stall_rs_tuse1_e = (D_tuse_rs_1) && (E_new_at == `new_at_DM) && 
										(lrm_in_pip ? (D_A1):(D_A1 == E_A3)) && D_A1; 
 	 
	 assign stall_rt_tuse1_e = (D_tuse_rt_1) && (E_new_at == `new_at_DM) && 
										(lrm_in_pip ? (D_A2):(D_A2 == E_A3)) && D_A2;//E的lw tnew = 2√， M的tnew = 1× 
	 
	 //***
	 wire stall_eret = D_iseret && ((E_ismtc0 && (E_mtc0_dst == 14))||(M_ismtc0 && (M_mtc0_dst == 14)));  
	  //stall_rt_tuse2_m = 0;tuse最大了想怎样
	 assign stall = stall_eret || stall_rs_tuse0_e || stall_rs_tuse0_m || stall_rt_tuse0_e || stall_rt_tuse0_m || stall_rs_tuse1_e || stall_rt_tuse1_e || (D_MDU_op != 0 && E_real_busy);
	//注意这里，因为前面MDU_op为所以的md指令分配了非0 op, 所以这么写可以， stall控制在处理md指令时也不用加什么,
	 //前面无论什么分配好非0 op就好
	 //同时md指令在stall结束前被冻在了d
	//(E_new_at == `new_at_DM) == (tnew = 2)
	// M_new_at == `new_at_DM  == (tnew = 1)
	// E_new_at == `new_at_ALU == (tnew = 1)
	//...
	
	/*
		// lwso 
	 如果Tnew <= Tuse 则不用暂停 TNEWE 可以是2,1,0, 符合正常的都不用考虑暂停。
	 lwso和lw的tnew,tuse基本一致
	 到了机会W级lwso有了A3自然会转发；
	 如果lwso 结果产生太慢了， 但如果D级指令不读寄存器产生结果的reg也可以
	 如果lwso 结果产生太慢，且如果D偏偏要读虽然我还不知道要读啥呢，那么请你先暂停，等到tnew足够小
	 对比lw ,我们判断的条件可能就是等于了，相当于这里A1等于一切可能值都暂停
	 wire stall_rs_e = (TuseRS < TnewE) && D_rs_addr && (D_lwso ? D_rs_addr == 5'd31 : A1 D_rs_addr == E_RFDstA3);
	 // lrm
	 wire stall_rs_e = (TuseRS < TnewE) && D_rs_addr && (D_lrm ? D_rs_addr : D_rs_addr == E_RFDst);
	在 CU 中的写法则与条件跳转类似。
	*/
endmodule
