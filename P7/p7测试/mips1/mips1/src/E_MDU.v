`timescale 1ns / 1ps
`include "const.v"
`default_nettype wire

module MDU(
	input [31:0] RS,
	input [31:0] RT,
	input [4:0] MDU_op,
	input MDU_en,
	input clk,
	input req,
	input reset,
	output [31:0] MDU_OUT,
	output MDU_busy
	);
	
	//*************Decode
	wire mult	= (MDU_op==`MDU_mult);
	wire multu	= (MDU_op==`MDU_multu);
	wire div		= (MDU_op==`MDU_div);
	wire divu	= (MDU_op==`MDU_divu);
	wire mfhi	= (MDU_op==`MDU_mfhi);
	wire mflo	= (MDU_op==`MDU_mflo);
	wire mthi	= (MDU_op==`MDU_mthi);
	wire mtlo	= (MDU_op==`MDU_mtlo);
	wire madd	= (MDU_op==`MDU_madd);
	wire maddu	= (MDU_op==`MDU_maddu);
	wire msub	= (MDU_op==`MDU_msub);
	wire msubu	= (MDU_op==`MDU_msubu);
	wire mul		= (MDU_op==`MDU_mul);
	wire mas		= madd|maddu|msub|msubu;
	
	wire start = mult|multu|div|divu|mas|(mul&&(!fzero));
	reg busy, fzero;
	reg [4:0] state;
	reg [31:0] hi, lo, temphi, templo, res_mul;
	
	initial begin
		state <= 0;
		busy <= 0;
		hi <= 0;
		lo <= 0;
		res_mul <= 0;
		fzero <= 0;
	end
	
	assign MDU_busy = start|busy;
	assign MDU_OUT = (mfhi)? hi:
						  (mflo)? lo:
						  (mul)? res_mul: 0;
						  
	always @(posedge clk) begin
		if(reset) begin
			state <= 0;
			busy <= 0;
			hi <= 0;
			lo <= 0;
			res_mul <= 0;
			fzero <= 0;
		end
		else if(!req) begin
			if(state==0) begin
				fzero <= 0;
				if(mthi) hi <= RS;
				else if(mtlo) lo <= RS;
				else if(mult|(mul&&(!fzero))) begin
					{temphi, templo} <= $signed(RS) * $signed(RT);
					busy <= 1;
					state <= 5;
				end
				else if(multu) begin
					{temphi, templo} <= RS*RT;
					busy <= 1;
					state <= 5;
				end
				else if(mas) begin
					if(madd){temphi, templo} <= {hi,lo} + $signed($signed(64'b0) + $signed(RS) * $signed(RT));
					if(msub){temphi, templo} <= {hi,lo} - $signed($signed(64'b0) + $signed(RS) * $signed(RT));
					if(maddu){temphi, templo} <= {hi,lo} + RS*RT;
					if(msubu){temphi, templo} <= {hi,lo} - RS*RT;
					busy <= 1;
					state <= 5;
				end
				else if(div) begin
					if(RT==0) {temphi, templo} <= {hi, lo};
					else begin
						temphi <= $signed(RS) % $signed(RT);
						templo <= $signed(RS) / $signed(RT);
					end
					busy <= 1;
					state <= 10;
				end
				else if(divu) begin
					temphi <= (RT)? (RS%RT): hi;
					templo <= (RT)? (RS/RT): lo;
					busy <= 1;
					state <= 10;
				end
			end
			else if(state==1&&(!mul)) begin
				hi <= temphi;
				lo <= templo;
				busy <= 0;
				state <= 0;
			end
			else if(state==1&&(mul)) begin
				res_mul <= templo;
				busy <= 0;
				state <= 0;
				fzero <= 1;
			end
			else state <= state - 1;
		end
	end
	
endmodule
