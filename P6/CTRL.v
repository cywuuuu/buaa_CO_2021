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
`include "./header.v"//��ָ��point1

module CTRL(
    input [31:0] instr,
	 input [1:0] cmp,
	 input [1:0] zero, 
	 output [2:0] fwd_src_sel,
    output reg_write,
    output [2:0]reg_dst,
    output [2:0] which_to_reg,
	 output [1:0]ALU_src,
    output mem_write,
	 output [2:0]NPCop,
	 output [4:0]ALU_op,
	 output [4:0]MDU_op,
	 output start,
	 output CAL_sel,
	 output [1:0]LS_op,
	 output DM_sign, 
	 output sign,//ÿ��ָ��ȷ��������źžͶ�����
	 output Tuse_rs_0,
	 output Tuse_rs_1,
	 output Tuse_rt_0,
	 output Tuse_rt_1,
	 output Tuse_rt_2,//ÿ��ָ����е����ԣ� ����forward unit������ת��
	 output [2:0] new_at,//ÿ��ָ��ȷ���󣬲���������ȷ��
	 output [4:0]A1,
	 output [4:0]A2,
	 output [4:0]A3//ÿ��ָ��ȷ���� ���ǵĲ�������ȷ��
    );
	/*
	{addu, subu, ori, lw, sw, beq, lui, jal, jr,nop}
	*/
	//������
	wire [5:0] opcode = instr[31:26];
	wire [5:0] func = instr[5:0];
	wire [5:0] rt = instr[20:16];
	wire AND, OR, SLLV, SLL, SRL, SRA, SRLV, SRAV, SLT, JR, JALR, J, JAL, ADDIU, ADDU, SUBU, ADDI, 
	ORI, LUI, SLTI, SW, LW, BEQ, BLEZ, LHU, RTYPE, ANDI, SH, SB, LH, LB, LBU, ADD, SUB; //��ָ��point2
	assign RTYPE = (opcode == `op_rtype);

	
	assign ADD = (opcode == `op_rtype && func == `func_add);
	assign SUB = (opcode == `op_rtype && func == `func_sub);
	assign ADDU = (opcode == `op_rtype && func == `func_addu);
	assign SUBU = (opcode == `op_rtype && func == `func_subu);
	
	assign MULT = (opcode == `op_rtype && func == `func_mult);
	assign MULTU = (opcode == `op_rtype && func == `func_multu);	
	assign DIV = (opcode == `op_rtype && func == `func_div);
	assign DIVU = (opcode == `op_rtype && func == `func_divu);	
	assign MFHI = (opcode == `op_rtype && func == `func_mfhi);
	assign MFLO = (opcode == `op_rtype && func == `func_mflo);	
	assign MTHI = (opcode == `op_rtype && func == `func_mthi);
	assign MTLO = (opcode == `op_rtype && func == `func_mtlo);	
	
	assign AND = (opcode == `op_rtype && func == `func_and);
	assign OR = (opcode == `op_rtype && func == `func_or);	
	assign XOR = (opcode == `op_rtype && func == `func_xor);
	assign NOR = (opcode == `op_rtype && func == `func_nor);	

	assign BEQ = opcode == `op_beq;
	assign BNE = opcode == `op_bne;
	assign BLEZ = opcode == `op_blez;
	assign BGTZ = opcode == `op_bgtz;
	assign BLTZ = opcode == `op_bltzbgez && rt == `rt_bltz;
	assign BGEZ = opcode == `op_bltzbgez && rt == `rt_bgez;
	
	assign SLL = (opcode == `op_rtype && func == `func_sll);
	assign SLLV = (opcode == `op_rtype && func == `func_sllv);
	assign SRL = (opcode == `op_rtype && func == `func_srl);
	assign SRA = (opcode == `op_rtype && func == `func_sra);
	assign SRLV = (opcode == `op_rtype && func == `func_srlv);	
	assign SRAV = (opcode == `op_rtype && func == `func_srav);	
		
	assign SLT = (opcode == `op_rtype && func == `func_slt);
	assign SLTU = (opcode == `op_rtype && func == `func_sltu); 

	assign JR = (opcode == `op_rtype && func == `func_jr); //PC <- GPR[rs], src A RD1
	assign JALR = (opcode == `op_rtype && func == `func_jalr);// PC ? GPR[rs]  GPR[rd] ? PC + 4, 
	assign J = opcode == `op_j;// j type
	assign JAL = opcode == `op_jal;// j type, link $31 to PC+4
	
	assign ANDI = opcode == `op_andi;
	assign ORI = opcode == `op_ori;
	assign XORI = opcode == `op_xori;
	assign ADDIU = opcode == `op_addiu;
	assign LUI = opcode == `op_lui;
	assign SLTI = opcode == `op_slti;
	assign SLTIU = opcode == `op_sltiu; 
	assign ADDI = opcode == `op_addi;
	
	assign SW = opcode == `op_sw;
	assign LW = opcode == `op_lw;
	assign LBU = (opcode == `op_lbu);
	assign LHU = opcode == `op_lhu;	
	assign LB = opcode == `op_lb;
	assign LH = opcode == `op_lh;
	assign SB = opcode == `op_sb;
	assign SH = opcode == `op_sh;
	

	//��ָ��point3
	//��ָ��slti,lui
	/*
	`define fwd_src_ALUres 3'b011
	`define fwd_src_DM_RD 3'b010
	`define fwd_src_PC8 3'b001
	*/
	//д�Ĵ�����ָ��Ҫ��һ������
	assign fwd_src_sel =  	( LW | LH | LB | LBU | LHU) ? `fwd_src_DM_RD : 
									(JAL | JALR) ? `fwd_src_PC8 : 
									`fwd_src_CALres ;// CAL��ָ ALU,MDU

	assign CAL_sel = (MFHI | MFLO) ? `sel_MDU : `sel_ALU;  
	assign start = MULT | MULTU | DIV | DIVU ;
	////����Ϊ��ָ��point4, ע��ӿڸı�����ʹ���Ŷ, ע���¼�����Ŀ���
	assign reg_write = AND | OR | XOR | NOR | SLT | SLTU | SLTIU | SLTI | SLLV | SLL | SRL | SRA | SRLV | SRAV |LW 
	| LH | LB | LBU | LHU | ADD | SUB | ADDU | SUBU | JAL | JALR | ADDI | ADDIU | ANDI | ORI | XORI | LUI | MFHI |MFLO  ;//BGEZAL&&branch
	assign LS_op = (LW | SW) ? `LS_w : 
						(LH | SH | LHU) ? `LS_h :
						(LB | SB | LBU) ? `LS_b : 
						`LS_w;
	assign DM_sign = (LB | LH) ? 1 : 0;


	assign reg_dst = (RTYPE) ? `sel_rd   : // mfhi, mflo jalr is rtype 
						  (JAL) 	 ? `sel_31 :
							         `sel_rt;

	
	assign which_to_reg = (LW | LH | LB | LBU | LHU) ? `sel_dm : 
								 (JAL | JALR) ? `sel_PC4 :								 // ����PC+4����һ����
								 `sel_res;
								 

	assign sign = (ORI | ANDI | XORI) ? `ext_zero : `ext_sign;
	
	// ALU_src, B = imm or GPRrt �� RD2
	/*
	// sel ALU_srcB
	`define sel_RD2   2'b00
	`define sel_imm32 2'b01
	*/
	assign ALU_src = ( ORI | XORI | ANDI| LUI | SLTI | SLTIU | ADDIU | ADDI | 
							 LW | SW | LH | LB | SH | SB | LHU | LBU) ? `sel_imm32 : 
						  `sel_RD2;
						  					  
	wire branch, j, jr;
	//�ж��Ƿ���ת
	assign branch = 		(BEQ &&(cmp	 ==`cmp_eq  )) 
							|| (BLEZ&&(zero == `zero_eq || zero == `zero_lt)) 
							|| (BNE &&(cmp  == `cmp_lt  || cmp  == `cmp_gt ))
							|| (BGTZ&&(zero == `zero_gt))
							|| (BLTZ&&(zero == `zero_lt))
							|| (BGEZ&&(zero == `zero_eq || zero == `zero_gt)) ;     // PC <- PC + 4 + sign_ext(imm16|00)
	//bgezal
	assign jr = (JR | JALR);	assign j = (JAL | J); //PC <- PC[31:28]|imm26|00
	assign NPCop = (branch) ? `NPCop_B : 
						(j)		? `NPCop_J :
						(jr)		? `NPCop_JR:
						`NPCop_PC4;
	
	
	assign ALU_op = (SUBU | SUB) ? `ALU_sub : 
						 (AND | ANDI) ? `ALU_and :
						 (OR | ORI) ? `ALU_or :
						 (NOR) ? `ALU_nor : 
						 (XOR | XORI) ? `ALU_xor :
						 (SLT | SLTI) ? `ALU_slt : 
						 (SLTU | SLTIU) ? `ALU_sltu : 
						 (LUI) ? `ALU_lui :
						 (SLL) ? `ALU_sll :
						 (SLLV)? `ALU_sllv :
						 (SRL) ? `ALU_srl :
						 (SRLV)? `ALU_srlv :
						 (SRA) ? `ALU_sra :
						 (SRAV)? `ALU_srav :						 
						 `ALU_add;// never used
	
	assign MDU_op = (MULT) ? `MDU_mult :
						 (MULTU) ? `MDU_multu :
						 (DIV) ? `MDU_div :
						 (DIVU) ? `MDU_divu :
						 (MFHI) ? `MDU_mfhi :
						 (MFLO) ? `MDU_mflo :
						 (MTHI) ? `MDU_mthi :
						 (MTLO) ? `MDU_mtlo :
						 0;
	
	assign mem_write = SW | SH | SB;
	
	//***Acode
	/////////////////////forward_signal/////////////////////////
	assign A1 = instr[25:21];
	assign A2 = instr[20:16];
	assign A3 = (RTYPE)?instr[15:11] : //mflo,mfhi����R,дrd
					(ORI | LUI | SLTI | SLTIU | LW | LB | LH | LBU | LHU | ADDIU | ANDI | XORI | ADDI) ? instr[20:16] :
					(JAL || JALR) ? 31 :// || (BGEZAL&&branch)
					0;//д�Ĵ����Ĳ���A3!=0, ��д��ͳͳA3=0
					
	//////////////////////stall_signal/////////////////////////
	//ɶʱ���üĴ����� ���õĲ�д d,e,m
	assign Tuse_rs_0 = JR | JALR | BEQ | BNE | BLEZ | BGTZ | BLTZ | BGEZ;//JR | JALR | BEQ | BLEZ | BGEZAL;
	assign Tuse_rs_1 = AND | OR | NOR | XOR |ADDIU | ADDU | ADD | SUB | SUBU | SW | LW | SH | SB| LH | LB | LBU | LHU |
							 MTHI | MTLO | MULT | MULTU | DIV | DIVU | ORI | ANDI | XORI | ADDI | 
							 SLLV | SRAV | SRLV | SLT | SLTU | SLTI | SLTIU;
	assign Tuse_rt_0 = BEQ | BNE ;
	assign Tuse_rt_1 = AND | OR | NOR | XOR | ADDU | SUBU | ADD | SUB | SLL | SLLV | SRA | SRAV | 
							 SRL | SRLV | SLT | SLTU | MULT | MULTU | DIV | DIVU ;
	assign Tuse_rt_2 = SH| SB| SW;
	//Ҫ�ԼĴ���GRF[A3]д��Ľ������������

	assign new_at = (JAL | JALR) ? `new_at_PC : // (JAL | JALR | (BGEZAL&&branch)) 
						 (LW | LB | LH | LBU | LHU) ? `new_at_DM : 
						 (ADDU | ADD | SUBU | SUB | AND | OR | XOR | NOR | SLT |
						  ADDIU | ORI | ANDI | XORI | LUI | SLTI | SLTIU | SLTU | ADDI |
						  SLL | SLLV | SRA | SRAV | SRL | SRLV | MFHI | MFLO )?`new_at_CAL :
						 0 ; //дʹ��Ϊ0�򲻿��ǣ������Ļ��Ͳ����ж�Ϊ������
	
