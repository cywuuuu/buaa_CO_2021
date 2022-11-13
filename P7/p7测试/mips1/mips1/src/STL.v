`timescale 1ns / 1ps
`include "const.v"
`default_nettype wire

module STL(
	input [31:0] D_Instr,
	input [31:0] E_Instr,
	input [31:0] M_Instr,
	input [31:0] W_Instr,
	input E_MDU_busy,
	input D_cmp,
	input E_cmp,
	input M_cmp,
	output IFU_en,
	output F2D_en,
	output F2D_flush,
	output D2E_en,
	output D2E_flush,
	output E2M_en,
	output E2M_flush,
	output M2W_en,
	output stall
	);

	wire [2:0] E_tnew, M_tnew, W_tnew, rs_tuse, rt_tuse;
	
/////////////////////////////////////////////////stage D/////////////////////////////////////////////////
	wire [4:0] D_rs, D_rt, D_RF_A3;
	wire D_load, D_store, D_cali, D_calr, D_branch, D_jreg, D_shifts, D_mtc0;
	wire D_branchlr, D_branchl, D_mov, D_bmlr, D_mthilo, D_mdhilo, D_mfhilo, D_mdr, D_eret;
	
	CTR D_CTR (
    .Instr(D_Instr),
	 .cmp(D_cmp),
    .rs(D_rs), 
    .rt(D_rt), 
    .RF_A3(D_RF_A3), 
    .jreg(D_jreg), 
    .lui(D_lui), 
    .cali(D_cali), 
    .calr(D_calr), 
    .load(D_load), 
    .store(D_store),
	 .shifts(D_shifts),
    .branch(D_branch),
	 .branchl(D_branchl),
	 .branchlr(D_branchlr),
	 .mov(D_mov),
	 .bmlr(D_bmlr),
	 .mthilo(D_mthilo),
	 .mdhilo(D_mdhilo),
	 .mfhilo(D_mfhilo),
	 .mdr(D_mdr),
	 .eret(D_eret),
	 .mtc0(D_mtc0)
   );
	 
	assign rs_tuse = (D_branch|D_jreg|D_branchl|D_branchlr)? 0:
						  (D_cali|(D_calr && !D_shifts)|D_load|D_store|D_bmlr|D_mthilo|D_mdhilo|D_mdr)? 1:
						  3;
	
	assign rt_tuse = (D_branch|D_mov|(D_branchlr&&D_cmp))? 0:
						  (D_cali|D_calr|D_mdhilo|D_mdr)? 1:
						  (D_store|D_bmlr|D_mtc0)? 2: 
						  3;
						  
/////////////////////////////////////////////////stage E/////////////////////////////////////////////////
	wire [4:0] E_RF_A3, E_rd;
	wire E_load, E_cali, E_calr, E_bmlr, E_mfhilo, E_mdr, E_mtc0, E_mfc0;
	
	CTR E_CTR (
    .Instr(E_Instr),
	 .rd(E_rd),
	 .cmp(E_cmp),
    .RF_A3(E_RF_A3), 
    .cali(E_cali), 
    .calr(E_calr), 
    .load(E_load),
	 .bmlr(E_bmlr),
	 .mfhilo(E_mfhilo),
	 .mdr(E_mdr),
	 .mtc0(E_mtc0),
	 .mfc0(E_mfc0)
   );
	assign E_tnew = (E_cali|E_calr|E_mfhilo)? 1:
						 (E_load|E_bmlr|E_mfc0)? 2: 0;
	 
/////////////////////////////////////////////////stage M///////////////////////////////////////////////// 
	wire [4:0] M_RF_A3, M_rd;
	wire M_load, M_bmlr, M_mtc0, M_mfc0;
	
	CTR M_CTR (
    .Instr(M_Instr),
	 .rd(M_rd),
	 .cmp(M_cmp),
    .RF_A3(M_RF_A3), 
    .load(M_load),
	 .bmlr(M_bmlr),
	 .mtc0(M_mtc0),
	 .mfc0(M_mfc0)
   );
	assign M_tnew = (M_load|M_bmlr|M_mfc0)? 1: 0;
	
///////////////////////////////////////////////// judge ///////////////////////////////////////////////// 
	
	wire rs_stall_E = (rs_tuse<E_tnew && D_rs && ((E_bmlr)? (D_rs==5'd31): E_RF_A3==D_rs));
	wire rs_stall_M = (rs_tuse<M_tnew && D_rs && ((M_bmlr)? (D_rs==5'd31): M_RF_A3==D_rs));
	wire rt_stall_E = (rt_tuse<E_tnew && D_rt && ((E_bmlr)? (D_rt==5'd31): E_RF_A3==D_rt));
	wire rt_stall_M = (rt_tuse<M_tnew && D_rt && ((M_bmlr)? (D_rt==5'd31): M_RF_A3==D_rt));
	
	wire MDU_stall = E_MDU_busy&&(D_mfhilo|D_mdhilo|D_mthilo);
	wire mdr_stall = E_MDU_busy&&(E_mdr);
	wire CP0_stall = D_eret & ((E_mtc0&&E_rd==5'd14)|(M_mtc0&&M_rd==5'd14));
	
	assign stall = rs_stall_E|rs_stall_M|rt_stall_E|rt_stall_M|MDU_stall|CP0_stall;
	
	assign IFU_en		= (D_bmlr|E_bmlr)? 0: 
							  (E_mdr)? ~mdr_stall: 
							  ~stall;
	assign F2D_en		= (D_bmlr|E_bmlr)? 0:
							  (E_mdr)? ~mdr_stall:
							  ~stall;
	assign F2D_flush	= (D_bmlr|E_bmlr)? 1: 0;
	assign D2E_en		= (D_bmlr|E_bmlr)? 1:
							  (E_mdr)? ~mdr_stall:
							  ~stall;
	assign D2E_flush	= (D_bmlr|E_bmlr)? 0: 
							  (E_mdr)? 0: 
							  stall;
	assign E2M_en 		= (E_mdr)? ~mdr_stall: 1;
	assign E2M_flush	= (E_mdr)? mdr_stall: 0;
	assign M2W_en 		= 1;

endmodule
