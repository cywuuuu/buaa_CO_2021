`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   13:07:58 12/08/2021
// Design Name:   shishi
// Module Name:   E:/Desktop/pipeline_create4/tttt.v
// Project Name:  my_firs_pipeline
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: shishi
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module tttt;

	// Inputs
	reg [31:0] A;

	// Outputs
	wire [31:0] cnt;

	// Instantiate the Unit Under Test (UUT)
	shishi uut (
		.A(A), 
		.cnt(cnt)
	);

	initial begin
		// Initialize Inputs
		A = 33;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here

	end
      
endmodule

