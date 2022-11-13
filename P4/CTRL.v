`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    10:31:09 11/01/2021 
// Design Name: 
// Module Name:    CTRL 
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
`include "./header.v"//加指令point1

module CTRL(
    input [5:0] opcode,
    input [5:0] func,
	 input [1:0] cmp,
	 input [1:0] zero, 
	 input [4:0] rt,
    output reg_write,
    output [2:0]reg_dst,
    output [2:0] which_to_reg,
	 output [1:0]ALU_src,
    output mem_write,
	 output [2:0]NPCop,
	 output [4:0]ALU_op,
	 output [1:0]LS_op,
	 output sign
    );
	/*
	{addu, subu, ori, lw, sw, beq, lui, jal, jr,nop}
	*/
	wire AND, OR, SLLV, SLT, JR, JALR, J, JAL, ADDIU, ADDU, SUBU,
	ORI, LUI, SLTI, SW, LW, BEQ, BLEZ, LHU, RTYPE, ANDI, SH, SB, LH, LB; //加指令point2
	assign RTYPE = (opcode == `op_rtype);
	assign ADDU = (opcode == `op_rtype && func == `func_addu);
	assign SUBU = (opcode == `op_rtype && func == `func_subu);
	assign AND = (opcode == `op_rtype && func == `func_and);
	assign OR = (opcode == `op_rtype && func == `func_or);	
	//assign SLL = (opcode == `op_rtype && func == `func_sll);
	assign SLLV = (opcode == `op_rtype && func == `func_sllv);
	assign SLT = (opcode == `op_rtype && func == `func_slt);
	assign JR = (opcode == `op_rtype && func == `func_jr); //PC <- GPR[rs], src A RD1
	assign JALR = (opcode == `op_rtype && func == `func_jalr);// PC ? GPR[rs]  GPR[rd] ? PC + 4, 
	assign J = opcode == `op_j;// j type
	assign JAL = opcode == `op_jal;// j type, link $31 to PC+4
	assign ANDI = opcode == `op_andi;
	assign ADDIU = opcode == `op_addiu;
	assign ORI = opcode == `op_ori;
	assign LUI = opcode == `op_lui;
	assign SLTI = opcode == `op_slti;
	assign SW = opcode == `op_sw;
	assign LW = opcode == `op_lw;
	assign BEQ = opcode == `op_beq;
	assign BLEZ = opcode == `op_blez;
	assign LHU = opcode == `op_lhu;	
	assign LB = opcode == `op_lb;
	assign LH = opcode == `op_lh;
	assign SB = opcode == `op_sb;
	assign SH = opcode == `op_sh;//加指令point3

	
	////以下为加指令point4, 注意接口改变扩充和搭线哦, 注意新加输出的控制
	assign reg_write = ADDU | AND | SUBU | OR  | SLT | SLLV | LW | LH | LB |
	JAL | JALR | ADDIU | ORI | LUI | SLTI ;
	assign LS_op = (LW | SW) ? `LS_w : 
						(LH | SH) ? `LS_h :
						(LB | SB) ? `LS_b : 
						`LS_w;
	//A3 = ? Rtype rd, Itype rt, link ,
	assign reg_dst = (RTYPE) ? `sel_rd   : // jalr is rtype 
						  (JAL) 	 ? `sel_31 :
							         `sel_rt;
	//WD3 = ? WD, PC+4, res
	
	assign which_to_reg = (LW | LH | LB) ? `sel_dm : 
								 (JAL | JALR) ? `sel_PC4:// 生成PC+4但不一定用
								 `sel_res;
								 

	assign sign = (ORI || ANDI) ? `ext_zero : `ext_sign;
	
	// ALU_src, B = imm or GPRrt 即 RD2
	/*
	// sel ALU_srcB
	`define sel_RD2   2'b00
	`define sel_imm32 2'b01
	*/
	assign ALU_src = ( ORI || LUI || SLTI || LW || ADDIU || ANDI || SW || LH || LB || SH || SB) ? `sel_imm32 : 
						  `sel_RD2;
						  
	wire branch, j, jr;
	//判断是否跳转
	assign branch = (BEQ&&cmp==`cmp_eq) || (BLEZ&&(zero == `zero_eq || zero == `zero_lt)) ;     // PC <- PC + 4 + sign_ext(imm16|00)
	
	//PC <- GPR[rs]
	assign jr = (JR || JALR);
		assign j = (JAL || J); //PC <- PC[31:28]|imm26|00
	
	assign NPCop = (branch) ? `NPCop_B : 
						(j)		? `NPCop_J :
						(jr)		? `NPCop_JR:
						`NPCop_PC4;
	
	
	assign ALU_op = (SUBU) ? `ALU_sub : 
						 (AND || ANDI) ? `ALU_and :
						 (OR || ORI) ? `ALU_or :
						 //(SLL) ? `ALU_sll :
						 (SLT || SLTI) ? `ALU_slt : 
						 (LUI) ? `ALU_lui :
						 (SLLV)? `ALU_sllv :
						 `ALU_add;// never used
	//zero 0, sign 1
	
	assign mem_write = SW | SH | SB;
	
	//ori,andi 0ext(not done), branch imm26 signext(done),slti sign_ext(not done), sh/sw sign_ext(done)
//addi s_ext(not done),   
	
	
	
endmodule
