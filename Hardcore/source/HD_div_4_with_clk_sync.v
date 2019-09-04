module HD_div_4_with_clk_sync(
								input  wire         rst_n,
								input  wire         pclk,
								input  wire  [15:0] RGB565,
								
								input  wire  [11:0] H_cnt,
								input  wire  [10:0] V_cnt,

								output reg          oclk,
								output reg   [15:0] RGB565_o,
								output reg   [7:0]  GREY_o,
								output reg   [14:0] Addr_160
								);
	
always @ (posedge pclk or negedge rst_n)
if(!rst_n)
begin
    RGB565_o <= 0;
	Addr_160 <= 0;
	oclk     <= 0;
end
else if(H_cnt[1:0]==2'b00 && V_cnt[1:0]==2'b00)
begin
    Addr_160 <= 160*V_cnt[8:2] + H_cnt[9:2];
	RGB565_o <= RGB565;
	GREY_o   <= {2'b0,RGB565[15:11],1'b0}+{1'b0,RGB565[10:5],1'b0}+{3'b0,RGB565[4:0]};
	oclk     <=1;
end
else
begin
    RGB565_o <= RGB565_o;
	GREY_o   <= GREY_o;
	Addr_160 <= Addr_160;
	oclk     <= 0;
end

endmodule