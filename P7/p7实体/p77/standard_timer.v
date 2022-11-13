`timescale 1ns / 1ps
`define IDLE 2'b00
`define LOAD 2'b01
`define CNT  2'b10
`define INT  2'b11

`define ctrl   mem[0]//控制寄存器
`define preset mem[1]//初值寄存器
`define count  mem[2]//计数寄存器
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:43:39 12/28/2017 
// Design Name: 
// Module Name:    TC 
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
module TC(
    input clk,
    input reset,
    input [31:2] Addr,
    input WE,
    input [31:0] Din,
    output [31:0] Dout,
    output IRQ
    );

	reg [1:0] state;
	reg [31:0] mem [2:0];
	
	reg _IRQ;///模式0下计数器寄存器值为0
	assign IRQ = `ctrl[3] & _IRQ;//且中断允许，产生中断请求
	
	assign Dout = mem[Addr[3:2]];//输出which寄存器
	//对于addr处于00-0b的地址我们只取 [3:2] 因为
	// [00]00, [01]00, [10]00, 分别代表了三个4byte寄存器的初始地址选择
	wire [31:0] load = Addr[3:2] == 0 ? {28'h0, Din[3:0]} : Din;
	// 读取ctrl, 00寄存器未定义位被忽略,
	// 此为写入ctrl寄存器时，未定义位31：4被忽略
	/*
		Reserved 31:4 保留 － 0
		IM 3
		中断屏蔽
		0：禁止中断
		1：允许中断
		///////
		Mode 2:1
		模式选择
		00：方式 0
		01：方式 1
		10：未定义
		11：未定义
		///////
		Enable 0
		计数器使能
		0：停止计数
		1：允许计数
		R/W 
	*/
	integer i;
	always @(posedge clk) begin
		if(reset) begin
			state <= 0; 
			for(i = 0; i < 3; i = i+1) mem[i] <= 0;
			_IRQ <= 0;
		end
		else if(WE) begin
			// $display("%d@: *%h <= %h", $time, {Addr, 2'b00}, load);
			mem[Addr[3:2]] <= load;//写入寄存器
		end
		else begin
			case(state)
				`IDLE : if(`ctrl[0]) begin//ctrl[0] enable 计数
					state <= `LOAD;
					_IRQ <= 1'b0;//还没中断
				end
				`LOAD : begin
					`count <= `preset;//开始存入初值
					state <= `CNT;
				end
				`CNT  : 
					if(`ctrl[0]) begin//enable = 1计数开始
						if(`count > 1) `count <= `count-1;
						else begin//午时已到
							`count <= 0;//清零计数寄存器
							state <= `INT;
							_IRQ <= 1'b1;//开始中断，并判断掩码
						end
					end
					else state <= `IDLE;//突然enable停止计数，外界出了状况， 滚回idle
				default : begin
					if(`ctrl[2:1] == 2'b00) `ctrl[0] <= 1'b0;//中断态 且模式0 停止计数，并且一直中断
					else _IRQ <= 1'b0;//模式1 回到初值
					state <= `IDLE;
				end
			endcase
		end
	end

endmodule
