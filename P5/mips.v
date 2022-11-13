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
module mips(
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
		wire PC_en = ~stall;
		wire D_en = ~stall;		wire E_en = 1;
		wire M_en = 1;				wire W_en = 1;
		wire D_reset = reset;	wire E_reset = (reset) ? 1 : stall;
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
	PC i_fpc		(.clk(clk), .reset(reset), .NPC(D_NPC), 
				    .PC(F_PC), .en(PC_en));
	//IM			
	//IM i_fim		(.PC(F_PC), .clk(clk), 
	//             .instr(F_instr));
	assign i_inst_addr = F_PC;
	assign F_instr = i_inst_rdata;
	
	//////////////////////////////////////////////////////////////
	//*********************Dstage********************************
	//////////////////////////////////////////////////////////////
	
	//DREG				
	SPDREG i_dreg (.instr(F_instr), 	.PC(F_PC), 		.D_null_slot(D_null_slot),
						.D_PC(D_PC), 	.D_instr(D_instr),
						.en(D_en), 		.reset(D_reset), 	.clk(clk));
						  
	//NPC				
	NPC i_dnpc 	(	.F_PC(F_PC),	.D_PC(D_PC),	.imm26(D_instr[25:0]),	.jreg(D_RD1_fwd_mux),	.NPCop(D_NPCop),
						.NPC(D_NPC));

	//CTRL
	CTRL i_dctrl (	.instr(D_instr), .cmp(D_cmp), .zero(D_zero),			.stall(stall),
						.Tuse_rs_0(D_tuse_rs_0), .Tuse_rs_1(D_tuse_rs_1), 	.MDU_op(D_MDU_op), 
						.Tuse_rt_0(D_tuse_rt_0), .Tuse_rt_1(D_tuse_rt_1), 	.Tuse_rt_2(D_tuse_rt_2),
						.A1(D_A1), 	.A2(D_A2), 	.A3(D_A3), .new_at(D_new_at), //forward & stall 信息输出
						.NPCop(D_NPCop), .sign(D_sign),.reg_write(D_reg_write),
						.null_slot(D_null_slot));//功能部件

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
	
	wire [1:0] E_zero, E_cmp;
	//EREG				//input
	SPEREG i_ereg (	.instr(D_instr), 				.PC(D_PC), 		.RD1(D_RD1_fwd_mux), .RD2(D_RD2_fwd_mux),
							.ext_imm32(D_ext_imm32), 	.cmp(D_cmp), 	.zero(D_zero), 
							//output
							.E_RD1(E_RD1), 	.E_RD2(E_RD2), 		.E_ext_imm32(E_ext_imm32),
							.E_PC(E_PC), 		.E_instr(E_instr), 	.E_cmp(E_cmp), 	
							.E_zero(E_zero),  .E_fwd_src(E_fwd_src),
							//control
							.reset(E_reset), 	.en(E_en),	.clk(clk), .E_fwd_src_sel(E_fwd_src_sel));

	//CTRL			//ordinary
	CTRL i_ectrl (	.instr(E_instr), 	.ALU_src(E_ALU_src),		.ALU_op(E_ALU_op),	.MDU_op(E_MDU_op),	.start(E_start),
						.reg_write(E_reg_write),	.cmp(E_cmp), 	.zero(E_zero), 		.CAL_sel(E_CAL_sel),
						//hazard
						.A1(E_A1), 	.A2(E_A2), 		.A3(E_A3), 		.new_at(E_new_at), 	.fwd_src_sel(E_fwd_src_sel),
						.islrm(E_lrm));

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
	ALU i_ealu   (	.ctrl(E_ALU_op), 	.overflow(overflow), 
						.A(E_RD1_fwd_mux),.B(E_ALU_B_mux), 	.result(E_ALU_res), 	.shamt(E_instr[10:6]));

	MDU i_mdu	(	.start(E_start), 	.D1(E_RD1_fwd_mux), 	.D2(E_ALU_B_mux), .MDU_op(E_MDU_op),
						.clk(clk),	.reset(reset),	.real_busy(E_real_busy),	.MDU_out(E_MDU_out));
						
	assign E_CAL_res = (E_CAL_sel == `sel_MDU) ? E_MDU_out : E_ALU_res; 

	//////////////////////////////////////////////////////////////
	//*********************Mstage********************************
	//////////////////////////////////////////////////////////////
	wire [1:0] M_zero, M_cmp;
	//MREG			//input
	SPMREG i_mreg(	.instr(E_instr),	.PC(E_PC),	.RD2(E_RD2_fwd_mux),	.CAL_res(E_CAL_res), 
						.cmp(E_cmp),		.zero(E_zero),		.M_fwd_src(M_fwd_src),
						//output
						.M_CAL_res(M_CAL_res),	.M_RD2(M_RD2),	.M_PC(M_PC),
						.M_instr(M_instr),		.M_cmp(M_cmp),	.M_zero(M_zero),
						//control
						.en(M_en),	.reset(M_reset),	.clk(clk),	.M_fwd_src_sel(M_fwd_src_sel));
	wire M_DM_sign;
	//CTRL
	CTRL i_mctrl (	.instr(M_instr),	.mem_write(M_mem_write),	.reg_write(M_reg_write), 
						.cmp(M_cmp),		.zero(M_zero), .LS_op(M_LS_op),		.DM_sign(M_DM_sign),
						.A1(M_A1), .A2(M_A2), .A3(M_A3), .new_at(M_new_at), 	.fwd_src_sel(M_fwd_src_sel),
						.DM_RD(M_DM_RD), .RD2(M_RD2_fwd_mux),// M_RD2_fwd_mux 这里应该用转发的, 我以前用了M_RD2
						.islrm(M_lrm));

	//****M转发点*******			 
	assign M_RD2_fwd_mux = (M_RD2_fwd_ctrl == `M_RD2_fwd_W) ? W_fwd_src ://check???转发最终结果， 别只转发DM_RD啊
																							M_RD2;
	//DM
	//DM  i_mdm		(.clk(clk), .reset(reset), .WE(M_mem_write), .PC(M_PC), 
	//			 .A(M_ALU_res), .WD(M_RD2_fwd_mux), .RD(M_DM_RD), .LS_op(M_LS_op));

	BYTEEN i_byteen (.A(M_CAL_res), 	.WE(M_mem_write),	.LS_op(M_LS_op), 
						  .byte_en(m_data_byteen));
						  
	assign m_data_addr = M_CAL_res;
	assign m_data_wdata = (M_LS_op == `LS_h) ? (M_RD2_fwd_mux << (M_CAL_res[1] * 16)) :
								 (M_LS_op == `LS_b) ? (M_RD2_fwd_mux << (M_CAL_res[1:0] * 8)):
								 M_RD2_fwd_mux;
	assign m_inst_addr = M_PC;

	DATA_EXT i_dataext (.A(M_CAL_res), .LS_op(M_LS_op), .RDin(m_data_rdata), .DM_sign(M_DM_sign), 
							  .RDout(M_DM_RD));
			
	//////////////////////////////////////////////////////////////
	//*********************Wstage********************************
	//////////////////////////////////////////////////////////////
	wire [1:0] W_zero, W_cmp;wire [31:0] W_RD2;
	//WREG
	SPWREG i_wreg (  .clk(clk),	.en(W_en),	.reset(W_reset),	.cmp(M_cmp),	.RD2(M_RD2), 
						  .instr(M_instr),	.PC(M_PC),		.CAL_res(M_CAL_res),	.DM_RD(M_DM_RD),	 
						  .zero(M_zero),		.W_PC(W_PC),	.W_instr(W_instr),	.W_CAL_res(W_CAL_res), 
						  .W_DM_RD(W_DM_RD),	.W_cmp(W_cmp),	.W_zero(W_zero),		.W_RD2(W_RD2), 
						  .W_fwd_src(W_fwd_src),	.W_fwd_src_sel(W_fwd_src_sel));
	
	//CTRL
	CTRL i_wctrl    (	.instr(W_instr),	.reg_write(W_reg_write),	.reg_dst(W_reg_dst), 
							.DM_RD(W_DM_RD), 	.RD2(W_RD2),
							.which_to_reg(W_which_to_reg),	.cmp(W_cmp),		.zero(W_zero), 
							.A1(W_A1), .A2(W_A2), .A3(W_A3), .new_at(W_new_at),.fwd_src_sel(W_fwd_src_sel),
							.islrm(W_lrm));//转发的时候不用判断we，因为呢，如果不写入，我们使其A3=0,写入0，这样会被我们的A3!=0滤掉，不会转发啦

	assign w_grf_we = W_reg_write;
	assign w_grf_addr = W_grf_A3_mux;
	assign w_grf_wdata = W_grf_WD3_mux;
	assign w_inst_addr = W_PC;
	assign W_grf_A3_mux = (W_reg_dst == `sel_rd) ? W_instr[15:11] : 
								 (W_reg_dst == `sel_rt) ? W_instr[20:16] :
								 (W_reg_dst == `sel_DM_RD) ? M_DM_RD[4:0]: 
								 (W_reg_dst == `sel_4) ? 4:
								 (W_reg_dst == `sel_5) ? 5://check!!
								 (W_reg_dst == `sel_31) ? 31 :
								 23;// default 23
	assign W_grf_WD3_mux = (W_which_to_reg == `sel_PC4) ?  (W_PC+8) :
								  (W_which_to_reg == `sel_res) ?  W_CAL_res : 
								  (W_which_to_reg == `sel_dm)  ?  W_DM_RD :
								  (W_which_to_reg == `sel_grfrt) ? W_RD2 :
								 233333;
	////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//FWD_CTRL
	FWD_CTRL i_fwdctrl (.D_A1(D_A1), .D_A2(D_A2), .D_A3(D_A3), .E_A1(E_A1), .E_A2(E_A2), .E_A3(E_A3),
							  .M_A1(M_A1), .M_A2(M_A2), .M_A3(M_A3), .W_A1(W_A1), .W_A2(W_A2), .W_A3(W_A3), 
							  .D_RD1_fwd_ctrl(D_RD1_fwd_ctrl), .D_RD2_fwd_ctrl(D_RD2_fwd_ctrl), .E_RD1_fwd_ctrl(E_RD1_fwd_ctrl),
							  .E_RD2_fwd_ctrl(E_RD2_fwd_ctrl), .M_RD2_fwd_ctrl(M_RD2_fwd_ctrl));
	//STALL_CTRL
	STALL_CTRL i_stallctrl(.D_tuse_rs_1(D_tuse_rs_1), .D_tuse_rs_0(D_tuse_rs_0), .D_tuse_rt_2(D_tuse_rt_2),
								  .D_tuse_rt_1(D_tuse_rt_1), .D_tuse_rt_0(D_tuse_rt_0), .D_MDU_op(D_MDU_op),
								  .E_new_at(E_new_at), .M_new_at(M_new_at),	.E_real_busy(E_real_busy), 
								  .D_A1(D_A1), .D_A2(D_A2), .D_A3(D_A3), .lrm_in_pip(lrm_in_pip),
								  .E_A3(E_A3), .M_A3(M_A3), .W_A3(W_A3), .stall(stall));
endmodule
