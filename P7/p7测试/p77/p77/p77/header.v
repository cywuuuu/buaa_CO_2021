`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    08:57:01 11/01/2021 
// Design Name: 
// Module Name:    header 
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
// ALU control
// define 不能; Syntax error near ";"
`define ALU_add 5'b00000
`define ALU_sub 5'b00001
`define ALU_and 5'b00010
`define ALU_or  5'b00011
`define ALU_sll 5'b00100
`define ALU_slt 5'b00101
`define ALU_lui 5'b00110
`define ALU_sla 5'b00111
`define ALU_sllv 5'b01000
`define ALU_xor 5'b01001
`define ALU_nor 5'b01010
`define ALU_srl 5'b01011
`define ALU_sra 5'b01100
`define ALU_srlv 5'b01101
`define ALU_srav 5'b01110
`define ALU_sltu 5'b01111

`define ALU_ovfl_L 2'b01
`define ALU_ovfl_CAL 2'b10
`define ALU_ovfl_S 2'b11
//MDU
`define MDU_mult  5'b00001
`define MDU_multu 5'b00010
`define MDU_div   5'b00011
`define MDU_divu  5'b00100
`define MDU_mfhi  5'b00101
`define MDU_mflo  5'b00110
`define MDU_mthi  5'b00111
`define MDU_mtlo  5'b01000
//ALU,MDU sel

//compare and zero
`define cmp_eq 2'b01
`define cmp_gt 2'b10
`define cmp_lt 2'b11
`define zero_eq 2'b01
`define zero_gt 2'b10
`define zero_lt 2'b11
// opcode
`define op_rtype 6'b000000
`define op_j 6'b000010
`define op_jal 6'b000011
`define op_addi 6'b001000
`define op_addiu 6'b001001
`define op_ori 6'b001101
`define op_lui 6'b001111
`define op_sw 6'b101011
`define op_lw 6'b100011
`define op_beq 6'b000100
`define op_blez 6'b000110
`define op_lhu 6'b100101
`define op_slti 6'b001010
`define op_andi 6'b001100
`define op_lh 6'b100001
`define op_lb 6'b100000
`define op_sh 6'b101001
`define op_sb 6'b101000
`define op_lbu 6'b100100
`define op_lhu 6'b100101
`define op_xori 6'b001110
`define op_sltiu 6'b001011
`define op_bne 6'b000101
`define op_bgtz 6'b000111
`define op_bltzbgez 6'b000001
`define op_bgezall 6'b000001
`define op_lrm 6'b111111
`define op_cp0 6'b010000
//rt
`define rt_bgez 5'b00001
`define rt_bltz 5'b00000
`define rt_bgezall 5'b10011
//rs 
`define rs_mfc0 5'b00000
`define rs_mtc0 5'b00100
// funct
`define func_addu 6'b100001
`define func_subu 6'b100011
`define func_and 6'b100100
`define func_or 6'b100101
`define func_xor 6'b100110
`define func_nor 6'b100111
`define func_sll 6'b000000
`define func_sllv 6'b000100
`define func_slt 6'b101010
`define func_jr 6'b001000
`define func_jalr 6'b001001
`define func_add 6'b100000
`define func_sub 6'b100010
`define func_srl 6'b000010
`define func_sra 6'b000011
`define func_sllv 6'b000100
`define func_srlv 6'b000110
`define func_srav 6'b000111
`define func_slt 6'b101010
`define func_sltu 6'b101011
`define func_mult 6'b011000
`define func_multu 6'b011001
`define func_div 6'b011010
`define func_divu 6'b011011
`define func_mult 6'b011000
`define func_multu 6'b011001
`define func_div 6'b011010
`define func_divu 6'b011011
`define func_mfhi 6'b010000
`define func_mflo 6'b010010
`define func_mthi 6'b010001
`define func_mtlo 6'b010011
`define func_eret 6'b011000

// sel A3 #reg_dst
`define sel_rd 3'b000   // R_rd, jalr 毕竟Rtpye, A3 = rd
`define sel_rt 3'b001	// I_rt 
`define sel_31 3'b010 	// jal link A3 = 31
`define sel_DM_RD 3'b011
// sel WD #which_to_reg
`define sel_PC4  3'b000 //jal, jalr link WD = PC + 4
`define sel_res  3'b001 //包括了lui等Rtype, I type 的运算结果
`define sel_dm   3'b010 // lw
`define sel_grfrt  3'b100
`define sel_CP0 3'b101
// sel ALU_srcB
`define sel_RD2   2'b00
`define sel_imm32 2'b01
// sel MDU, ALU
`define sel_MDU 1
`define sel_ALU 0
//NPCop
`define NPCop_PC4 3'b000
`define NPCop_J 	3'b001
`define NPCop_B 	3'b010
`define NPCop_JR 	3'b011
//sign?ext
`define ext_zero 1'b0
`define ext_sign 1'b1
`define DM_SIZE 4096
`define DM_HIGH 13
//LS_op;
`define LS_w 2'b11
`define LS_h 2'b01
`define LS_b 2'b10
`define LS_nothing 2'b00
//dext_op

`define IM_SIZE 5120
`define IM_HIGH 14
// new at
`define new_at_CAL 2
`define new_at_DM 3
`define new_at_PC 1
//PC
`define PC_default 32'h0000_3000
`define PC_kernel 32'h0000_4180

//M_fwd
`define M_RD2_fwd_W 2'b01//WtoM
//D_fwd
`define D_RD2_fwd_E 2'b11
`define D_RD2_fwd_M 2'b10
`define D_RD2_fwd_W 2'b01
`define D_RD1_fwd_E 2'b11
`define D_RD1_fwd_M 2'b10
`define D_RD1_fwd_W 2'b01//谨遵高老板
//E_fwd
`define E_RD2_fwd_M 2'b10
`define E_RD2_fwd_W 2'b01
`define E_RD1_fwd_M 2'b10
`define E_RD1_fwd_W 2'b01//谨遵高老板
//E_fwd_src
`define fwd_src_CP0 3'b101
`define fwd_src_RD2 3'b100
`define fwd_src_CALres 3'b011
`define fwd_src_DM_RD 3'b010
`define fwd_src_PC8 3'b001
// addr 
`define dm_addr_begin 32'h0000_0000
`define dm_addr_end 32'h0000_2fff

`define im_addr_begin 32'h0000_3000
`define im_addr_end 32'h0000_6fff
`define handler_begin 32'h0000_4180

`define dev0_addr_begin 32'h0000_7f00
`define dev0_addr_end 32'h0000_7f0b
`define dev1_addr_begin 32'h0000_7f10
`define dev1_addr_end 32'h0000_7f1b

`define sr_addr 12
`define cause_addr 13
`define epc_addr 14
`define prid_addr 15 
//exc
`define Int 0
`define AdEL 4
`define AdES 5
`define RI 10
`define Ov 12
`define nothing 0