# Main Clock
set_property PACKAGE_PIN L16 [get_ports clk100]
set_property IOSTANDARD LVCMOS33 [get_ports clk100]

# BTN
set_property PACKAGE_PIN Y16 [get_ports rst]
set_property IOSTANDARD LVCMOS33 [get_ports rst]

# VGA signals
set_property PACKAGE_PIN F19 [get_ports {vga_red[4]}]
set_property PACKAGE_PIN G20 [get_ports {vga_red[3]}]
set_property PACKAGE_PIN J20 [get_ports {vga_red[2]}]
set_property PACKAGE_PIN L20 [get_ports {vga_red[1]}]
set_property PACKAGE_PIN M19 [get_ports {vga_red[0]}]
set_property PACKAGE_PIN F20 [get_ports {vga_green[5]}]
set_property PACKAGE_PIN H20 [get_ports {vga_green[4]}]
set_property PACKAGE_PIN J19 [get_ports {vga_green[3]}]
set_property PACKAGE_PIN L19 [get_ports {vga_green[2]}]
set_property PACKAGE_PIN N20 [get_ports {vga_green[1]}]
set_property PACKAGE_PIN H18 [get_ports {vga_green[0]}]
set_property PACKAGE_PIN G19 [get_ports {vga_blue[4]}]
set_property PACKAGE_PIN J18 [get_ports {vga_blue[3]}]
set_property PACKAGE_PIN K19 [get_ports {vga_blue[2]}]
set_property PACKAGE_PIN M20 [get_ports {vga_blue[1]}]
set_property PACKAGE_PIN P20 [get_ports {vga_blue[0]}]
set_property IOSTANDARD LVCMOS33 [get_ports {vga_red[4]}]
set_property IOSTANDARD LVCMOS33 [get_ports {vga_red[3]}]
set_property IOSTANDARD LVCMOS33 [get_ports {vga_red[2]}]
set_property IOSTANDARD LVCMOS33 [get_ports {vga_red[1]}]
set_property IOSTANDARD LVCMOS33 [get_ports {vga_red[0]}]
set_property IOSTANDARD LVCMOS33 [get_ports {vga_green[5]}]
set_property IOSTANDARD LVCMOS33 [get_ports {vga_green[4]}]
set_property IOSTANDARD LVCMOS33 [get_ports {vga_green[3]}]
set_property IOSTANDARD LVCMOS33 [get_ports {vga_green[2]}]
set_property IOSTANDARD LVCMOS33 [get_ports {vga_green[1]}]
set_property IOSTANDARD LVCMOS33 [get_ports {vga_green[0]}]
set_property IOSTANDARD LVCMOS33 [get_ports {vga_blue[4]}]
set_property IOSTANDARD LVCMOS33 [get_ports {vga_blue[3]}]
set_property IOSTANDARD LVCMOS33 [get_ports {vga_blue[2]}]
set_property IOSTANDARD LVCMOS33 [get_ports {vga_blue[1]}]
set_property IOSTANDARD LVCMOS33 [get_ports {vga_blue[0]}]
set_property PACKAGE_PIN P19 [get_ports VGA_HSYNC]
set_property PACKAGE_PIN R19 [get_ports VGA_VSYNC]
set_property IOSTANDARD LVCMOS33 [get_ports VGA_HSYNC]
set_property IOSTANDARD LVCMOS33 [get_ports VGA_VSYNC]

#CMOS1 signals
set_property -dict {PACKAGE_PIN H15 IOSTANDARD LVCMOS33} [get_ports cmos1_reset] 
set_property -dict {PACKAGE_PIN T15 IOSTANDARD LVCMOS33} [get_ports cmos1_pclk]  
set_property -dict {PACKAGE_PIN V18 IOSTANDARD LVCMOS33} [get_ports cmos1_href]  
set_property -dict {PACKAGE_PIN R14 IOSTANDARD LVCMOS33} [get_ports cmos1_vsync] 
set_property -dict {PACKAGE_PIN W16 IOSTANDARD LVCMOS33} [get_ports cmos1_scl]   
set_property -dict {PACKAGE_PIN U17 IOSTANDARD LVCMOS33} [get_ports cmos1_sda]   
set_property -dict {PACKAGE_PIN T10 IOSTANDARD LVCMOS33} [get_ports {cmos1_d[7]}]
set_property -dict {PACKAGE_PIN V15 IOSTANDARD LVCMOS33} [get_ports {cmos1_d[6]}]
set_property -dict {PACKAGE_PIN U15 IOSTANDARD LVCMOS33} [get_ports {cmos1_d[5]}]
set_property -dict {PACKAGE_PIN U14 IOSTANDARD LVCMOS33} [get_ports {cmos1_d[4]}]
set_property -dict {PACKAGE_PIN W15 IOSTANDARD LVCMOS33} [get_ports {cmos1_d[3]}]
set_property -dict {PACKAGE_PIN T11 IOSTANDARD LVCMOS33} [get_ports {cmos1_d[2]}]
set_property -dict {PACKAGE_PIN U12 IOSTANDARD LVCMOS33} [get_ports {cmos1_d[1]}]
set_property -dict {PACKAGE_PIN V17 IOSTANDARD LVCMOS33} [get_ports {cmos1_d[0]}]

#CMOS2 signals
set_property -dict {PACKAGE_PIN Y17 IOSTANDARD LVCMOS33} [get_ports cmos2_reset] 
set_property -dict {PACKAGE_PIN J15 IOSTANDARD LVCMOS33} [get_ports cmos2_scl]   
set_property -dict {PACKAGE_PIN T17 IOSTANDARD LVCMOS33} [get_ports cmos2_sda]   
set_property -dict {PACKAGE_PIN V20 IOSTANDARD LVCMOS33} [get_ports cmos2_vsync] 
set_property -dict {PACKAGE_PIN W19 IOSTANDARD LVCMOS33} [get_ports cmos2_href]  
set_property -dict {PACKAGE_PIN W20 IOSTANDARD LVCMOS33} [get_ports cmos2_pclk]   
set_property -dict {PACKAGE_PIN Y18 IOSTANDARD LVCMOS33} [get_ports {cmos2_d[7]}]
set_property -dict {PACKAGE_PIN U20 IOSTANDARD LVCMOS33} [get_ports {cmos2_d[6]}]
set_property -dict {PACKAGE_PIN W18 IOSTANDARD LVCMOS33} [get_ports {cmos2_d[5]}]
set_property -dict {PACKAGE_PIN Y19 IOSTANDARD LVCMOS33} [get_ports {cmos2_d[4]}]
set_property -dict {PACKAGE_PIN T12 IOSTANDARD LVCMOS33} [get_ports {cmos2_d[3]}]  
set_property -dict {PACKAGE_PIN Y14 IOSTANDARD LVCMOS33} [get_ports {cmos2_d[2]}]
set_property -dict {PACKAGE_PIN W14 IOSTANDARD LVCMOS33} [get_ports {cmos2_d[1]}]
set_property -dict {PACKAGE_PIN T20 IOSTANDARD LVCMOS33} [get_ports {cmos2_d[0]}]
   
#buzzer signals
set_property PACKAGE_PIN V12 [get_ports buzzer]
set_property IOSTANDARD LVCMOS33 [get_ports buzzer]

#close the input clk buffer
set_property CLOCK_DEDICATED_ROUTE FALSE [get_nets cmos1_pclk_IBUF]
set_property CLOCK_DEDICATED_ROUTE FALSE [get_nets cmos2_pclk_IBUF]

#set_property PULLUP true [get_ports rst]
