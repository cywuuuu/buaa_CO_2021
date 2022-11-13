`timescale 1ns / 1ps
`include "const.v"
`default_nettype wire

module ALU(
	input [31:0] A,
	input [31:0] B,
	input [4:0] shamt,
	input [4:0] ALU_op,
	input ov_en,
	input adel_en,
	input ades_en,
	output reg [31:0] C,
	output ov,
	output adel,
	output ades
	);
	
	reg [31:0] res;
	integer i;
	
	always @(*) begin
		case(ALU_op)
			`ALU_add:	C = A + B;
			`ALU_sub:	C = A - B;
			`ALU_and:	C = A&B;
			`ALU_or:		C = A|B;
			`ALU_xor:	C = A^B;
			`ALU_nor:	C = ~(A|B);
			//--------------------------
			`ALU_slt:	C = ($signed(A) < $signed(B))? 1:0;
			`ALU_sltu:	C = (A < B)? 1:0;
			//--------------------------
			`ALU_sll:	C = B<<shamt;
			`ALU_sllv:	C = B<<(A[4:0]);
			`ALU_srl:	C = B>>shamt;
			`ALU_srlv:	C = B>>(A[4:0]);
			`ALU_sra:	C = $signed($signed(B)>>>shamt);
			`ALU_srav:	C = $signed($signed(B)>>>(A[4:0]));
			//--------------------------
			`ALU_clo: begin
				res = 0;
				for(i=31;(A[i]&&i>=0);i=i-1)res = res + 1;
				C = res;
			end
			`ALU_clz: begin
				res = 0;
				for(i=31;(A[i]==0&&i>=0);i=i-1)res = res + 1;
				C = res;
			end
			default: C = 0;
		endcase
	end
	
	wire [32:0] A_ex = {A[31], A}, B_ex = {B[31], B};
	wire [32:0] temp_add = A_ex + B_ex, temp_sub = A_ex - B_ex;
	
	wire overflow_add = ((ALU_op==`ALU_add)&&(temp_add[32]!=temp_add[31]));
	wire overflow_sub = ((ALU_op==`ALU_sub)&&(temp_sub[32]!=temp_sub[31]));
	
	assign ov	= ov_en && (overflow_add||overflow_sub);
	assign adel	= adel_en && overflow_add;
	assign ades	= ades_en && overflow_add;
								
endmodule
