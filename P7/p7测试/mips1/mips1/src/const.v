`default_nettype none

//Instr: func&opcode
`define op_sp		6'b000000
`define op_sp2		6'b011100
`define op_regimm	6'b000001
`define op_addi	6'b001000
`define op_addiu	6'b001001
`define op_andi	6'b001100
`define op_beq		6'b000100
`define op_bgtz	6'b000111
`define op_blez	6'b000110
`define op_bne		6'b000101
`define op_j		6'b000010 
`define op_jal		6'b000011
`define op_lb		6'b100000
`define op_lbu		6'b100100
`define op_lh		6'b100001
`define op_lhu		6'b100101
`define op_lui		6'b001111
`define op_lw		6'b100011
`define op_lb		6'b100000
`define op_ori		6'b001101
`define op_slti	6'b001010
`define op_sltiu	6'b001011
`define op_sw		6'b101011
`define op_sh		6'b101001
`define op_sb		6'b101000
`define op_xori	6'b001110
`define op_bmgezalr 6'b111111
`define op_bmltzalr 6'b111110

`define rt_bgez		5'b00001
`define rt_bgezal		5'b10001
`define rt_bltz		5'b00000
`define rt_bltzal		5'b10000
`define rt_bltzall	5'b10010
`define rt_bltzl		5'b00010

`define func_add   6'b100000
`define func_addu  6'b100001
`define func_and   6'b100100
`define func_clo	 6'b100001
`define func_clz	 6'b100000
`define func_div   6'b011010
`define func_divu  6'b011011
`define func_jalr  6'b001001
`define func_jr    6'b001000
`define func_movn	 6'b001011
`define func_movz	 6'b001010
`define func_mfhi  6'b010000
`define func_mflo  6'b010010
`define func_mthi  6'b010001
`define func_mtlo  6'b010011
`define func_mult  6'b011000
`define func_multu 6'b011001
`define func_mul	 6'b000010
`define func_madd	 6'b000000
`define func_maddu 6'b000001
`define func_msub	 6'b000100
`define func_msubu 6'b000101
`define func_nor   6'b100111
`define func_or    6'b100101
`define func_sll   6'b000000
`define func_sllv  6'b000100
`define func_slt   6'b101010
`define func_sltu  6'b101011
`define func_sra   6'b000011
`define func_srav  6'b000111
`define func_srl   6'b000010
`define func_srlv  6'b000110
`define func_sub   6'b100010
`define func_subu  6'b100011
`define func_xor   6'b100110
`define func_bgezalr 6'b111001
`define func_bltzalr 6'b111000

`define op_eret	32'b010000_1000_0000_0000_0000_0000_011000
`define op_mtc0	11'b010000_00100
`define op_mfc0	11'b010000_00000
// ALU
`define ALU_add	5'd0
`define ALU_sub	5'd1
`define ALU_sll	5'd2
`define ALU_srl	5'd3
`define ALU_or		5'd4
`define ALU_and	5'd5
`define ALU_xor	5'd6
`define ALU_nor	5'd7
`define ALU_slt	5'd8
`define ALU_sltu	5'd9
`define ALU_sra	5'd10
`define ALU_sllv	5'd11
`define ALU_srlv	5'd12
`define ALU_srav	5'd13
`define ALU_clo	5'd14
`define ALU_clz	5'd15
//MDU
`define MDU_mult	5'd0
`define MDU_multu	5'd1
`define MDU_div	5'd2
`define MDU_divu	5'd3
`define MDU_mfhi	5'd4
`define MDU_mflo	5'd5
`define MDU_mthi	5'd6
`define MDU_mtlo	5'd7
`define MDU_madd	5'd8
`define MDU_maddu	5'd9
`define MDU_msub	5'd10
`define MDU_msubu	5'd11
`define MDU_mul	5'd12
`define MDU_err	5'd31
//NPC
`define NPC_default	3'd0
`define NPC_branch	3'd1
`define NPC_j			3'd2
`define NPC_jr			3'd3
`define NPC_branchlr	3'd4
//EXT
`define EXT_unsigned	3'd0
`define EXT_signed	3'd1
`define EXT_lui		3'd2
//DM
`define DM_w	3'd0
`define DM_h	3'd1
`define DM_hu	3'd2
`define DM_b	3'd3
`define DM_bu	3'd4
`define DM_err	3'd5
//RF_A3
`define RF_A3_rt	3'd0
`define RF_A3_rd	3'd1
`define RF_A3_31	3'd2
`define RF_A3_err	3'd7
//RF_WD
`define RF_WD_ALU	5'd0
`define RF_WD_DM	5'd1
`define RF_WD_PC8	5'd2
`define RF_WD_EXT	5'd3
`define RF_WD_RS	5'd4
`define RF_WD_MDU	5'd5
`define RF_WD_CP0 5'd6
`define RF_WD_err	5'd7
//ALU_B
`define ALU_RD2	3'd0
`define ALU_EXT	3'd1
//CHK
`define CHK_mgez	3'd0
`define CHK_mltz	3'd1
`define CHK_err	3'd7
//CMP
`define CMP_eq		5'd0
`define CMP_ltz	5'd1
`define CMP_lez	5'd2
`define CMP_gtz	5'd3
`define CMP_gez	5'd4
`define CMP_ne		5'd5
`define CMP_rtez	5'd6
`define CMP_rtnez	5'd7
`define CMP_err	5'd31
//EXC
`define EXC_int	5'd0
`define EXC_adel	5'd4
`define EXC_ades	5'd5
`define EXC_ri		5'd10
`define EXC_ov		5'd12
`define EXC_err	5'd0
//ADDR
`define ADDR_IMs	32'h3000
`define ADDR_IMt	32'h6fff
`define ADDR_DMs	32'h0
`define ADDR_DMt	32'h2fff
`define ADDR_T0s	32'h7f00
`define ADDR_T0t	32'h7f0b
`define ADDR_T1s	32'h7f10
`define ADDR_T1t	32'h7f1b