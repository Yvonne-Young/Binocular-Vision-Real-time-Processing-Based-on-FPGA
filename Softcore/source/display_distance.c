#include "xparameters.h"
#include "xil_io.h"
#include "stdio.h"
#include "select_3.h"

//====================================================

int main (void) 
{
   int data;
   xil_printf("-- Start of the Program --\r\n");
   while (1)
   {  
	  for (int i=0; i<20; i++){
		  data=SELECT_3_mReadReg(XPAR_SELECT_3_0_S00_AXI_BASEADDR,0);
		  xil_printf("--the data written in is:%d--\r\n",data);
	      for (int j=0; j<19999999; j++);
	  }
   }
}


