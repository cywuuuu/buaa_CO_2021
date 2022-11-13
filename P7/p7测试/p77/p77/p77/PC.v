`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    08:52:40 10/25/2021 
// Design Name: 
// Module Name:    PC 
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
module PC(
    input clk,
    input [31:0] NPC,
	 input [31:0] EPC,
	 input D_iseret,
	 output exc_AdEL, 
    output [31:0] PC,
    input reset,
	 input en
    );
//测试数据中可能出现 eret 指令后紧跟另一条非 nop 指令的情况，你的设计应该保证 eret 的后续指令不被执行。
// eret 我们使其阻塞， 同时清空延迟槽

//发生AdEL 时， 该指令直接变成0，其他不变; 其PC接着流水，给后续处理
	 initial begin
		fake_PC <= `PC_default;
	 end
	 reg[31:0] fake_PC;
	 //快速切换，省插入nop了， 直接换成
	 assign PC = D_iseret ? EPC : fake_PC; 
	 always@(posedge clk)begin
		if(reset)begin
			fake_PC <= `PC_default;
		end
		else if(en)begin
			fake_PC <= NPC;
		end
	end//我们忽略掉eret到EPC可能产生的异常？eret的EPC应该不会异常
	assign exc_AdEL = ((|PC[1:0]) | (PC < `im_addr_begin) | (PC > `im_addr_end)) && (~D_iseret);  //&& ~D_iseret; //最后结束了，eret刚好
endmodule