endmodule
/*
����ͼ򵥽��� P5 ����·�ɡ�

���ȿ��ϵ�����ָ����� + ��ת + �洢��

�����������򵥵ģ��ص��������д����������� always@(*) ��ô���ⲻ�󡣵���������õ��� assign ��ô���ʹ�� function ��ʵ�ּ���ָ�
��תһ��Ҳ���ѣ�һ����������ת + ����д�� ��תָ��һ���ô����������� D �������Ƿ���ת�ģ�Ҳ����˵�� D ������Ի��ȫ������ȷ��Ϣ���෴����������� lwso ���֣������Ҫ���� DM ��ֵ���ܾ�����ô�������������ǵķ����� D ������һ�� D_check �ź�Ȼ����ˮ����Ȼ��ÿһ����������ź��ж�д���ַ/д��ֵ֮��ġ�

 // ����ź�
 D_check = D_bgezalc & D_b_jump;
 // CU
 assign RFDst = // ...
               bgezalc ? (check ? 5'd31 : 5'd0) :
               5'd0;
�����洢һ�������ѵġ� ������������·֮��Ҳ���á������洢���ص��Ǳ���Ҫ�� M ����֪��Ҫдɶ����͸�ת��֮�����������ѣ��������ǵĲ�������� D ��Ҫ���Ĵ�����������ָ�����Ҫд����Ĵ�������ô�� stall��������˵�������ģ�

 // lwso
 wire stall_rs_e = (TuseRS < TnewE) && D_rs_addr && (D_lwso ? D_rs_addr == 5'd31 : A1 D_rs_addr == E_RFDstA3);
 // lrm
 wire stall_rs_e = (TuseRS < TnewE) && D_rs_addr && (D_lrm ? D_rs_addr : D_rs_addr == E_RFDst);
�� CU �е�д������������ת���ơ�


 // lwso
 M_check = D_lwso && condition;
 // CU
 assign RFDst = // ...
               lwso ? (check===1'd1 ? 5'd31 : 5'd0) : // ע�ⲻ��ֱ��һ�� check, ��д�Ļ�ֱ��0�� д�Ļ�����31
               5'd0;
����Ҫע���һ���ǣ�������õ���ͳһ CU ��д������ô�����һ�����⣺check �ź�ֻ���� M �����롣���ʱ���� E ���� CU ��������ź��ǲ���̬ x�������ᵼ�� RFDst �źų������������������д���� check===1'd1�����������ų� x �������
*/