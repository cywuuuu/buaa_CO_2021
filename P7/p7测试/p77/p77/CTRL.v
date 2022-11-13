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
// 1. ��ctrl��stall,forward..
// 2. ������ͨ·���������ź��˰��������������ͨ·�˾Ͳ�����
module CTRL(
    input [31:0] instr,
	 input [1:0] cmp,
	 input [1:0] zero, 
	 input stall,
	 input [4:0] DM_RD, 
	 output [2:0] fwd_src_sel,
    output reg_write,
    output [2:0]reg_dst,
    output [2:0] which_to_reg,
	 output [1:0] ALU_src,
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
	 output [4:0]A3,//ÿ��ָ��ȷ���� ���ǵĲ�������ȷ��
	 output null_slot, 
	 output islrm, 
	 output has_DB, //D
	 output ismtc0,//ALL eret��������Ҫ���дCP0 
	 output ismfc0,//дgrf,�൱��new at dm, �õ�����ͨת��
	 output iseret, //D
	 output CP0_WE, //M
	 input overflow, 
	 input [31:0]m_data_addr, 
	 output exc_RI, 
	 output exc_Ov, 
	 output exc_AdEL, 
	 output exc_AdES, 
	 output [31:0]mtc0_dst
    );
	/*
	{addu, subu, ori, lw, sw, beq, lui, jal, jr,nop}
	*/
	//������
	wire [5:0] opcode = instr[31:26];
	wire [5:0] func = instr[5:0];
	wire [5:0] rt = instr[20:16];
	wire [5:0] rs = instr[25:21]; 
	

	wire RTYPE ,ADD, SUB, ADDU, SUBU, MULT, MULTU, DIV, DIVU, MFHI, MFLO, MTHI, MTLO, AND, OR, XOR, NOR;  
	wire ANDI, ORI, XORI, ADDIU, LUI, SLTI, SLTIU, ADDI, SW, LW, LBU, LHU, LB, LH, SB, SH, LRM, ERET, MTC0, MFC0; 
	wire BEQ, BNE, BLEZ, BGTZ, BLTZ, BGEZ, BGEZALL, SLL, SLLV, SRL, SRLV, SRAV, SLT, SLTU, JR, JALR, J, JAL;
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
	assign BGEZALL = (opcode == `op_bgezall) && (rt == `rt_bgezall);
	
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
	assign LRM = opcode == `op_lrm;
	assign null_slot = (BGEZALL && ~branch) && ~stall;
	//CP0 
	assign ERET = opcode == `op_cp0 && func == `func_eret; 
	assign MTC0 = opcode == `op_cp0 && rs == `rs_mtc0; 
	assign MFC0 = opcode == `op_cp0 && rs == `rs_mfc0; 
	assign iseret = ERET; 
	assign ismtc0 = MTC0;
	assign ismfc0 = MFC0; 
	assign CP0_WE = MTC0; 
	assign islrm = LRM;
	//��ָ��point3
	//��ָ��slti,lui
	/*
	`define fwd_src_ALUres 3'b011
	`define fwd_src_DM_RD 3'b010
	`define fwd_src_PC8 3'b001
	*/
	//exception//

	assign exc_RI = !(   BEQ | BNE | BGEZ | BGTZ | BLEZ | BLTZ |
                    J | JAL | JALR | JR |
                    LB | LBU | LH | LHU | LW | SB | SH | SW |
                    LUI | ADDI | ADDIU | ANDI | ORI | XORI | SLTI | SLTIU |
                    ADD | ADDU | SUB | SUBU  | ORI | SLT | SLTU |
                    SLL | SLLV | SRA | SRAV | SRL | SRLV |
                    ((opcode == 6'B000000) && (func == 6'B000000)) |
                    DIV | DIVU | MFHI | MFLO | MTHI | MTLO | MULT | MULTU |
                    MTC0 | MFC0 | ERET |ADD | SUB | ADDU | SUBU | MULT | MULTU | DIV | DIVU | MFHI | MFLO | MTHI | MTLO | AND | OR | XOR | NOR |
	ANDI | ORI | XORI | ADDIU | LUI | SLTI | SLTIU | ADDI | SW | LW | LBU | LHU | LB | LH | SB | SH | ERET | MTC0 | MFC0 | 
	BEQ | BNE | BLEZ | BGTZ | BLTZ | BGEZ | SLL | SLLV | SRL | SRLV | SRAV | SLT | SLTU | JR | JALR | J | JAL |
	(opcode == 0 && func == 0));//������syscall
	
	assign exc_Ov = (ADDI | ADD | SUB) && overflow;//
	
	wire not_align = ((LW|SW) && (|m_data_addr[1:0])) || 
					 ((LH|LHU|SH) && (m_data_addr[0])); 	
	wire ls_tc_not_word = (LH|LHU|LB|LBU|SH|SB) && (m_data_addr >= `dev0_addr_begin); 
	

	//ȡ Timer ��cnt�Ĵ����İ��֣�byte mem[2]
	

	/*
		((m_data_addr >= `dev0_addr_begin && m_data_addr <= `dev0_addr_end) || 
	 (m_data_addr >= `dev1_addr_begin && m_data_addr <= `dev1_addr_end)); 
	*/
	//д���쳣��ǰ�ᣬ д��д�Ǻ��
	wire save_tc_cnt =  
							  ((m_data_addr >= 32'h0000_7f08 && m_data_addr <= 32'h0000_7f0b) || 
								(m_data_addr >= 32'h0000_7f18 && m_data_addr <= 32'h0000_7f1b));
	wire DM_overflow = (LW|LH|LB|LBU|LHU|SB|SH|SW) && overflow; 	
	wire not_in_range = 	~((m_data_addr <= `dm_addr_end && m_data_addr >= `dm_addr_begin ) ||
							(m_data_addr >= `dev0_addr_begin && m_data_addr <= `dev0_addr_end) ||
							(m_data_addr >= `dev1_addr_begin && m_data_addr <= `dev1_addr_end)); 	
	assign exc_AdEL = (LW|LH|LB|LBU|LHU) && ((not_in_range) | not_align | ls_tc_not_word | DM_overflow ); 
	assign exc_AdES = (SB|SH|SW)&& ((not_in_range) | not_align | ls_tc_not_word | DM_overflow | save_tc_cnt); 
	//wire [1:0]bytt = CAL_res[1:0];//��E��֮��Ϊz
	//wire condition_LHS = (bytt == 0 || bytt == 2);
	
	assign CAL_sel = (MFHI | MFLO) ? `sel_MDU : `sel_ALU;  //md++
	assign start = MULT | MULTU | DIV | DIVU ; //md++
	////����Ϊ��ָ��point4, ע��ӿڸı�����ʹ���Ŷ, ע���¼�����Ŀ���
	
	assign LS_op = (LW | SW ) ? `LS_w : 
						(LH | SH | LHU) ? `LS_h :
						(LB | SB | LBU) ? `LS_b : 
						`LS_nothing;
	assign load_type = LW | LH | LB | LHU | LBU; 
	assign save_type = SW | SH | SB; 
	assign DM_sign = (LB | LH) ? 1 : 0;
	
	//����д OP&&condition===
	assign reg_write = AND | OR | XOR | NOR | SLT | SLTU | SLTIU | SLTI | SLLV | SLL | SRL | SRA | SRLV | SRAV |LW | MFC0 | 
	| LH | LB | LBU | LHU | ADD | SUB | ADDU | SUBU | JAL | JALR | ADDI | ADDIU | ANDI | ORI | XORI | LUI | MFHI |MFLO | BGEZALL | LRM;//BGEZAL&&branch


	assign reg_dst = (RTYPE) 					? `sel_rd   	: // mfhi, mflo jalr is rtype 
						  (JAL | BGEZALL) 	 	? `sel_31 		:
						  (LRM) 						? `sel_DM_RD 	:
							         `sel_rt;

	
	assign which_to_reg = (LW | LH | LB | LBU | LHU) ? `sel_dm : 
								 (JAL | JALR | BGEZALL) ? `sel_PC4 :								 // ����PC+4����һ����
								 (LRM) ? `sel_grfrt :
								 (MFC0) ? `sel_CP0 :
								 `sel_res;
								 

	assign sign = (ORI | ANDI | XORI) ? `ext_zero : `ext_sign;
	

	assign ALU_src = ( ORI | XORI | ANDI| LUI | SLTI | SLTIU | ADDIU | ADDI | 
							 LW | SW | LH | LB | SH | SB | LHU | LBU | LRM) ? `sel_imm32 : 
						  `sel_RD2;
						  					  
	wire branch, j, jr;
	//�ж��Ƿ���ת
	assign branch = 		(BEQ &&(cmp	 ==`cmp_eq  )) 
							|| (BLEZ&&(zero == `zero_eq || zero == `zero_lt)) 
							|| (BNE &&(cmp  == `cmp_lt  || cmp  == `cmp_gt ))
							|| (BGTZ&&(zero == `zero_gt))
							|| (BLTZ&&(zero == `zero_lt))
							|| (BGEZ&&(zero == `zero_eq || zero == `zero_gt)) 
							|| (BGEZALL && (zero == `zero_eq || zero == `zero_gt));     // PC <- PC + 4 + sign_ext(imm16|00)
	//bgezal
	assign jr = (JR | JALR);	assign j = (JAL | J); //PC <- PC[31:28]|imm26|00
	assign has_DB = BEQ | BLEZ | BNE | BGTZ | BLTZ | BGEZ | BGEZALL | JR | JALR | JAL | J; 
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
						 `ALU_add;
	
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
	assign A1 = instr[25:21];//rs, ���ص��ĳ�ͻ��stall, ���ò�дtuse���ɣ� ���ص���ת���� ת����Ҳ����
	assign A2 = instr[20:16];//rt
	//����д������ת�� 
	assign A3 = (RTYPE)?instr[15:11] : //mflo,mfhi����R,дrd
					(ORI | MFC0 | LUI | SLTI | SLTIU | LW | LB | LH | LBU | LHU | ADDIU | ANDI | XORI | ADDI ) ? instr[20:16] :
					(JAL || JALR || BGEZALL) ? 31 :// || (BGEZAL&&branch)
					//OP ? ((condition === ) ? reg1 : reg2) :
					(LRM) ? ((DM_RD[4:0] !== 5'bzzzzz) ? DM_RD[4:0] : 0): //�������DM_RD�Ų���zz,����A3����0
					0;//д�Ĵ����Ĳ���A3!=0, ��д��ͳͳA3=0
	assign mtc0_dst = (MTC0) ? instr[15:11]:0;
	//д�Ĵ�����ָ��Ҫ��һ�������������
	assign fwd_src_sel =  	( LW | LH | LB | LBU | LHU) ? `fwd_src_DM_RD : 
									(JAL | JALR | BGEZALL) ? `fwd_src_PC8 : 
									(LRM) ? `fwd_src_RD2 :
									(MFC0) ? `fwd_src_CP0 : 
									`fwd_src_CALres ;// CAL��ָ ALU,MDU

	//////////////////////stall_signal/////////////////////////
	//ɶʱ���üĴ����� ���õĲ�д, d,e,m, ��֮ǰ����ת����������stall
	assign Tuse_rs_0 = JR | JALR | BEQ | BNE | BLEZ | BGTZ | BLTZ | BGEZ | BGEZALL;//JR | JALR | BEQ | BLEZ | BGEZAL;
	assign Tuse_rs_1 = AND | OR | NOR | XOR |ADDIU | ADDU | ADD | SUB | SUBU | SW | LW | SH | SB| LH | LB | LBU | LHU |
							 MTHI | MTLO | MULT | MULTU | DIV | DIVU | ORI | ANDI | XORI | ADDI | LRM |
							 SLLV | SRAV | SRLV | SLT | SLTU | SLTI | SLTIU ;
	assign Tuse_rt_0 = BEQ | BNE ;
	assign Tuse_rt_1 = AND | OR | NOR | XOR | ADDU | SUBU | ADD | SUB | SLL | SLLV | SRA | SRAV | 
							 SRL | SRLV | SLT | SLTU | MULT | MULTU | DIV | DIVU ;
	assign Tuse_rt_2 = SH| SB| SW | MTC0;
	//Ҫ�ԼĴ���GRF[A3]д��Ľ������������
	
	assign new_at = (JAL | JALR | BGEZALL) ? `new_at_PC : // (JAL | JALR | (BGEZAL&&branch)) 
						 (LW | LB | LH | LBU | LHU | LRM | MFC0) ? `new_at_DM ://  
						 (ADDU | ADD | SUBU | SUB | AND | OR | XOR | NOR | SLT |
						  ADDIU | ORI | ANDI | XORI | LUI | SLTI | SLTIU | SLTU | ADDI |
						  SLL | SLLV | SRA | SRAV | SRL | SRLV | MFHI | MFLO )?`new_at_CAL :
						 0 ; //дʹ��Ϊ0�򲻿��ǣ������Ļ��Ͳ����ж�Ϊ������
	
endmodule
/*
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
 M_check = D_lwso && condition;
 // CU
 assign RFDst = // ...
               lwso ? (check===1'd1 ? 5'd31 : 5'd0) : // ע�ⲻ��ֱ��һ�� check, ��д�Ļ�ֱ��0�� д�Ļ�����31
               5'd0;
����Ҫע���һ���ǣ�������õ���ͳһ CU ��д������ô�����һ�����⣺check �ź�ֻ���� M �����롣���ʱ���� E ���� CU ��������ź��ǲ���̬ x�������ᵼ�� RFDst �źų������������������д���� check===1'd1�����������ų� x �������
*/