`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    10:02:58 11/01/2021 
// Design Name: 
// Module Name:    NPC 
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
`include "./header.v" 
module NPC(
    input [31:0] F_PC,
	 input [31:0] D_PC,
    input [25:0] imm26,
	 input [2:0] NPCop,
    input [31:0] jreg,
	 input int_exc_req, 
    output reg[31:0] NPC
    );
	wire [31:0] D_PC4 = D_PC + 4;
	always @(*)begin
		if(int_exc_req)begin//优先级要高！ppt上说的
			NPC = `PC_kernel; 
		end//入kernel, 采用慢切， 清零DMEW（实际消除FDME当下的指令）,
			// F下个周期变成NPC = PC_kernel，往后传
		//退kernel直接D_iseret, 快切F瞬间变成EPC，防止eret延迟出问题 , 
		else if(NPCop == `NPCop_J) begin
			NPC = {D_PC4[31:28], imm26, 2'b00}; // jump
		end
		else if (NPCop == `NPCop_JR)begin // jump register
			NPC = jreg;
		end
		else if (NPCop == `NPCop_B)begin// branch type
			NPC = D_PC + 4 + {{14{imm26[15]}}, imm26[15:0], 2'b00};
		end
		else NPC = F_PC + 4;
		//有待补充
		//异常处理
	end
	
	
endmodule
