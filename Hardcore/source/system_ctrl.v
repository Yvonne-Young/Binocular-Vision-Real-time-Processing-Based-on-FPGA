/*-------------------------------------------------------------------------
Description			:		sdram vga controller with ov7670 display.
===========================================================================
15/02/1
--------------------------------------------------------------------------*/
`timescale 1 ns / 1 ns
module system_ctrl
(
	input 		clk,		//50MHz
	input 		rst,		//global reset

	output reg sys_rst_n	//system reset


);
wire rst_n;
assign rst_n = ~rst;

reg  [9:0]   delay_cnt;
always @(posedge clk or negedge rst_n)
begin
	if(!rst_n)
		begin
		delay_cnt <= 0;
		sys_rst_n <= 1'b0;
		end
	else
		begin
		  if (delay_cnt== 1000)
			 sys_rst_n <= 1'b1;
        else
          delay_cnt <= delay_cnt +1'b1;
		end
end

endmodule
