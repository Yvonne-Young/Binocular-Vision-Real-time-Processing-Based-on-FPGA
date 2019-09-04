module x(
         input done1,
         input done2,
		 output done);
		 
assign done = done1 && done2;

endmodule