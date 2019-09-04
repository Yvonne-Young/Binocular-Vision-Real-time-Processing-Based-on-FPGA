#include "stereo.h"

void stereo(arr inputL[rows*cols],
		arr inputR[rows*cols],
		arr outputD[rows*cols]
				)
{
#pragma HLS INTERFACE bram port=outputD
#pragma HLS INTERFACE bram port=inputR
#pragma HLS INTERFACE bram port=inputL
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS DATAFLOW

	GRAY img1r,img2r;
	hls::Array2Mat<cols,arr,rows,cols,HLS_8UC1>(inputL,cols,img1r);
	hls::Array2Mat<cols,arr,rows,cols,HLS_8UC1>(inputR,cols,img2r);
    const int wsize = 13;//11
    const int ndisp_unit = 2;
    const int ndisp=ndisp_unit*16;
    hls::StereoBMState<wsize,ndisp,ndisp_unit> bm;
    bm.uniquenessRatio=20;//18
    //bm.textureThreshold=500;
	hls::Mat<rows,cols,HLS_16SC1>disp;
	GRAY imgO;
	hls::FindStereoCorrespondenceBM<wsize,ndisp,ndisp_unit,rows,cols,HLS_8UC1,HLS_16SC1>(img2r, img1r, disp, bm);
    hls::ConvertScaleAbs<HLS_16SC1,HLS_8UC1,rows,cols>(disp,imgO,255/(ndisp*16.));
	hls::Mat2Array<cols,arr,rows,cols,HLS_8UC1>(imgO,outputD,cols);
}
