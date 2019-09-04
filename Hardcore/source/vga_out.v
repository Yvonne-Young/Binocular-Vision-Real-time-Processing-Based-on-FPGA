`timescale 1ns / 1ps

module vga_out #(
parameter  HD = 640, //�?
           HF = 48,
           HA = 16,
           HB = 96,
           HT = 800,
           VD = 480, //�?
           VF = 33,
           VA = 10,
           VB = 2,
           VT = 525,
		   SHOW_H_START = 0,
           SHOW_V_START = 0,
           SHOW_WIDTH = 640,
           SHOW_HEIGHT = 480
 )
 (
	input [15:0] RGB565,
    input vga_pclk,vga_rst,
    output wire vga_hsync,vga_vsync, //vga视频同步信号
    output wire [11:0]vga_h_cnt,                //计数信号
    output wire [10:0]vga_v_cnt,                 //(h,v)当前像素�?
	output wire [4:0]vga_red,
	output wire [5:0]vga_green,
	output wire [4:0]vga_blue
    );

reg [11:0]pixel_cnt;
reg [10:0]line_cnt;
reg hsync,vsync;
wire vga_valid;

always@(posedge vga_pclk or negedge vga_rst)  //pixel_cnt 像素计数�?0-799
if(!vga_rst)
    pixel_cnt <= 0;
else if(pixel_cnt < (HT - 1))
    pixel_cnt <= pixel_cnt + 1;
else
    pixel_cnt <= 0;

always@(posedge vga_pclk or negedge vga_rst)  //hsync行消隐控�?
if(!vga_rst)
    hsync <= 1;
else if((pixel_cnt >= (HD + HF - 1))&&(pixel_cnt < (HD + HF + HA -1)))
    hsync <= 0;
else
    hsync <= 1;
    
always@(posedge vga_pclk or negedge vga_rst)  //line_cnt 行计�?
if(!vga_rst)
    line_cnt <= 0;
else if(pixel_cnt == (HT -1))
    if(line_cnt < (VT - 1))
        line_cnt <= line_cnt + 1;
    else
        line_cnt <= 0;
                    
always@(posedge vga_pclk or negedge vga_rst)  //vsync场消隐控�?
if(!vga_rst)
    vsync <= 1;
else if((line_cnt >= (VD + VF - 1))&&(line_cnt < (VD + VF + VA - 1)))
    vsync <= 0;
else
    vsync <= 1;
                    
assign vga_hsync = hsync;
assign vga_vsync = vsync;
assign vga_valid = ((pixel_cnt < HD) && (line_cnt < VD));
    
assign vga_h_cnt = (pixel_cnt < HD) ? pixel_cnt:11'd0;
assign vga_v_cnt = (line_cnt < VD) ? line_cnt:10'd0;
	
assign vga_red   = (vga_valid==1 && vga_h_cnt >=SHOW_H_START && vga_h_cnt<SHOW_H_START+SHOW_WIDTH && vga_v_cnt>=SHOW_V_START && vga_v_cnt<SHOW_V_START+SHOW_HEIGHT)?RGB565[15:11]:5'b0;
assign vga_green = (vga_valid==1 && vga_h_cnt >=SHOW_H_START && vga_h_cnt<SHOW_H_START+SHOW_WIDTH && vga_v_cnt>=SHOW_V_START && vga_v_cnt<SHOW_V_START+SHOW_HEIGHT)?RGB565[10:5]:6'b0;
assign vga_blue  = (vga_valid==1 && vga_h_cnt >=SHOW_H_START && vga_h_cnt<SHOW_H_START+SHOW_WIDTH && vga_v_cnt>=SHOW_V_START && vga_v_cnt<SHOW_V_START+SHOW_HEIGHT)?RGB565[4:0]:5'b0;

endmodule
