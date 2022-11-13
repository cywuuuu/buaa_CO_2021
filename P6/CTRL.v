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
	 output sign,//每个指令确定后控制信号就都定了
	 output Tuse_rs_0,
	 output Tuse_rs_1,
	 output Tuse_rt_0,
	 output Tuse_rt_1,
	 output Tuse_rt_2,//每个指令固有的属性， 丢给forward unit来控制转发
	 output [2:0] new_at,//每个指令确定后，产生在哪里确定
	 output [4:0]A1,
	 output [4:0]A2,
	 output [4:0]A3//每个指令确定， 他们的操作对象确定
    );
	/*
	{addu, subu, ori, lw, sw, beq, lui, jal, jr,nop}
	*/
	//功能区
	wire [5:0] opcode = instr[31:26];
	wire [5:0] func = instr[5:0];
	wire [5:0] rt = instr[20:16];
	wire AND, OR, SLLV, SLL, SRL, SRA, SRLV, SRAV, SLT, JR, JALR, J, JAL, ADDIU, ADDU, SUBU, ADDI, 
	ORI, LUI, SLTI, SW, LW, BEQ, BLEZ, LHU, RTYPE, ANDI, SH, SB, LH, LB, LBU, ADD, SUB; //加指令point2
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
	

	//加指令point3
	//加指令slti,lui
	/*
	`define fwd_src_ALUres 3'b011
	`define fwd_src_DM_RD 3'b010
	`define fwd_src_PC8 3'b001
	*/
	//写寄存器的指令要加一下这里
	assign fwd_src_sel =  	( LW | LH | LB | LBU | LHU) ? `fwd_src_DM_RD : 
									(JAL | JALR) ? `fwd_src_PC8 : 
									`fwd_src_CALres ;// CAL代指 ALU,MDU

	assign CAL_sel = (MFHI | MFLO) ? `sel_MDU : `sel_ALU;  
	assign start = MULT | MULTU | DIV | DIVU ;
	////以下为加指令point4, 注意接口改变扩充和搭线哦, 注意新加输出的控制
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
								 (JAL | JALR) ? `sel_PC4 :								 // 生成PC+4但不一定用
								 `sel_res;
								 

	assign sign = (ORI | ANDI | XORI) ? `ext_zero : `ext_sign;
	
	// ALU_src, B = imm or GPRrt 即 RD2
	/*
	// sel ALU_srcB
	`define sel_RD2   2'b00
	`define sel_imm32 2'b01
	*/
	assign ALU_src = ( ORI | XORI | ANDI| LUI | SLTI | SLTIU | ADDIU | ADDI | 
							 LW | SW | LH | LB | SH | SB | LHU | LBU) ? `sel_imm32 : 
						  `sel_RD2;
						  					  
	wire branch, j, jr;
	//判断是否跳转
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
	assign A3 = (RTYPE)?instr[15:11] : //mflo,mfhi都是R,写rd
					(ORI | LUI | SLTI | SLTIU | LW | LB | LH | LBU | LHU | ADDIU | ANDI | XORI | ADDI) ? instr[20:16] :
					(JAL || JALR) ? 31 :// || (BGEZAL&&branch)
					0;//写寄存器的才有A3!=0, 不写的统统A3=0
					
	//////////////////////stall_signal/////////////////////////
	//啥时候用寄存器， 不用的不写 d,e,m
	assign Tuse_rs_0 = JR | JALR | BEQ | BNE | BLEZ | BGTZ | BLTZ | BGEZ;//JR | JALR | BEQ | BLEZ | BGEZAL;
	assign Tuse_rs_1 = AND | OR | NOR | XOR |ADDIU | ADDU | ADD | SUB | SUBU | SW | LW | SH | SB| LH | LB | LBU | LHU |
							 MTHI | MTLO | MULT | MULTU | DIV | DIVU | ORI | ANDI | XORI | ADDI | 
							 SLLV | SRAV | SRLV | SLT | SLTU | SLTI | SLTIU;
	assign Tuse_rt_0 = BEQ | BNE ;
	assign Tuse_rt_1 = AND | OR | NOR | XOR | ADDU | SUBU | ADD | SUB | SLL | SLLV | SRA | SRAV | 
							 SRL | SRLV | SLT | SLTU | MULT | MULTU | DIV | DIVU ;
	assign Tuse_rt_2 = SH| SB| SW;
	//要对寄存器GRF[A3]写入的结果产生在哪里

	assign new_at = (JAL | JALR) ? `new_at_PC : // (JAL | JALR | (BGEZAL&&branch)) 
						 (LW | LB | LH | LBU | LHU) ? `new_at_DM : 
						 (ADDU | ADD | SUBU | SUB | AND | OR | XOR | NOR | SLT |
						  ADDIU | ORI | ANDI | XORI | LUI | SLTI | SLTIU | SLTU | ADDI |
						  SLL | SLLV | SRA | SRAV | SRL | SRLV | MFHI | MFLO )?`new_at_CAL :
						 0 ; //写使能为0则不考虑，这样的话就不会判断为阻塞了
	
endmodule
/*
这里就简单讲讲 P5 的套路吧。

首先课上的三条指令：计算 + 跳转 + 存储。

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
 wire stall_rs_e = (TuseRS < TnewE) && D_rs_addr && (D_lwso ? D_rs_addr == 5'd31 : A1 D_rs_addr == E_RFDstA3);
 // lrm
 wire stall_rs_e = (TuseRS < TnewE) && D_rs_addr && (D_lrm ? D_rs_addr : D_rs_addr == E_RFDst);
在 CU 中的写法则与条件跳转类似。


 // lwso
 M_check = D_lwso && condition;
 // CU
 assign RFDst = // ...
               lwso ? (check===1'd1 ? 5'd31 : 5'd0) : // 注意不是直接一个 check, 不写的话直接0， 写的话特判31
               5'd0;
这里要注意的一点是，如果你用的是统一 CU 的写法，那么会出现一个问题：check 信号只有在 M 级传入。这个时候在 E 级的 CU 里面这个信号是不定态 x，这样会导致 RFDst 信号出锅。所以我们这里的写法是 check===1'd1，这样可以排除 x 的情况。
*/