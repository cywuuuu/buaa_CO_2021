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
// 1. 改ctrl，stall,forward..
// 2. 改数据通路，别光改了信号了啊，结果忘记扩充通路了就不好了
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
	 output sign,//每个指令确定后控制信号就都定了
	 output Tuse_rs_0,
	 output Tuse_rs_1,
	 output Tuse_rt_0,
	 output Tuse_rt_1,
	 output Tuse_rt_2,//每个指令固有的属性， 丢给forward unit来控制转发
	 output [2:0] new_at,//每个指令确定后，产生在哪里确定
	 output [4:0]A1,
	 output [4:0]A2,
	 output [4:0]A3,//每个指令确定， 他们的操作对象确定
	 output null_slot, 
	 output islrm, 
	 output has_DB, //D
	 output ismtc0,//ALL eret的阻塞需要检测写CP0 
	 output ismfc0,//写grf,相当于new at dm, 用的是普通转发
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
	//功能区
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
	//加指令point3
	//加指令slti,lui
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
	(opcode == 0 && func == 0));//加这里syscall
	
	assign exc_Ov = (ADDI | ADD | SUB) && overflow;//
	
	wire not_align = ((LW|SW) && (|m_data_addr[1:0])) || 
					 ((LH|LHU|SH) && (m_data_addr[0])); 	
	wire ls_tc_not_word = (LH|LHU|LB|LBU|SH|SB) && (m_data_addr >= `dev0_addr_begin); 
	

	//取 Timer 中cnt寄存器的半字，byte mem[2]
	

	/*
		((m_data_addr >= `dev0_addr_begin && m_data_addr <= `dev0_addr_end) || 
	 (m_data_addr >= `dev1_addr_begin && m_data_addr <= `dev1_addr_end)); 
	*/
	//写入异常是前提， 写不写是后果
	wire save_tc_cnt =  
							  ((m_data_addr >= 32'h0000_7f08 && m_data_addr <= 32'h0000_7f0b) || 
								(m_data_addr >= 32'h0000_7f18 && m_data_addr <= 32'h0000_7f1b));
	wire DM_overflow = (LW|LH|LB|LBU|LHU|SB|SH|SW) && overflow; 	
	wire not_in_range = 	~((m_data_addr <= `dm_addr_end && m_data_addr >= `dm_addr_begin ) ||
							(m_data_addr >= `dev0_addr_begin && m_data_addr <= `dev0_addr_end) ||
							(m_data_addr >= `dev1_addr_begin && m_data_addr <= `dev1_addr_end)); 	
	assign exc_AdEL = (LW|LH|LB|LBU|LHU) && ((not_in_range) | not_align | ls_tc_not_word | DM_overflow ); 
	assign exc_AdES = (SB|SH|SW)&& ((not_in_range) | not_align | ls_tc_not_word | DM_overflow | save_tc_cnt); 
	//wire [1:0]bytt = CAL_res[1:0];//在E级之后不为z
	//wire condition_LHS = (bytt == 0 || bytt == 2);
	
	assign CAL_sel = (MFHI | MFLO) ? `sel_MDU : `sel_ALU;  //md++
	assign start = MULT | MULTU | DIV | DIVU ; //md++
	////以下为加指令point4, 注意接口改变扩充和搭线哦, 注意新加输出的控制
	
	assign LS_op = (LW | SW ) ? `LS_w : 
						(LH | SH | LHU) ? `LS_h :
						(LB | SB | LBU) ? `LS_b : 
						`LS_nothing;
	assign load_type = LW | LH | LB | LHU | LBU; 
	assign save_type = SW | SH | SB; 
	assign DM_sign = (LB | LH) ? 1 : 0;
	
	//条件写 OP&&condition===
	assign reg_write = AND | OR | XOR | NOR | SLT | SLTU | SLTIU | SLTI | SLLV | SLL | SRL | SRA | SRLV | SRAV |LW | MFC0 | 
	| LH | LB | LBU | LHU | ADD | SUB | ADDU | SUBU | JAL | JALR | ADDI | ADDIU | ANDI | ORI | XORI | LUI | MFHI |MFLO | BGEZALL | LRM;//BGEZAL&&branch


	assign reg_dst = (RTYPE) 					? `sel_rd   	: // mfhi, mflo jalr is rtype 
						  (JAL | BGEZALL) 	 	? `sel_31 		:
						  (LRM) 						? `sel_DM_RD 	:
							         `sel_rt;

	
	assign which_to_reg = (LW | LH | LB | LBU | LHU) ? `sel_dm : 
								 (JAL | JALR | BGEZALL) ? `sel_PC4 :								 // 生成PC+4但不一定用
								 (LRM) ? `sel_grfrt :
								 (MFC0) ? `sel_CP0 :
								 `sel_res;
								 

	assign sign = (ORI | ANDI | XORI) ? `ext_zero : `ext_sign;
	

	assign ALU_src = ( ORI | XORI | ANDI| LUI | SLTI | SLTIU | ADDIU | ADDI | 
							 LW | SW | LH | LB | SH | SB | LHU | LBU | LRM) ? `sel_imm32 : 
						  `sel_RD2;
						  					  
	wire branch, j, jr;
	//判断是否跳转
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
	assign A1 = instr[25:21];//rs, 不必担心冲突而stall, 不用不写tuse即可， 不必担心转发， 转发了也不用
	assign A2 = instr[20:16];//rt
	//条件写则条件转发 
	assign A3 = (RTYPE)?instr[15:11] : //mflo,mfhi都是R,写rd
					(ORI | MFC0 | LUI | SLTI | SLTIU | LW | LB | LH | LBU | LHU | ADDIU | ANDI | XORI | ADDI ) ? instr[20:16] :
					(JAL || JALR || BGEZALL) ? 31 :// || (BGEZAL&&branch)
					//OP ? ((condition === ) ? reg1 : reg2) :
					(LRM) ? ((DM_RD[4:0] !== 5'bzzzzz) ? DM_RD[4:0] : 0): //到了最后DM_RD才不是zz,否则A3就是0
					0;//写寄存器的才有A3!=0, 不写的统统A3=0
	assign mtc0_dst = (MTC0) ? instr[15:11]:0;
	//写寄存器的指令要加一下这里，备好数据
	assign fwd_src_sel =  	( LW | LH | LB | LBU | LHU) ? `fwd_src_DM_RD : 
									(JAL | JALR | BGEZALL) ? `fwd_src_PC8 : 
									(LRM) ? `fwd_src_RD2 :
									(MFC0) ? `fwd_src_CP0 : 
									`fwd_src_CALres ;// CAL代指 ALU,MDU

	//////////////////////stall_signal/////////////////////////
	//啥时候用寄存器， 不用的不写, d,e,m, 用之前必须转发到，否则stall
	assign Tuse_rs_0 = JR | JALR | BEQ | BNE | BLEZ | BGTZ | BLTZ | BGEZ | BGEZALL;//JR | JALR | BEQ | BLEZ | BGEZAL;
	assign Tuse_rs_1 = AND | OR | NOR | XOR |ADDIU | ADDU | ADD | SUB | SUBU | SW | LW | SH | SB| LH | LB | LBU | LHU |
							 MTHI | MTLO | MULT | MULTU | DIV | DIVU | ORI | ANDI | XORI | ADDI | LRM |
							 SLLV | SRAV | SRLV | SLT | SLTU | SLTI | SLTIU ;
	assign Tuse_rt_0 = BEQ | BNE ;
	assign Tuse_rt_1 = AND | OR | NOR | XOR | ADDU | SUBU | ADD | SUB | SLL | SLLV | SRA | SRAV | 
							 SRL | SRLV | SLT | SLTU | MULT | MULTU | DIV | DIVU ;
	assign Tuse_rt_2 = SH| SB| SW | MTC0;
	//要对寄存器GRF[A3]写入的结果产生在哪里
	
	assign new_at = (JAL | JALR | BGEZALL) ? `new_at_PC : // (JAL | JALR | (BGEZAL&&branch)) 
						 (LW | LB | LH | LBU | LHU | LRM | MFC0) ? `new_at_DM ://  
						 (ADDU | ADD | SUBU | SUB | AND | OR | XOR | NOR | SLT |
						  ADDIU | ORI | ANDI | XORI | LUI | SLTI | SLTIU | SLTU | ADDI |
						  SLL | SLLV | SRA | SRAV | SRL | SRLV | MFHI | MFLO )?`new_at_CAL :
						 0 ; //写使能为0则不考虑，这样的话就不会判断为阻塞了
	
endmodule
/*
计算绝对是最简单的，重点在于你的写法。如果你用 always@(*) 那么问题不大。但是如果你用的是 assign 那么最好使用 function 来实现计算指令。
跳转一般也不难，一般是条件跳转 + 条件写。 跳转指令一个好处在于它是在 D 级决定是否跳转的，也就是说在 D 级你可以获得全部的正确信息（相反如果是类似于 lwso 这种，你必须要读出 DM 的值才能决定怎么做）。所以我们的方案是 D 级生成一个 D_check 信号然后流水它。然后每一级根据这个信号判断写入地址/写入值之类的。

 // 检测信号
 D_check = D_bgezalc & D_b_jump;
 // CU
 assign RFDst = // ...
               bgezalc ? (check ? 5'd31 : 5'd0) :
               5'd0;
条件存储一般是最难的。 但是掌握了套路之后也还好。条件存储的特点是必须要到 M 级才知道要写啥，这就给转发之类的造成了困难，所以我们的策略是如果 D 级要读寄存器，而且新指令可能要写这个寄存器，那么就 stall。具体来说是这样的：


 // lwso
 M_check = D_lwso && condition;
 // CU
 assign RFDst = // ...
               lwso ? (check===1'd1 ? 5'd31 : 5'd0) : // 注意不是直接一个 check, 不写的话直接0， 写的话特判31
               5'd0;
这里要注意的一点是，如果你用的是统一 CU 的写法，那么会出现一个问题：check 信号只有在 M 级传入。这个时候在 E 级的 CU 里面这个信号是不定态 x，这样会导致 RFDst 信号出锅。所以我们这里的写法是 check===1'd1，这样可以排除 x 的情况。
*/