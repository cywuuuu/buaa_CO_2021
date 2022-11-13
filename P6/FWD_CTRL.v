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
	 //暴力转发（并非需求来了再转发， 但是兼顾写使能、写入0寄存器的转发）的依据
	 //stall帮我们排出了无法转发的
	 //其余都是可以转发的
	 //转发的时间点并不重要， 只要在需求方的需求阶段来临之前转发好即可
	 //暴力转发在于，需求指令一进流水线， 就开始检测转发， 一旦可以提前转发，都会转发， 甚至是在需求时刻来临前的多次重复转发
	 //在需求时刻来临前的重复转发并没有必要，但是并不影响结果，也可以简化转发逻辑所以这么干！
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
