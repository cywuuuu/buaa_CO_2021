/*`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   02:35:20 11/20/2019
// Design Name:   mips
// Module Name:   C:/Users/mumuy/Desktop/ISE/pipelineCPU10/tb.v
// Project Name:  pipelineCPU10
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: mips
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module tb;

	// Inputs
	reg clk;
	reg reset;

	// Instantiate the Unit Under Test (UUT)
	mips uut (
		.clk(clk), 
		.reset(reset)
	);

	initial begin
		// Initialize Inputs
		clk = 0;
		reset = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here

	end
	
	always #5 clk=~clk;
      
endmodule

*/




/*

`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   14:31:29 11/16/2016
// Design Name:   mips
// Module Name:   D:/ISE/P4/mips_txt.v
// Project Name:  P4
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: mips
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module tb;

	// Inputs
	reg clk;
	reg reset;

	// Outputs
	wire [31:0] addr;

	// Instantiate the Unit Under Test (UUT)
	mips uut (
		.clk(clk), 
		.reset(reset),
		.interrupt(1'b0),
		.addr(addr)
	);

	initial begin
		// Initialize Inputs
		clk = 0;
		reset = 1;
		#20 reset = 0;
		// Wait 100 ns for global reset to finish
		// Add stimulus here

	end
   always #2 clk = ~clk;
endmodule
*/


`timescale 1ns/1ps

module mips_txt;

	reg clk;
	reg reset;
	reg interrupt;

	wire [31:0] macroscopic_pc;

	wire [31:0] i_inst_addr;
	wire [31:0] i_inst_rdata;

	wire [31:0] m_data_addr;
	wire [31:0] m_data_rdata;
	wire [31:0] m_data_wdata;
	wire [3 :0] m_data_byteen;

	wire [31:0] m_inst_addr;

	wire		w_grf_we;
	wire [4 :0] w_grf_addr;
	wire [31:0] w_grf_wdata;

	wire [31:0] w_inst_addr;

	mips uut(
		.clk(clk),
		.reset(reset),
		.interrupt(interrupt),
		.macroscopic_pc(macroscopic_pc),

		.i_inst_addr(i_inst_addr),
		.i_inst_rdata(i_inst_rdata),

		.m_data_addr(m_data_addr),
		.m_data_rdata(m_data_rdata),
		.m_data_wdata(m_data_wdata),
		.m_data_byteen(m_data_byteen),

		.m_inst_addr(m_inst_addr),

		.w_grf_we(w_grf_we),
		.w_grf_addr(w_grf_addr),
		.w_grf_wdata(w_grf_wdata),

		.w_inst_addr(w_inst_addr)
	);

	initial begin
		clk <= 0;
		reset <= 1;
		interrupt <= 0;
		#20 reset <= 0;
	end

	integer i;
	reg [31:0] fixed_addr;
	reg [31:0] fixed_wdata;
	reg [31:0] data[0:4095];
	reg [31:0] inst[0:5119];

	// ----------- For Instructions -----------

	assign m_data_rdata = data[(m_data_addr >> 2) % 5120];
	assign i_inst_rdata = inst[((i_inst_addr - 32'h3000) >> 2) % 5120];

	initial begin
		$readmemh("code.txt", inst);
		$readmemh("code_handler.txt", inst, 32'h460);
		for (i = 0; i < 5120; i = i + 1) data[i] <= 0;
	end

	// ----------- For Data Memory -----------

	always @(*) begin
		fixed_wdata = data[(m_data_addr >> 2) & 4095];
		fixed_addr = m_data_addr & 32'hfffffffc;
		if (m_data_byteen[3]) fixed_wdata[31:24] = m_data_wdata[31:24];
		if (m_data_byteen[2]) fixed_wdata[23:16] = m_data_wdata[23:16];
		if (m_data_byteen[1]) fixed_wdata[15: 8] = m_data_wdata[15: 8];
		if (m_data_byteen[0]) fixed_wdata[7 : 0] = m_data_wdata[7 : 0];
	end

	always @(posedge clk) begin
		if (reset) for (i = 0; i < 4096; i = i + 1) data[i] <= 0;
		else if (|m_data_byteen && fixed_addr >> 2 < 4096) begin
			data[fixed_addr >> 2] <= fixed_wdata;
			$display("%d@%h: *%h <= %h", $time, m_inst_addr, fixed_addr, fixed_wdata);
		end
	end

	// ----------- For Registers -----------

	always @(posedge clk) begin
		if (~reset) begin
			if (w_grf_we && (w_grf_addr != 0)) begin
				$display("%d@%h: $%d <= %h", $time, w_inst_addr, w_grf_addr, w_grf_wdata);
			end
		end
	end


	parameter exception_pc = 32'h0000301c;
	integer exception_count;
	integer interrupt_counter;
	integer needInterrupt;

	initial begin
		exception_count = 0;
		interrupt = 0;
		needInterrupt = 0;
		interrupt_counter = 0;
		// Initialize Inputs
		clk = 0;
		reset = 1;
		#20 reset = 0;
		#4;
		#4;
		#4;
		#4;
		#4;
		#4;
		#4;
		#4;
		#4;
		#4;
		#4;
		#4;
		#4;
		#4;
		#2;
		#2;
		#4;
		#4;
		#4;
		#4;
		#4;
		#4;
		#4;
		#4;
		#4;
		// Wait 100 ns for global reset to finish
		// Add stimulus here

	end
   always #2 clk = ~clk;

   always @(negedge clk) begin
      if (reset) begin
	  	interrupt_counter = 0;
		needInterrupt = 0;
		interrupt = 0;
	  end else begin
	  	if (interrupt) begin
		  	if (interrupt_counter == 0) begin
				interrupt = 0;
			end else begin
				interrupt_counter = interrupt_counter - 1;
			end
		end else if (needInterrupt) begin
			needInterrupt = needInterrupt - 1;
			if(needInterrupt==0)begin
				interrupt = 1;
				interrupt_counter = 5;
			end
		end else begin
			case (macroscopic_pc)
				exception_pc: 
					begin
						if (exception_count == 0) begin
							exception_count = 1;
							needInterrupt = 5;
							interrupt_counter = 5;
						end
					end
			endcase
		end
	  end
	
   end

endmodule
