
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <cstdio>
#include <string>
#include <hls_video.h>
#include"ap_fixed.h"
#include "ap_int.h"
using namespace std;

const int rows=120;
const int cols=160;

//typedef hls::stream< ap_axiu<24,1,1,1> >  AXI_STREAM;
//typedef hls::stream< ap_axiu<8,1,1,1> >  AXI_STREAMs;
typedef hls::Mat<rows,cols,HLS_8UC1> GRAY;
typedef ap_uint<8> arr;
typedef ap_ufixed<13,8,AP_RND,AP_SAT> m;
typedef ap_fixed<21,1,AP_RND,AP_SAT> r;
typedef ap_fixed<16,1,AP_RND,AP_SAT> d;

void stereo(arr inputL[rows*cols],
		arr inputR[rows*cols],
		arr outputD[rows*cols]
				);

