module buzzer
(
	input wire        clk_data,
	input wire [14:0] addr,
	input wire [7:0]  data,
	
	input wire        clk_100,
	input wire        rst_n,
	
	output reg        buzzer
);

reg [7:0]  max;
reg [15:0] freq;
reg [15:0] clk_div;

reg [7:0] history0;
reg [7:0] history1;
reg [7:0] history2;
reg [7:0] history3;

reg [7:0] history4;
reg [7:0] history5;
reg [7:0] history6;
reg [7:0] history7;

reg [7:0] data_after_filter;

always@(posedge clk_data or negedge rst_n)
if(!rst_n) begin
	history0<=0;
	history1<=0;
	history2<=0;
	history3<=0;
	history4<=0;
	history5<=0;
	history6<=0;
	history7<=0;
end
else begin
	history0<=history1;
	history1<=history2;
	history2<=history3;
	history3<=history4;
	history4<=history5;
	history5<=history6;
	history6<=history7;
	history7<=data;
end

always@(posedge clk_data or negedge rst_n)
if(!rst_n)
	data_after_filter <= 0;
else if(history0==data &&
		history1==data &&
		history2==data &&
		history3==data &&
		history4==data &&
		history5==data &&
		history6==data &&
		history7==data)
	data_after_filter <= data;
else
	data_after_filter <= 0;


always@(posedge clk_data or negedge rst_n)
if(!rst_n)
	max <= 0;
else if(addr == 0)
	max <= 0;
else if(data_after_filter > max)
	max <= data_after_filter;
	
always@(posedge clk_100 or negedge rst_n)
if(!rst_n)
	freq <= 0;
