`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    23:09:20 11/02/2021 
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
module CPU(
	input clk,
	input reset,
	 input [31:0] i_inst_rdata,
    input [31:0] m_data_rdata,
    output [31:0] i_inst_addr,
    output [31:0] m_data_addr,
    output [31:0] m_data_wdata,
    output [3 :0] m_data_byteen,
    output w_grf_we,
    output [4:0] w_grf_addr,
    output [31:0] w_grf_wdata,
    output [31:0] w_inst_addr, 
	 output [31:0] macroscopic_pc, 
	 output [31:0] m_inst_addr, 
	 input  [5:0] HW_int, 
	 output intt_req
    );
		wire [1:0]  D_RD1_fwd_ctrl, D_RD2_fwd_ctrl, E_RD1_fwd_ctrl, E_RD2_fwd_ctrl, M_RD2_fwd_ctrl;
		wire [31:0] E_fwd_src, M_fwd_src, W_fwd_src;
		wire [2:0] E_fwd_src_sel, M_fwd_src_sel, W_fwd_src_sel;
		
		wire [4:0] D_A1, D_A2, D_A3; 
		wire [4:0] E_A1, E_A2, E_A3; 
		wire [4:0] M_A1, M_A2, M_A3; 
		wire [4:0] W_A1, W_A2, W_A3;
		wire E_lrm, M_lrm, W_lrm;wire lrm_in_pip = E_lrm ;// | M_lrm| W_lrm   dm sp
		
		wire D_reg_write, E_reg_write, M_reg_write, W_reg_write;
		wire D_tuse_rs_1, D_tuse_rs_0, D_tuse_rt_2, D_tuse_rt_1, D_tuse_rt_0;
		wire [2:0]D_new_at, E_new_at, M_new_at, W_new_at;
		
		wire [31:0] F_PC, F_instr, D_PC, D_instr, E_PC, E_instr, M_PC, M_instr, W_PC, W_instr;
		wire [32*8-1:0]F_asm, D_asm, E_asm, M_asm, W_asm;
		/////////////// stall 执行  ///////////////	
		wire D_en = ~stall;		wire E_en = 1;
		wire M_en = 1;				wire W_en = 1;
		wire D_reset = reset;	wire E_reset = reset;
		wire M_reset = reset;	wire W_reset = reset;

		////////////////////////////////////Dsignal/////////////////////////////////////////////////		
		wire [2:0] D_NPCop;		wire [4:0] D_MDU_op;
		wire [1:0] D_cmp, D_zero;
		wire [31:0] D_NPC, D_grf_RD1, D_grf_RD2, D_ext_imm32;
		wire D_sign;	wire D_null_slot;
		wire [31:0] D_RD1_fwd_mux, D_RD2_fwd_mux;									 
		/////////////////////////////////////Esignal///////////////////////////////////////////////									 
		wire [31:0] E_RD1, E_RD2, E_ext_imm32;
		wire [1:0]  E_ALU_src;	wire [4:0]  E_ALU_op, E_MDU_op;
		wire E_CAL_sel, E_start, E_real_busy;
		wire [31:0] E_CAL_res, E_ALU_B_mux, E_ALU_res, E_MDU_out;
		wire [31:0] E_RD1_fwd_mux, E_RD2_fwd_mux;		
		/////////////////////////////////////Msignal///////////////////////////////////////////////
		wire [31:0] M_CAL_res, M_RD2;
		wire M_mem_write;			wire [1:0] M_LS_op;
		wire [31:0] M_DM_RD;		wire [31:0] M_RD2_fwd_mux;																							
		/////////////////////////////////////Wsignal////////////////////////////////////////////////																					
		wire [31:0] W_CAL_res, W_DM_RD;
		wire [2:0] W_reg_dst, W_which_to_reg;	
		wire [4:0] W_grf_A3_mux;
		wire [31:0] W_grf_WD3_mux;

	//////////////////////////////////////////////////////////////
	//*********************Fstage********************************
	//////////////////////////////////////////////////////////////
	//PC
	/*
	    input clk,
    input [31:0] NPC,
	 input [31:0] EPC,
	 input D_iseret,
	 output exc_AdEL, 
    output reg [31:0] PC,
    input reset,
	 input en
	*/
	wire [31:0] M_EPC_RD; 
	wire D_iseret; 
	wire F_exc_AdEL;
	PC i_fpc		(.clk(clk), .reset(reset), .NPC(D_NPC), .EPC(M_EPC_RD), 
					 .D_iseret(D_iseret), .exc_AdEL(F_exc_AdEL), 
				    .PC(F_PC), .en((!stall)|M_int_exc_req));
	//IM			
	//IM i_fim		(.PC(F_PC), .clk(clk), 
	//             .instr(F_instr));
	assign i_inst_addr = F_PC;
	wire [4:0] F_exc_code = (F_exc_AdEL) ? `AdEL : `nothing;
	assign F_instr = i_inst_rdata;
	wire F_DB = (D_has_DB) ? 1 : 0 ;
	//如果取指错误， F_instr = 0; 
	//////////////////////////////////////////////////////////////
	//*********************Dstage********************************
	//////////////////////////////////////////////////////////////
	wire D_DB, D_has_DB; 
	wire D_exc_RI; 
	wire [4:0] D_exc_code_tmp, D_exc_code; 

	//DREG				
	SPDREG i_dreg (.instr(F_instr), .PC(F_PC), 	.DB(F_DB),  .exc_code(F_exc_code), 
						.D_null_slot(D_null_slot), .D_DB(D_DB), .D_exc_code(D_exc_code_tmp),
						.D_PC(D_PC), 	.D_instr(D_instr),
						.en(D_en), 		.reset(D_reset), 	.clk(clk), .int_exc_req(M_int_exc_req));
						  
	//NPC				
	NPC i_dnpc 	(	.F_PC(F_PC),	.D_PC(D_PC),	.imm26(D_instr[25:0]),	
						.jreg(D_RD1_fwd_mux),	.NPCop(D_NPCop),	.int_exc_req(M_int_exc_req),
						.NPC(D_NPC));

	//CTRL
	CTRL i_dctrl (	.instr(D_instr), .cmp(D_cmp), .zero(D_zero),			.stall(stall),  
						.Tuse_rs_0(D_tuse_rs_0), .Tuse_rs_1(D_tuse_rs_1), 	.MDU_op(D_MDU_op), 
						.Tuse_rt_0(D_tuse_rt_0), .Tuse_rt_1(D_tuse_rt_1), 	.Tuse_rt_2(D_tuse_rt_2),
						.A1(D_A1), 	.A2(D_A2), 	.A3(D_A3), .new_at(D_new_at), //forward & stall 信息输出
						.iseret(D_iseret), .exc_RI(D_exc_RI), .has_DB(D_has_DB), //
						.NPCop(D_NPCop), .sign(D_sign),.reg_write(D_reg_write),
						.null_slot(D_null_slot));//功能部件
	
	assign D_exc_code = (D_exc_code_tmp) ?  D_exc_code_tmp : 
								D_exc_RI ? `RI : `nothing ;
							  ;//RI 发生后实际作用和nop没啥区别吧应该？

	//****D转发点*******
	
	assign  D_RD1_fwd_mux =  (D_RD1_fwd_ctrl == `D_RD1_fwd_E) ? E_fwd_src :
									 (D_RD1_fwd_ctrl == `D_RD1_fwd_M) ? M_fwd_src ://上述为非0
									 //(D_RD1_Fwd_ctrl == `D_RD1_fwd_W) ? W_grf_WD3_mux : 
									 D_grf_RD1;//待补充
	assign  D_RD2_fwd_mux =  (D_RD2_fwd_ctrl == `D_RD2_fwd_E) ? E_fwd_src :
									 (D_RD2_fwd_ctrl == `D_RD2_fwd_M) ? M_fwd_src :
									 //(D_RD2_Fwd_ctrl == `D_RD2_fwd_W) ? W_grf_WD3_mux : 
									 D_grf_RD2;//待补充
	//GRF
	GRF i_dgrf 	(	.clk(clk), 	.WE(W_reg_write), 	.reset(reset), 
						.PC(W_PC), 	.A1(D_instr[25:21]), .A2(D_instr[20:16]), 
						.RD1(D_grf_RD1),  	.RD2(D_grf_RD2),
						.A3(W_grf_A3_mux), 	.WD3(W_grf_WD3_mux));
					 
	//EXT
	EXT i_dext (	.imm16(D_instr[15:0]), 	.sign(D_sign), 	.ext_imm32(D_ext_imm32));
	
	//CMP
	CMP i_dcmp (	.A(D_RD1_fwd_mux), 	.B(D_RD2_fwd_mux), 	.cmp(D_cmp), 	.zero(D_zero));
	
	//////////////////////////////////////////////////////////////
	//*********************Estage********************************
	//////////////////////////////////////////////////////////////
	wire E_DB,  E_ismtc0; 
	wire [4:0] E_exc_code, E_exc_code_tmp;
	wire [1:0] E_zero, E_cmp;
	wire E_overflow;
	wire E_exc_Ov; 
	//EREG				//input
	SPEREG i_ereg (	.instr(D_instr), 				.PC(D_PC), 		.RD1(D_RD1_fwd_mux), .RD2(D_RD2_fwd_mux),
							.ext_imm32(D_ext_imm32), 	.cmp(D_cmp), 	.zero(D_zero), 
							.DB(D_DB),	.exc_code(D_exc_code), 	.stall(stall),//
							//output
							.E_RD1(E_RD1), 	.E_RD2(E_RD2), 		.E_ext_imm32(E_ext_imm32),
							.E_PC(E_PC), 		.E_instr(E_instr), 	.E_cmp(E_cmp), 	
							.E_DB(E_DB),	.E_exc_code(E_exc_code_tmp), //
							.E_zero(E_zero),  .E_fwd_src(E_fwd_src),
							//control
							.int_exc_req(M_int_exc_req),
							.reset(E_reset), 	.en(E_en),	.clk(clk), .E_fwd_src_sel(E_fwd_src_sel));

	//CTRL			//ordinary
	CTRL i_ectrl (	.instr(E_instr), 	.ALU_src(E_ALU_src),		.ALU_op(E_ALU_op),	.MDU_op(E_MDU_op),	.start(E_start),
						.reg_write(E_reg_write),	.cmp(E_cmp), 	.zero(E_zero), 		.CAL_sel(E_CAL_sel),
						//hazard
						.A1(E_A1), 	.A2(E_A2), 		.A3(E_A3), 		.new_at(E_new_at), 	.fwd_src_sel(E_fwd_src_sel),
						.islrm(E_lrm), 	.ismtc0(E_ismtc0), //
						.overflow(E_overflow), .exc_Ov(E_exc_Ov)//
						);
	

	//****E转发点*******
	assign  E_RD1_fwd_mux = (E_RD1_fwd_ctrl == `E_RD1_fwd_M) ? M_fwd_src :
									(E_RD1_fwd_ctrl == `E_RD1_fwd_W) ? W_fwd_src :
									 E_RD1;		
	assign  E_RD2_fwd_mux = (E_RD2_fwd_ctrl == `E_RD2_fwd_M) ? M_fwd_src :
									(E_RD2_fwd_ctrl == `E_RD2_fwd_W) ? W_fwd_src :
									 E_RD2;//待补充

	assign  E_ALU_B_mux = 	(E_ALU_src == `sel_RD2) 	? 	E_RD2_fwd_mux:
									(E_ALU_src == `sel_imm32) 	? 	E_ext_imm32:
									32'h233333;
	//ALU									
	ALU i_ealu   (	.ctrl(E_ALU_op),  .overflow(E_overflow), 
						.A(E_RD1_fwd_mux),.B(E_ALU_B_mux), 	.result(E_ALU_res), 	.shamt(E_instr[10:6]));

	MDU i_mdu	(	.start(E_start), 	.D1(E_RD1_fwd_mux), 	.D2(E_ALU_B_mux), .MDU_op(E_MDU_op),
						.clk(clk),	.reset(reset),	.real_busy(E_real_busy),	.MDU_out(E_MDU_out));
						
	assign E_CAL_res = (E_CAL_sel == `sel_MDU) ? E_MDU_out : E_ALU_res; 
	assign E_exc_code = (E_exc_code_tmp) ? E_exc_code_tmp :
								(E_exc_Ov ? `Ov : `nothing) ; 
							  
	//////////////////////////////////////////////////////////////
	//*********************Mstage********************************
	//////////////////////////////////////////////////////////////
	wire [1:0] M_zero, M_cmp;
	wire M_DB, M_ismtc0, M_overflow; 
	wire [4:0] M_exc_code_tmp, M_exc_code;
	wire M_CP0_WE; 
	//MREG			//input
	SPMREG i_mreg(	.instr(E_instr),	.PC(E_PC),	.RD2(E_RD2_fwd_mux),	.CAL_res(E_CAL_res), .overflow(E_overflow), 
						.cmp(E_cmp),		.zero(E_zero),		.M_fwd_src(M_fwd_src),
						.DB(E_DB), 	.exc_code(E_exc_code), 	
						//output
						.M_DB(M_DB), 	.M_exc_code(M_exc_code_tmp), 
						.M_CAL_res(M_CAL_res),	.M_RD2(M_RD2),	.M_PC(M_PC),
						.M_instr(M_instr),		.M_cmp(M_cmp),	.M_zero(M_zero), .M_overflow(M_overflow), 
						//control
						.int_exc_req(M_int_exc_req),
						.en(M_en),	.reset(M_reset),	.clk(clk),	.M_fwd_src_sel(M_fwd_src_sel));
	wire M_DM_sign;	
	//CTRL
	CTRL i_mctrl (	.instr(M_instr),	.mem_write(M_mem_write),	
						.reg_write(M_reg_write), 	.CP0_WE(M_CP0_WE),
						.overflow(M_overflow), //overflow
						.m_data_addr(m_data_addr), //dm_addr
						.exc_AdEL(M_exc_AdEL), .exc_AdES(M_exc_AdES), //if exc?
						.cmp(M_cmp),		.zero(M_zero), .LS_op(M_LS_op),		.DM_sign(M_DM_sign),
						.A1(M_A1), .A2(M_A2), .A3(M_A3), .new_at(M_new_at), 	.fwd_src_sel(M_fwd_src_sel),
						.islrm(M_lrm), .ismtc0(M_ismtc0), .iseret(M_iseret));

	
	
	//当外部中断来临防止写入， 内部异常的话不写
	//防止中断	int_exc_req ? 0 : M_mem_write												M_RD2;
	
	wire M_byteen_WE = M_int_exc_req ? 0 : M_mem_write; 
	assign m_data_addr = M_CAL_res;
	BYTEEN i_byteen (.A(m_data_addr), 	.WE(M_byteen_WE),	.LS_op(M_LS_op), 
						  .byte_en(m_data_byteen));
	

	
	assign M_exc_code = (M_exc_code_tmp) ?  M_exc_code_tmp :
							  (M_exc_AdEL ? `AdEL : 
							  (M_exc_AdES ? `AdES : 
							  `nothing)) ;
	
	assign m_data_wdata = (M_LS_op == `LS_h) ? (M_RD2_fwd_mux << (M_CAL_res[1] * 16)) :
								 (M_LS_op == `LS_b) ? (M_RD2_fwd_mux << (M_CAL_res[1:0] * 8)):
								 M_RD2_fwd_mux;

	assign m_inst_addr = M_PC;
	assign macroscopic_pc = M_PC;

	DATA_EXT i_dataext (.A(M_CAL_res), .LS_op(M_LS_op), .RDin(m_data_rdata), .DM_sign(M_DM_sign), 
							  .RDout(M_DM_RD));
	wire [31:0]EPC; 
	wire M_int_exc_req; 

	wire M_iseret; 
	wire [31:0]M_CP0_RD;//连到哪里？想想 mfc0, 把cp0RD写入寄存器 
	wire [5:0]M_HW_int = HW_int; 
	wire M_req, M_BD;
	
	CP0 i_mcp0( .A(M_instr[15:11]), .WD(M_RD2_fwd_mux), .WE(M_CP0_WE), .RD(M_CP0_RD), 
					.exc_code(M_exc_code), .HW_int(M_HW_int), .PC(M_PC), .BD(M_DB), .intt_req(intt_req), 
					.EXL_clr(M_iseret), .EPC_RD(M_EPC_RD), .int_exc_req(M_int_exc_req), .clk(clk), .reset(reset));

	//****M转发点*******			 
	assign M_RD2_fwd_mux = (M_RD2_fwd_ctrl == `M_RD2_fwd_W) ? W_fwd_src : M_RD2; //check???转发最终结果， 别只转发DM_RD啊
	
	
	//////////////////////////////////////////////////////////////
	//*********************Wstage********************************
	//////////////////////////////////////////////////////////////
	wire [1:0] W_zero, W_cmp;
	wire [31:0] W_RD2, W_CP0_RD;
	//WREG
	SPWREG i_wreg (  .clk(clk),	.en(W_en),	.reset(W_reset),	.int_exc_req(M_int_exc_req), 
						  .cmp(M_cmp),	.RD2(M_RD2), .CP0_RD(M_CP0_RD),
						  .instr(M_instr),	.PC(M_PC),		.CAL_res(M_CAL_res),	.DM_RD(M_DM_RD),	 
						  .zero(M_zero),		.W_PC(W_PC),	.W_instr(W_instr),	.W_CAL_res(W_CAL_res), 
						  .W_DM_RD(W_DM_RD),	.W_cmp(W_cmp),	.W_zero(W_zero),		.W_RD2(W_RD2), 
						  .W_CP0_RD(W_CP0_RD),
						  .W_fwd_src(W_fwd_src),	.W_fwd_src_sel(W_fwd_src_sel));
	
	//CTRL
	CTRL i_wctrl    (	.instr(W_instr),	.reg_write(W_reg_write),	.reg_dst(W_reg_dst), .DM_RD(M_DM_RD[4:0]), 
							.which_to_reg(W_which_to_reg),	.cmp(W_cmp),		.zero(W_zero), 
							.A1(W_A1), .A2(W_A2), .A3(W_A3), .new_at(W_new_at),.fwd_src_sel(W_fwd_src_sel),
							.islrm(W_lrm));//转发的时候不用判断we，因为呢，如果不写入，我们使其A3=0,写入0，这样会被我们的A3!=0滤掉，不会转发啦

	assign w_grf_we = W_reg_write;
	assign w_grf_addr = W_grf_A3_mux;
	assign w_grf_wdata = W_grf_WD3_mux;
	assign w_inst_addr = W_PC;
	wire [31:0]W_rs = W_instr[25:21];
	wire [31:0]W_rt = W_instr[20:16];
	wire [31:0]W_rd = W_instr[15:11];
	assign W_grf_A3_mux = (W_reg_dst == `sel_rd) ? W_instr[15:11] : 
								 (W_reg_dst == `sel_rt) ? W_instr[20:16] :
								 (W_reg_dst == `sel_DM_RD) ? M_DM_RD[4:0]: 
								 (W_reg_dst == `sel_31) ? 31 : 
								 23;// default 23
	assign W_grf_WD3_mux = (W_which_to_reg == `sel_PC4) ?  (W_PC+8) :
								  (W_which_to_reg == `sel_res) ?  W_CAL_res : 
								  (W_which_to_reg == `sel_dm)  ?  W_DM_RD :
								  (W_which_to_reg == `sel_CP0) ? W_CP0_RD : 
								  (W_which_to_reg == `sel_grfrt) ? W_RD2 :
								 233333;
	////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//FWD_CTRL
	FWD_CTRL i_fwdctrl (.D_A1(D_A1), .D_A2(D_A2), .D_A3(D_A3), .E_A1(E_A1), .E_A2(E_A2), .E_A3(E_A3),
							  .M_A1(M_A1), .M_A2(M_A2), .M_A3(M_A3), .W_A1(W_A1), .W_A2(W_A2), .W_A3(W_A3), 
							  .D_RD1_fwd_ctrl(D_RD1_fwd_ctrl), .D_RD2_fwd_ctrl(D_RD2_fwd_ctrl), .E_RD1_fwd_ctrl(E_RD1_fwd_ctrl),
							  .E_RD2_fwd_ctrl(E_RD2_fwd_ctrl), .M_RD2_fwd_ctrl(M_RD2_fwd_ctrl));
	//STALL_CTRL
	/*
			input D_iseret,
		input E_ismtc0, 
		input M_ismtc0,
	*/
	STALL_CTRL i_stallctrl(.D_tuse_rs_1(D_tuse_rs_1), .D_tuse_rs_0(D_tuse_rs_0), .D_tuse_rt_2(D_tuse_rt_2),
								  .D_tuse_rt_1(D_tuse_rt_1), .D_tuse_rt_0(D_tuse_rt_0), .D_MDU_op(D_MDU_op),
								  .E_new_at(E_new_at), .M_new_at(M_new_at),	.E_real_busy(E_real_busy), 
								  .D_iseret(D_iseret), .E_ismtc0(E_ismtc0),  .M_ismtc0(M_ismtc0), //
								  .D_A1(D_A1), .D_A2(D_A2), .D_A3(D_A3), .lrm_in_pip(lrm_in_pip),
								  
								  .E_A3(E_A3), .M_A3(M_A3), .W_A3(W_A3), .stall(stall));




endmodule
