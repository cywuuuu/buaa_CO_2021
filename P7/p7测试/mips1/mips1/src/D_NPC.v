`timescale 1ns / 1ps
`include "const.v"
`default_nettype wire

module NPC(
	input [31:0] F_PC,
	input [31:0] D_PC,
	input [31:0] EPC,
	input [31:0] RS,
	input [31:0] RT,
	input [25:0] imm26,
	input [2:0] NPC_op,
	input cmp,
	input req,
	input D_eret,
	output [31:0] NPC,
	output [31:0] PC8
	);
	
	reg [31:0] npc;
	
	//working on NPC:: consider from stage F
	//in state_F, see if previous instr will branch or jump
	//here, NPC_op come from stage D
	always @(*) begin
		case(NPC_op)
			`NPC_branch: begin
				if(cmp) npc = D_PC + 4 + {{14{imm26[15]}}, imm26[15:0], 2'b00};
				else npc = PC8;
			end
			`NPC_branchlr: begin
				if(cmp) npc = RT;
				else npc = PC8;
			end
			`NPC_j: npc = {D_PC[31:28], imm26, 2'b00};
			`NPC_jr: npc = RS;
			`NPC_default: npc = F_PC + 4;
			default: npc = F_PC + 4;
		endcase
	end
	
	assign PC8 = D_PC + 8;
	assign NPC = (req)? 32'h0000_4180: 
					 (D_eret)? EPC+4: npc;
	
endmodule