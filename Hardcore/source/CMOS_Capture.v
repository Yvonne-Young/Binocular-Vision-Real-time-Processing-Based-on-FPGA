/*-------------------------------------------------------------------------
Description			:		sdram test with uart interface.
Modification History	:
Data			By			Version			Change Description
===========================================================================

--------------------------------------------------------------------------*/

`timescale 1ns/1ns
module CMOS_Capture
(
	//Global Clock
	input				iCLK,			//24MHz
	input				iRST_N,

	//I2C Initilize Done
	input				Init_Done,		//Init Done
	
	//Sensor Interface
	input				CMOS_PCLK,		//24MHz
	input	[7:0]		CMOS_iDATA,		//CMOS Data
	input				CMOS_VSYNC,		//L: Vaild
	input				CMOS_HREF,		//H: Vaild
	
	//Ouput Sensor Data
	output	reg			CMOS_oCLK,		//1/2 PCLK
	output	reg	[15:0]	CMOS_oDATA,		//16Bits RGB		
	output	reg			CMOS_VALID		//Data Enable
);

//----------------------------------------------
reg		mCMOS_VSYNC;
always@(posedge CMOS_PCLK or negedge iRST_N)
begin
	if(!iRST_N)
		mCMOS_VSYNC <= 1;
	else
		mCMOS_VSYNC <= CMOS_VSYNC;		//场同步：低电平有效
end
wire	CMOS_VSYNC_over = ({mCMOS_VSYNC,CMOS_VSYNC} == 2'b01) ? 1'b1 : 1'b0;	//VSYNC上升沿结束

//-----------------------------------------------------
//Change the sensor data from 8 bits to 16 bits.
reg			byte_state;		//byte state count
reg [7:0]  	Pre_CMOS_iDATA;
always@(posedge CMOS_PCLK or negedge iRST_N)
begin
	if(!iRST_N)
		begin
		byte_state <= 0;
		Pre_CMOS_iDATA <= 8'd0;
		CMOS_oDATA <= 16'd0;
		end
	else
		begin
		if(~CMOS_VSYNC & CMOS_HREF)			//行场有效，{first_byte, second_byte} 
			begin
			byte_state <= byte_state + 1'b1;	//（RGB565 = {first_byte, second_byte}）
			case(byte_state)
			1'b0 :	Pre_CMOS_iDATA[7:0] <= CMOS_iDATA;
			1'b1 : 	CMOS_oDATA[15:0] <= {Pre_CMOS_iDATA[7:0], CMOS_iDATA[7:0]};
			endcase
			end
		else
			begin
			byte_state <= 0;
			Pre_CMOS_iDATA <= 8'd0;
			CMOS_oDATA <= CMOS_oDATA;
			end
		end
end


//--------------------------------------------
//Wait for Sensor output Data valid， 10 Franme
reg	[3:0] 	Frame_Cont;
reg 		Frame_valid;
always@(posedge CMOS_PCLK or negedge iRST_N)
begin
	if(!iRST_N)
		begin
		Frame_Cont <= 0;
		Frame_valid <= 0;
		end
	else if(Init_Done)					//CMOS I2C初始化完毕
		begin
		if(CMOS_VSYNC_over == 1'b1)		//VS上升沿，1帧写入完毕
			begin
			if(Frame_Cont < 12)
				begin
				Frame_Cont	<=	Frame_Cont + 1'b1;
				Frame_valid <= 1'b0;
				end
			else
				begin
				Frame_Cont	<=	Frame_Cont;
				Frame_valid <= 1'b1;		//数据输出有效
				end
			end
		end
end

//-----------------------------------------------------
//CMOS_DATA数据同步输出使能时钟
always@(posedge CMOS_PCLK or negedge iRST_N)
begin
	if(!iRST_N)
		CMOS_oCLK <= 0;
	else if(Frame_valid == 1'b1 && byte_state)
		CMOS_oCLK <= ~CMOS_oCLK;
	else
		CMOS_oCLK <= 0;
end

//----------------------------------------------------
//数据输出有效CMOS_VALID
always@(posedge CMOS_PCLK or negedge iRST_N)
begin
	if(!iRST_N)
		CMOS_VALID <= 0;
	else if(Frame_valid == 1'b1)
		CMOS_VALID <= ~CMOS_VSYNC;
	else
		CMOS_VALID <= 0;
end


endmodule



