module VGA_out_choose(
				input rst_n,
				input [15:0] RGB565_1,
				input [15:0] RGB565_2,
				input [7:0] RGB565_d,
				input [11:0] H_cnt,
				input [10:0] V_cnt,
				output reg [15:0] RGB565,
				output reg [14:0] Addr
				);
	
always@(*)
if(!rst_n)
	RGB565<=0;
else if(H_cnt>=160 && H_cnt<480 && V_cnt>=40 && V_cnt<280)
	RGB565 = {RGB565_d[7:3],RGB565_d[7:2],RGB565_d[7:3]};
else if(H_cnt>=160 && H_cnt<320 && V_cnt>=320 && V_cnt<440)
	RGB565 = RGB565_1;
else if(H_cnt>=320 && H_cnt<480 && V_cnt>=320 && V_cnt<440)
	RGB565 = RGB565_2;
else
	RGB565 = {V_cnt[7:3],V_cnt[7:2],V_cnt[7:3]};
	
always@(*)
if(!rst_n)
	Addr = 0;
else if(H_cnt>=160 && H_cnt<480 && V_cnt>=40 && V_cnt<280)
	Addr = ((H_cnt-160)/2)+160*((V_cnt-40)/2);
else if(H_cnt>=160 && H_cnt<320 && V_cnt>=320 && V_cnt<440)
	Addr = ((H_cnt-160))+160*((V_cnt-320));
else if(H_cnt>=320 && H_cnt<480 && V_cnt>=320 && V_cnt<440)
	Addr = ((H_cnt-320))+160*((V_cnt-320));
else
	Addr = Addr;

endmodule