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
`define op_lhu 6'b100101
`define op_lh 6'b100001
`define op_lb 6'b100000
`define op_sh 6'b101001
`define op_sb 6'b101000
// funct
`define func_addu 6'b100001
`define func_subu 6'b100011
`define func_and 6'b100100
`define func_or 6'b100101
`define func_sll 6'b000000
`define func_sllv 6'b000100
`define func_slt 6'b101010
`define func_jr 6'b001000
`define func_jalr 6'b001001

// sel A3 #reg_dst
`define sel_rd 3'b000   // R_rd, jalr 毕竟Rtpye, A3 = rd
`define sel_rt 3'b001	// I_rt 
`define sel_31 3'b010 	// jal link A3 = 31
// sel WD #which_to_reg
`define sel_PC4  3'b000 //jal, jalr link WD = PC + 4
`define sel_res  3'b001 //包括了lui等Rtype, I type 的运算结果
`define sel_dm   3'b010 // lw
// sel ALU_srcB
`define sel_RD2   2'b00
`define sel_imm32 2'b01

//NPCop
`define NPCop_PC4 3'b000
`define NPCop_J 	3'b001
`define NPCop_B 	3'b010
`define NPCop_JR 	3'b011
//sign?ext
`define ext_zero 1'b0
`define ext_sign 1'b1
`define DM_SIZE 1024
`define DM_HIGH 11
//LS_op;
`define LS_w 2'b00
`define LS_h 2'b01
`define LS_b 2'b10

`define IM_SIZE 1024	 
`define IM_HIGH 11

`define PC_default 32'h0000_3000