`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: []
// Engineer: 
// 
// Create Date:    13:41:14 12/08/2021 
// Design Name: 
// Module Name:    CP0 
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
`define IM SR[15:10]
`define EXL SR[1]
`define IE SR[0]
`define BD Cause[31]
`define IP Cause[15:10]
`define exc_code_reg Cause[6:2] 
module CP0(
	 // R&W like grf,to change EPC
    input [4:0] A,
    input [31:0] WD,
    input WE,
    output [31:0] RD,	 
	 //detect interrupt 
    input [6:2] exc_code,
    input [7:2] HW_int,

	 //save if it is for EPC
    input [31:0] PC,
    input BD,
	 //epc reg out
    output [31:0] EPC_RD,
	 //when detect exc or int, the pipeline need change
    output int_exc_req,
	 output intt_req,
	 input EXL_clr, //excp return
    input clk,
    input reset
    );

	reg [31:0] SR;
	reg [31:0] Cause; 
	reg [31:0] EPC; 
	reg [31:0] PrID = 666;
	
	wire int_req = |(HW_int[7:2] & `IM) && `IE && (!(`EXL));//HW_IP & IM， &上掩码才是真中断源
	wire exc_req = (|exc_code[6:2]) && (!(`EXL));
	assign intt_req = HW_int[4] && SR[12] && `IE && (!(`EXL));
	assign int_exc_req = (int_req | exc_req | intt_req) ;
	//12
	assign RD = (A == 12) ? SR : 
					(A == 13) ? Cause : 
					(A == 14) ? EPC :
					(A == 15) ? PrID :
					0;
	
	assign EPC_RD = EPC;//{EPC[31:2], 2'b00};
	
	always @ (posedge clk)begin
		if(reset)begin
			SR <= 0;
			Cause <= 0;
			EPC <= 0;
			PrID <= 666;
		end
		else begin
			`IP <= HW_int[7:2]; //实时检测中断
			if(int_exc_req)begin
					`exc_code_reg <= int_req ? 5'b0 : exc_code;
					`BD <= BD;
					`EXL <= 1;
					EPC <= BD ? (PC-4) : PC ; 
			end	

			else if(EXL_clr)begin//eret时， cp0的寄存器除了exl解除中断态以外，没改变
				`EXL <= 0;//外面清0
			end
			
			else if(WE)begin//写入WE当且仅当 mtc0
				if(A == 12) begin
					SR <= WD; 
				end
				//else if(A == `cause_addr) read only
				/*else if(A == 13) begin
					Cause <= WD;
				end*/
				else if(A == 14) begin
					EPC <= WD;
				end
			end
			

		end

	end
	
	

endmodule
