module camera_capture_320(
	input pclk,
	input vsync,
	input href,
	input rst_n,
	output [11:0]H_cnt,
	output [10:0]V_cnt
);

assign wclk = pclk;

reg[11:0] hcnt;
reg [10:0] vcnt;
reg href_post;

assign H_cnt = (hcnt/2>=0 && hcnt/2<640)?hcnt/2:0;
assign V_cnt = (vcnt>=0 && vcnt<480)?vcnt:0;  

always@(posedge pclk) 
    href_post<=href;

always@(posedge pclk)begin 
	if( vsync ==1) begin
		vcnt <=  0;
		hcnt <= 0;
	end
	else begin         
		if ({href_post,href}==2'b10 )begin
			vcnt <= vcnt+1;
			hcnt <= 0;
		end
		if(href ==1 )begin
				hcnt <= hcnt+1;
			end
	end
end
endmodule