else if(addr == 19199)
	case(max)
		8'd0  :freq<=520000;
		8'd1  :freq<=518000;
		8'd2  :freq<=516000;
		8'd3  :freq<=514000;
		8'd4  :freq<=512000;
		8'd5  :freq<=510000;
		8'd6  :freq<=508000;
		8'd7  :freq<=506000;
		8'd8  :freq<=504000;
		8'd9  :freq<=502000;
		8'd10 :freq<=500000;
		8'd11 :freq<=498000;
		8'd12 :freq<=496000;
		8'd13 :freq<=494000;
		8'd14 :freq<=492000;
		8'd15 :freq<=490000;
		8'd16 :freq<=488000;
		8'd17 :freq<=486000;
		8'd18 :freq<=484000;
		8'd19 :freq<=482000;
		8'd20 :freq<=480000;
		8'd21 :freq<=478000;
		8'd22 :freq<=476000;
		8'd23 :freq<=474000;
		8'd24 :freq<=472000;
		8'd25 :freq<=470000;
		8'd26 :freq<=468000;
		8'd27 :freq<=466000;
		8'd28 :freq<=464000;
		8'd29 :freq<=462000;
		8'd30 :freq<=460000;
		8'd31 :freq<=458000;
		8'd32 :freq<=456000;
		8'd33 :freq<=454000;
		8'd34 :freq<=452000;
		8'd35 :freq<=450000;
		8'd36 :freq<=448000;
		8'd37 :freq<=446000;
		8'd38 :freq<=444000;
		8'd39 :freq<=442000;
		8'd40 :freq<=440000;
		8'd41 :freq<=438000;
		8'd42 :freq<=436000;
		8'd43 :freq<=434000;
		8'd44 :freq<=432000;
		8'd45 :freq<=430000;
		8'd46 :freq<=428000;
		8'd47 :freq<=426000;
		8'd48 :freq<=424000;
		8'd49 :freq<=422000;
		8'd50 :freq<=420000;
		8'd51 :freq<=418000;
		8'd52 :freq<=416000;
		8'd53 :freq<=414000;
		8'd54 :freq<=412000;
		8'd55 :freq<=410000;
		8'd56 :freq<=408000;
		8'd57 :freq<=406000;
		8'd58 :freq<=404000;
		8'd59 :freq<=402000;
		8'd60 :freq<=400000;
		8'd61 :freq<=398000;
		8'd62 :freq<=396000;
		8'd63 :freq<=394000;
		8'd64 :freq<=392000;
		8'd65 :freq<=390000;
		8'd66 :freq<=388000;
		8'd67 :freq<=386000;
		8'd68 :freq<=384000;
		8'd69 :freq<=382000;
		8'd70 :freq<=380000;
		8'd71 :freq<=378000;
		8'd72 :freq<=376000;
		8'd73 :freq<=374000;
		8'd74 :freq<=372000;
		8'd75 :freq<=370000;
		8'd76 :freq<=368000;
		8'd77 :freq<=366000;
		8'd78 :freq<=364000;
		8'd79 :freq<=362000;
		8'd80 :freq<=360000;
		8'd81 :freq<=358000;
		8'd82 :freq<=356000;
		8'd83 :freq<=354000;
		8'd84 :freq<=352000;
		8'd85 :freq<=350000;
		8'd86 :freq<=348000;
		8'd87 :freq<=346000;
		8'd88 :freq<=344000;
		8'd89 :freq<=342000;
		8'd90 :freq<=340000;
		8'd91 :freq<=338000;
		8'd92 :freq<=336000;
		8'd93 :freq<=334000;
		8'd94 :freq<=332000;
		8'd95 :freq<=330000;
		8'd96 :freq<=328000;
		8'd97 :freq<=326000;
		8'd98 :freq<=324000;
		8'd99 :freq<=322000;
		8'd100:freq<=320000;
		8'd101:freq<=318000;
		8'd102:freq<=316000;
		8'd103:freq<=314000;
		8'd104:freq<=312000;
		8'd105:freq<=310000;
		8'd106:freq<=308000;
		8'd107:freq<=306000;
		8'd108:freq<=304000;
		8'd109:freq<=302000;
		8'd110:freq<=300000;
		8'd111:freq<=298000;
		8'd112:freq<=296000;
		8'd113:freq<=294000;
		8'd114:freq<=292000;
		8'd115:freq<=290000;
		8'd116:freq<=288000;
		8'd117:freq<=286000;
		8'd118:freq<=284000;
		8'd119:freq<=282000;
		8'd120:freq<=280000;
		8'd121:freq<=278000;
		8'd122:freq<=276000;
		8'd123:freq<=274000;
		8'd124:freq<=272000;
		8'd125:freq<=270000;
		8'd126:freq<=268000;
		8'd127:freq<=266000;
		8'd128:freq<=264000;
		8'd129:freq<=262000;
		8'd130:freq<=260000;
		8'd131:freq<=258000;
		8'd132:freq<=256000;
		8'd133:freq<=254000;
		8'd134:freq<=252000;
		8'd135:freq<=250000;
		8'd136:freq<=248000;
		8'd137:freq<=246000;
		8'd138:freq<=244000;
		8'd139:freq<=242000;
		8'd140:freq<=240000;
		8'd141:freq<=238000;
		8'd142:freq<=236000;
		8'd143:freq<=234000;
		8'd144:freq<=232000;
		8'd145:freq<=230000;
		8'd146:freq<=228000;
		8'd147:freq<=226000;
		8'd148:freq<=224000;
		8'd149:freq<=222000;
		8'd150:freq<=220000;
		8'd151:freq<=218000;
		8'd152:freq<=216000;
		8'd153:freq<=214000;
		8'd154:freq<=212000;
		8'd155:freq<=210000;
		8'd156:freq<=208000;
		8'd157:freq<=206000;
		8'd158:freq<=204000;
		8'd159:freq<=202000;
		8'd160:freq<=200000;
		8'd161:freq<=198000;
		8'd162:freq<=196000;
		8'd163:freq<=194000;
		8'd164:freq<=192000;
		8'd165:freq<=190000;
		8'd166:freq<=188000;
		8'd167:freq<=186000;
		8'd168:freq<=184000;
		8'd169:freq<=182000;
		8'd170:freq<=180000;
		8'd171:freq<=178000;
		8'd172:freq<=176000;
		8'd173:freq<=174000;
		8'd174:freq<=172000;
		8'd175:freq<=170000;
		8'd176:freq<=168000;
		8'd177:freq<=166000;
		8'd178:freq<=164000;
		8'd179:freq<=162000;
		8'd180:freq<=160000;
		8'd181:freq<=158000;
		8'd182:freq<=156000;
		8'd183:freq<=154000;
		8'd184:freq<=152000;
		8'd185:freq<=150000;
		8'd186:freq<=148000;
		8'd187:freq<=146000;
		8'd188:freq<=144000;
		8'd189:freq<=142000;
		8'd190:freq<=140000;
		8'd191:freq<=138000;
		8'd192:freq<=136000;
		8'd193:freq<=134000;
		8'd194:freq<=132000;
		8'd195:freq<=130000;
		8'd196:freq<=128000;
		8'd197:freq<=126000;
		8'd198:freq<=124000;
		8'd199:freq<=122000;
		8'd200:freq<=120000;
		8'd201:freq<=118000;
		8'd202:freq<=116000;
		8'd203:freq<=114000;
		8'd204:freq<=112000;
		8'd205:freq<=110000;
		8'd206:freq<=108000;
		8'd207:freq<=106000;
		8'd208:freq<=104000;
		8'd209:freq<=102000;
		8'd210:freq<=100000;
		8'd211:freq<=98000 ;
		8'd212:freq<=96000 ;
		8'd213:freq<=94000 ;
		8'd214:freq<=92000 ;
		8'd215:freq<=90000 ;
		8'd216:freq<=88000 ;
		8'd217:freq<=86000 ;
		8'd218:freq<=84000 ;
		8'd219:freq<=82000 ;
		8'd220:freq<=80000 ;
		8'd221:freq<=78000 ;
		8'd222:freq<=76000 ;
		8'd223:freq<=74000 ;
		8'd224:freq<=72000 ;
		8'd225:freq<=70000 ;
		8'd226:freq<=68000 ;
		8'd227:freq<=66000 ;
		8'd228:freq<=64000 ;
		8'd229:freq<=62000 ;
		8'd230:freq<=60000 ;
		8'd231:freq<=58000 ;
		8'd232:freq<=56000 ;
		8'd233:freq<=54000 ;
		8'd234:freq<=52000 ;
		8'd235:freq<=50000 ;
		8'd236:freq<=48000 ;
		8'd237:freq<=46000 ;
		8'd238:freq<=44000 ;
		8'd239:freq<=42000 ;
		8'd240:freq<=40000 ;
		8'd241:freq<=38000 ;
		8'd242:freq<=36000 ;
		8'd243:freq<=34000 ;
		8'd244:freq<=32000 ;
		8'd245:freq<=30000 ;
		8'd246:freq<=28000 ;
		8'd247:freq<=26000 ;
		8'd248:freq<=24000 ;
		8'd249:freq<=22000 ;
		8'd250:freq<=20000 ;
		8'd251:freq<=18000 ;
		8'd252:freq<=16000 ;
		8'd253:freq<=14000 ;
		8'd254:freq<=12000 ;
		8'd255:freq<=10000 ;
	endcase

always@(posedge clk_100 or negedge rst_n)
if(!rst_n) begin
	clk_div <= 0;
	buzzer  <= 0;
end
else if(clk_div != freq)
	clk_div <= clk_div + 1;
else begin
	clk_div <= 0;
	buzzer  <= ~buzzer;
end

endmodule
