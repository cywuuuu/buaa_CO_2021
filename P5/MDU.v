`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    16:32:27 11/27/2021 
// Design Name: 
// Module Name:    MDU 
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
module MDU(
    input start,    
	 input [31:0] D1,
    input [31:0] D2,
    input [4:0] MDU_op,
    input clk,
    input reset,
    output real_busy,
    output [31:0] MDU_out
    );
	 reg [31:0] cnt, HI_res, LO_res, HI, LO;
	 reg busy;
	 
	assign MDU_out = (MDU_op == `MDU_mflo) ?  LO : 
						  (MDU_op == `MDU_mfhi) ?  HI : 0;
	initial begin
			cnt <= 0;
			HI <= 0;
			LO <= 0;
			HI_res <= 0;
			LO_res <= 0;
			busy <= 0;
	end
	always @ (posedge clk)begin
		if(reset) begin
			cnt <= 0;
			HI <= 0;
			LO <= 0;
			HI_res <= 0;
			LO_res <= 0;
			busy <= 0;
		end
		else if(start)begin
				case(MDU_op)
				`MDU_mult: begin
					{HI_res, LO_res} <= $signed(D1)*$signed(D2);
					cnt <= 3;
					busy <= 1;
				end
				`MDU_multu: begin
					{HI_res, LO_res} <= D1 * D2;
					cnt <= 3;
					busy <= 1;
				end
				`MDU_div: begin
					HI_res <= $signed(D1)%$signed(D2);
					LO_res <= $signed(D1)/$signed(D2);
					cnt <= 8;
					busy <= 1;
				end 
				`MDU_divu:begin
					HI_res <= D1 % D2;
					LO_res <= D1 / D2;
					cnt <= 8;
					busy <= 1;
				end
				//{HI,LO} + $signed($signed(64'd0) + $signed(rs) * $signed(rt))
				//{HI,LO} + $signed({{32{rs[31]}}, rs[31:0]} * $signed({{32{rt[31]}}, rt[31:0]}));
			endcase 
			//此后 start就随着流水自动变成0了
		end
		else if(start == 0 && busy == 1)begin
			if($signed(cnt) >= $signed(0))begin
				cnt <= cnt - 1;
				busy <= 1;
			end
			else begin
				busy <= 0;
				HI <= HI_res;
				LO <= LO_res;
			end
		end
		else begin//start = 0, busy = 0
			if(MDU_op == `MDU_mthi) HI <= D1;
			else if(MDU_op == `MDU_mtlo) LO <= D1;
		end
	end
	assign real_busy = busy | start; 
endmodule
