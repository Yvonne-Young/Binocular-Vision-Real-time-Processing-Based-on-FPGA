#include "pre.h"

void pre(arr fbiL[rows*cols], 
         arr fbiR[rows*cols],
		 arr fboL[rows*cols],
		 arr fboR[rows*cols]
				)
{
#pragma HLS INTERFACE bram port=fboR
#pragma HLS INTERFACE bram port=fboL
#pragma HLS INTERFACE bram port=fbiR
#pragma HLS INTERFACE bram port=fbiL
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS DATAFLOW

	hls::Mat<rows,cols,HLS_16SC2> map11,map21;
	hls::Mat<rows,cols,HLS_12UC1> map12,map22;
	GRAY img1,img2,img1r,img2r;

	hls::Window<3,3,m> M1,M2;
	hls::Window<3,3,r> iR1,iR2;
	ap_uint<3> i,j;

	 //m m1[3][3]={{141.670093632375, 0., 81.3217530418497},{0.,177.354899021194, 47.4676024486666},{0., 0., 1.}};
	 m m2[3][3]={{141.657756536603, 0., 81.5881524487396},{0.,
	      177.213616265634, 52.4654149211577},{0., 0., 1.}};
	 r r1[3][3]={{0.00639365,-0.000104209, -0.565398},{0.000104633,0.00642304,-0.317697},
			 {-0.000613695,9.4215e-006,1.05889}};
	 r r2[3][3]={{0.00639726,-0.00010039,-0.571891},{9.99934e-005,0.00642311,-0.315918},{-0.000575713,
			 7.64606e-008,1.05593}};
	 d D1[4]={-0.368641459204379, 0.126428725257784, -0.000364057480755632,
		       0.000576290656880912};
	 d D2[4]={-0.381802339410920, 0.195934779882003, -0.000564323788321253,
		       0.000672280782326135};
	 m m1[3][3]={{141.670093632375, 0., 81.3217530418497},{0.,177.354899021194, 47.4676024486666},{0., 0., 1.}};

	getMap_label0:for(i=0;i<3;i++){
        #pragma HLS PIPELINE
		getMap_label1:for(j=0;j<3;j++){
		M1.insert(m1[i][j],i,j);
		M2.insert(m2[i][j],i,j);
		iR1.insert(r1[i][j],i,j);
		iR2.insert(r2[i][j],i,j);
		}
	}
	hls::InitUndistortRectifyMapInverse<m,d,r,rows,cols,HLS_16SC2,HLS_12UC1,4>(M1,D1,iR1,map11,map12);
	hls::InitUndistortRectifyMapInverse<m,d,r,rows,cols,HLS_16SC2,HLS_12UC1,4>(M2,D2,iR2,map21,map22);
	hls::Array222Mat<cols,arr,rows,cols,HLS_8UC1>(fbiL,cols,img1);
	hls::Array222Mat<cols,arr,rows,cols,HLS_8UC1>(fbiR,cols,img2);
    hls::Remap_linear<32,rows,cols,HLS_8UC1,HLS_8UC1,HLS_16SC2,HLS_12UC1>(img1, img1r, map11, map12);
    hls::Remap_linear<32,rows,cols,HLS_8UC1,HLS_8UC1,HLS_16SC2,HLS_12UC1>(img2, img2r, map21, map22);
	hls::Mat222Array<cols,arr,rows,cols,HLS_8UC1>(img1r,fboL,cols);
	hls::Mat222Array<cols,arr,rows,cols,HLS_8UC1>(img2r,fboR,cols);

}
