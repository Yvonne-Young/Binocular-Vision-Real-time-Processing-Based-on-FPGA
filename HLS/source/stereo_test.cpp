#include "bm.h"
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/legacy/legacy.hpp>
#include <hls_opencv.h>
using namespace hls;
int main(){
/*
	Window<3,3, double> iR1,iR2;
    Window<3,3, double> ir1,ir2;
    Window<3,3, double> irr1,irr2;
	Window<3,3, double> M1,M2,P;
	ap_uint<3> i,j;
	double m1[3][3]={{141.670093632375, 0, 81.3217530418497},{0.,
       177.354899021194, 47.4676024486666},{0., 0., 1.}};
	double m2[3][3]={{141.657756536603, 0., 81.5881524487396},{ 0.,
       177.213616265634, 52.4654149211577},{0., 0., 1.}};
	double p[3][3]={{1.5566886437486403e+002, 0., 1.0415352821350098e+002},{0.,
       1.5566886437486403e+002, 4.7779376506805420e+001},{0., 0., 1.}};
	double r1[3][3]={{9.9529297735334110e-001, 1.6288054207328227e-002,
       -9.5533180211174365e-002},{-1.6222139138716892e-002,
       9.9986733679333295e-001, 1.4666340961673140e-003},{9.5544395088805148e-002, 9.0021925487498728e-005,
       9.9542516567704220e-001}};
	double r2[3][3]={{9.9585433232194842e-001, 1.5565853571121674e-002,
       -8.9620605879500381e-002},{-1.5627673101962607e-002,
       9.9987788038927439e-001, 1.1902535492038131e-005},{8.9609846719121977e-002, 1.3887083403493032e-003,
       9.9597597704970808e-001}};
	double D1[4]={-0.368641459204379, 0.126428725257784, -0.000364057480755632,
       0.000576290656880912};
	double D2[4]={-0.381802339410920, 0.195934779882003, -0.000564323788321253,
       0.000672280782326135};

	getMap_label0:for(i=0;i<3;i++){
		getMap_label1:for(j=0;j<3;j++){
		M1.insert(m1[i][j],i,j);
		M2.insert(m2[i][j],i,j);
		P.insert(p[i][j],i,j);
		iR1.insert(r1[i][j],i,j);
		iR2.insert(r2[i][j],i,j);
		}
	}

	mul<3, 3, 3>(P.val, iR1.val, irr1.val);
	Invert<3>(irr1.val, ir1.val);
	mul<3, 3, 3>(P.val, iR2.val, irr2.val);
	Invert<3>(irr2.val, ir2.val);
	for(i=0;i<3;i++){
				for(j=0;j<3;j++){
					std::cout<<M1(i,j)<<endl;
				}
			}

	for(i=0;i<3;i++){
			for(j=0;j<3;j++){
			std::cout<<ir1(i,j)<<endl;
			}
		}
	for(i=0;i<3;i++){
				for(j=0;j<3;j++){
				std::cout<<ir2(i,j)<<endl;
				}
			}

    /*
	cv::Size img_size(160,120);
	//cv::Size img_size(1280,720);
	string intrinsic_filename = "E:/important/it/stereo/intrinsics1.yml";
	string extrinsic_filename = "E:/important/it/stereo/extrinsics1.yml";
	//string matrix_filename = "E:/important/it/stereo/matrix5.yml";

    cv::FileStorage fs(intrinsic_filename, CV_STORAGE_READ);
	    if(!fs.isOpened())
	    {
	        std::cout<<"Failed to open file "<<intrinsic_filename<<endl;
	        return -1;
	    }
		cv::Mat M1, D1, M2, D2;      //左右相机的内参数矩阵和畸变系数
	    fs["M1"] >> M1;
	    fs["D1"] >> D1;
		fs["M2"] >> M2;
		fs["D2"] >> D2;
		// 读取双目相机的立体矫正参数
	    fs.open(extrinsic_filename, CV_STORAGE_READ);
	    if(!fs.isOpened())
	    {
	        std::cout<<"Failed to open file  "<<extrinsic_filename<<endl;
	        return -1;
	    }

		// 立体矫正
		cv::Rect roi1, roi2;
	    cv::Mat Q;
	    cv::Mat R,T, R1, P1, R2, P2;
	    fs["R"] >> R;
	    fs["T"] >> T;*/
	    /*
	    double r_vec[3]={0.215008583984570,
	    		0.00175243001934400,
	    		-0.0114780703811160};
	    double R_matrix[9];
	    CvMat pr_vec;
	    CvMat pR_matrix;
	    cvInitMatHeader(&pr_vec,3,1,CV_64FC1,r_vec,CV_AUTOSTEP);
	    cvInitMatHeader(&pR_matrix,3,3,CV_64FC1,R_matrix,CV_AUTOSTEP);
	    cvRodrigues2(&pr_vec, &pR_matrix,0);
	    cv::Mat R=cv::Mat(&pR_matrix,true);

		//Alpha取值为-1时，OpenCV自动进行缩放和平移


cv::stereoRectify( M1, D1, M2, D2, img_size, R, T, R1, R2, P1, P2, Q, 1024, -1, img_size, &roi1, &roi2 );

	   fs.open(matrix_filename, CV_STORAGE_WRITE);
	    	    if(!fs.isOpened())
	    	    {
	    	        std::cout<<"Failed to open file  "<<matrix_filename<<endl;
	    	        return -1;
	    	    }
	    fs<<"R"<<R<<"R1"<<R1<<"R2"<<R2<<"P1"<<P1<<"P2"<< P2;


		// 获取两相机的矫正映射

	    cv::Mat map11, map12, map21, map22;
		cv::initUndistortRectifyMap(M1, D1, R1, P1, img_size, CV_16SC2, map11, map12);
	    cv::initUndistortRectifyMap(M2, D2, R2, P2, img_size, CV_16SC2, map21, map22);*/

	    cv::Mat x1=cv::imread("E:/important/it/stereo/mm3.png");
	    cv::Mat x2=cv::imread("E:/important/it/stereo/mm4.png");
	    //cv::Mat x1=cv::imread("E:/stereo/2.jpg");
	    //cv::Mat x2=cv::imread("E:/stereo/3.jpg");
	    cv::Mat x3=cv::Mat::zeros(x1.rows,x1.cols,CV_8UC1);
	    cv::Mat x4=cv::Mat::zeros(x1.rows,x1.cols,CV_8UC1);
	    cv::Mat x5=cv::Mat::zeros(x1.rows,x1.cols,CV_8UC1);
	    cv::Mat x6=cv::Mat::zeros(x1.rows,x1.cols,CV_8UC1);
	    cv::Mat x7=cv::Mat::zeros(x1.rows,x1.cols,CV_8UC1);
	    //cv::Mat x3=cv::imread("E:/stereo/DISPtest11.jpg");
	    //cv::Mat x4=cv::imread("E:/stereo/DISPtest22.jpg");
	    cv::cvtColor(x1,x3,CV_BGR2GRAY);
	    cv::cvtColor(x2,x4,CV_BGR2GRAY);

	   //hls::Mat<rows,cols,HLS_16SC2> map111,map211;
	   //hls::Mat<rows,cols,HLS_16UC1> map121,map221;
	    GRAY img1,img2,img1r,img2r,imgd,img2rr,img1rrr,img2rrr;
	  // hls::Mat<rows,cols,HLS_8UC3> img1,img2,img1r,img2r,img1rr,img2rr,img1rrr,img2rrr;
	   	cvMat2hlsMat(x3,img1);
	   	cvMat2hlsMat(x4,img2);
	   	arr fbi1[rows*cols],fbo1[rows*cols],fbi2[rows*cols],fbo2[rows*cols],fbo[rows*cols];
	   	hls::Mat2Array<cols,arr,rows,cols,HLS_8UC1>(img1,fbi1,cols);
	   	hls::Mat2Array<cols,arr,rows,cols,HLS_8UC1>(img2,fbi2,cols);
	   	//preL(fbi1,fbo1);
	   	//preR(fbi2,fbo2);
		hls::Array2Mat<cols,arr,rows,cols,HLS_8UC1>(fbo1,cols,img1r);
		hls::Array2Mat<cols,arr,rows,cols,HLS_8UC1>(fbo2,cols,img2r);
	   	hlsMat2cvMat(img1r,x5);
	   	hlsMat2cvMat(img2r,x6);
        //cv::imwrite("E:/important/it/stereo/LFINAL1123457.jpg",x5);
        //cv::imwrite("E:/important/it/stereo/RFINAL1123457.jpg",x6);
        stereo(fbi1,fbi2,fbo);
        hls::Array2Mat<cols,arr,rows,cols,HLS_8UC1>(fbo,cols,imgd);
	   	hlsMat2cvMat(imgd,x7);
        cv::imwrite("E:/important/it/stereo/DISPFINAL.jpg",x7);
	   	/*
	   	cvMat2hlsMat(map11,map111);
	   	cvMat2hlsMat(map12,map121);
	   	cvMat2hlsMat(map21,map211);
	   	cvMat2hlsMat(map22,map221);
	    hls::Remap_linear<32,rows,cols,HLS_8UC1,HLS_8UC1,HLS_16SC2,HLS_16UC1>(img1, img1r, map111, map121);
	    hls::Remap_linear<32,rows,cols,HLS_8UC1,HLS_8UC,HLS_16SC2,HLS_16UC1>(img2, img2r, map211, map221);*/
	    //hls::Duplicate(img1r,img1rr,img1rrr);
	    //hls::Duplicate(img2r,img2rr,img2rrr);
	    //cv::Mat x5=cv::Mat::zeros(x3.rows,x3.cols,CV_8UC3);
	    //cv::Mat x6=cv::Mat::zeros(x3.rows,x3.cols,CV_8UC3);
        /*
	    cv::Mat x7=cv::Mat::zeros(x3.rows,x3.cols,CV_8UC1);
	    const int wsize = 9;
	    const int ndisp_unit = 2;
	    const int ndisp=ndisp_unit*16;
	    hls::StereoBMState<wsize,ndisp,ndisp_unit> bm;
	    //bm.uniquenessRatio=20;
	    //bm.textureThreshold=18;
	    //bm.preFilterCap=13;
		hls::Mat <rows,cols,HLS_16SC1>disp;
		GRAY imgO;
		hls::FindStereoCorrespondenceBM<wsize,ndisp,ndisp_unit,rows,cols,HLS_8UC1,HLS_16SC1>(img1, img2, disp, bm);
	    //hls::ConvertScaleAbs<HLS_16SC1,HLS_8UC1,rows,cols>(disp,imgO,255/(ndisp*16.));
		hls::ConvertScaleAbs<HLS_16SC1,HLS_8UC1,rows,cols>(disp,imgO,255/(ndisp*16.));
		hlsMat2cvMat(imgO,x7);
        cv::imwrite("E:/important/it/stereo/FINAldisp6.jpg",x7);
		//hls::ConvertScaleAbs<HLS_16SC1,HLS_8UC1,rows,cols>(disp,imgO);
		/*
	    cv::Mat x1=cv::imread("E:/important/it/stereo/LR.jpg");
	    cv::Mat x2=cv::imread("E:/important/it/stereo/RR.jpg");
	    cv::Mat x3=cv::Mat::zeros(x1.rows,x1.cols,CV_8UC1);
	    cv::Mat x4=cv::Mat::zeros(x1.rows,x1.cols,CV_8UC1);
	    //cv::remap(x1, x3, map11, map12, CV_INTER_LINEAR);
	    //cv::remap(x2, x4, map21, map22, CV_INTER_LINEAR);
	    cv::Mat x5=cv::Mat::zeros(x1.rows,x1.cols,CV_8UC1);
	    //cv::Mat x6=cv::Mat::zeros(x1.rows,x1.cols,CV_8UC1);
	    cv::cvtColor(x1,x3,CV_BGR2GRAY);
	    cv::cvtColor(x2,x4,CV_BGR2GRAY);

	    GRAY img1r, img2r;
   	    cvMat2hlsMat(x3,img1r);
   	    cvMat2hlsMat(x4,img2r);
	    const int wsize = 9;
	    const int ndisp_unit = 2;
	    const int ndisp=ndisp_unit*16;
	    hls::StereoBMState<wsize,ndisp,ndisp_unit> bm;
	    //bm.uniquenessRatio=18;
	    //bm.textureThreshold=18;
	    //bm.preFilterCap=13;
		hls::Mat <rows,cols,HLS_16SC1>disp;
		GRAY imgO;
		hls::FindStereoCorrespondenceBM<wsize,ndisp,ndisp_unit,rows,cols,HLS_8UC1,HLS_16SC1>(img1r, img2r, disp, bm);
	    //hls::ConvertScaleAbs<HLS_16SC1,HLS_8UC1,rows,cols>(disp,imgO,255/(ndisp*16.));
		hls::ConvertScaleAbs<HLS_16SC1,HLS_8UC1,rows,cols>(disp,imgO,255/(ndisp*16.));
		hlsMat2cvMat(imgO,x5);
        cv::imwrite("E:/important/it/stereo/dispCCC3.jpg",x5);
	    /*
	    cv::Mat x7=cv::Mat::zeros(x1.rows,x1.cols,CV_8UC1);
	    cv::cvtColor(x1,x3,CV_BGR2GRAY);
	    cv::cvtColor(x2,x4,CV_BGR2GRAY);
	    const int wsize = 19;
	    const int ndisp_unit = 40;
	    const int ndisp=ndisp_unit*16;
	    hls::StereoBMState<wsize,ndisp,ndisp_unit> bm;
	    //bm.uniquenessRatio=18;
	    //bm.textureThreshold=18;
	    //bm.preFilterCap=13;
		hls::Mat <720,1280,HLS_16SC1>disp;
		hls::Mat <720,1280,HLS_8UC1> imgO, img1rr, img2rr;
   	    cvMat2hlsMat(x3,img1rr);
   	    cvMat2hlsMat(x4,img2rr);
		hls::FindStereoCorrespondenceBM<wsize,ndisp,ndisp_unit,720,1280,HLS_8UC1,HLS_16SC1>(img1rr, img2rr, disp, bm);
	    hls::ConvertScaleAbs<HLS_16SC1,HLS_8UC1,720,1280>(disp,imgO,255/(ndisp*16.));
	    hlsMat2cvMat(imgO,x7);
	    cv::imwrite("E:/important/it/stereo/dispCCC.jpg",x7);*/
        /*
	    cv::Mat disp1, disp2;
        cv::StereoBM bm1;

    	int unitDisparity = 2;//40
    	int numberOfDisparities = unitDisparity * 16;
    	//bm1.state->roi1 = roi1;
        //bm1.state->roi2 = roi2;
        bm1.state->preFilterCap = 13;
        bm1.state->SADWindowSize = 7;                                     // 窗口大小
        bm1.state->minDisparity = 0;                                       // 确定匹配搜索从哪里开始  默认值是0
        bm1.state->numberOfDisparities = numberOfDisparities;                // 在该数值确定的视差范围内进行搜索
        bm1.state->textureThreshold = 10;//10                                  // 保证有足够的纹理以克服噪声
        bm1.state->uniquenessRatio = 15;     //10                               // !!使用匹配功能模式
        bm1.state->speckleWindowSize = 13;   //13                             // 检查视差连通区域变化度的窗口大小, 值为 0 时取消 speckle 检查
        bm1.state->speckleRange = 32;    //32                                  // 视差变化阈值，当窗口内视差变化大于阈值时，该窗口内的视差清零，int 型
        bm1.state->disp12MaxDiff = -1;//-1
        bm1(x3, x4, disp1);
        disp1.convertTo(disp2, CV_8U, 255/(numberOfDisparities*16.));
        //cvNormalize( disp1, disp2, 0, 256, CV_MINMAX );
        //cv::imwrite("E:/important/it/stereo/LR.jpg",x3);
        //cv::imwrite("E:/important/it/stereo/RR.jpg",x4);
        cv::imwrite("E:/important/it/stereo/dispDDD3.jpg",disp2);
        /*
	    cv::Mat x1=cv::imread("E:/important/it/stereo/mm4.png");
	    cv::Mat x2=cv::imread("E:/important/it/stereo/mm3.png");

	    cv::Mat x3=cv::Mat::zeros(x1.rows,x1.cols,CV_8UC1);
	    cv::Mat x4=cv::Mat::zeros(x1.rows,x1.cols,CV_8UC1);

	    cv::Mat x5=cv::Mat::zeros(x1.rows,x1.cols,CV_8UC1);
	    cv::Mat x6=cv::Mat::zeros(x1.rows,x1.cols,CV_8UC1);
	    cv::Mat x7=cv::Mat::zeros(x1.rows,x1.cols,CV_8UC1);
	    cv::cvtColor(x1,x3,CV_BGR2GRAY);
	    cv::cvtColor(x2,x4,CV_BGR2GRAY);

	    arr input11[rows*cols],input22[rows*cols],output11[rows*cols],output22[rows*cols];
	    arr  outputDd[rows*cols];
	    GRAY input1, input2, outputD, OUTPUTL, OUTPUTR;
	    cvMat2hlsMat(x3,input1);
	    cvMat2hlsMat(x4,input2);
	    hls::Mat2Array<160,arr,120,160,HLS_8UC1>(input1,input11,cols);
	    hls::Mat2Array<cols,arr,rows,cols,HLS_8UC1>(input2,input22,cols);
	    preL(input11,output11);
	    preR(input22,output22);
	    stereo(input11,
	    	   input22,
	    	   outputDd);
	    //AXIvideo2cvMat(outputD,x5);
	    hls::Array2Mat<cols,arr,rows,cols,HLS_8UC1>(outputDd,cols,outputD);
	    hls::Array2Mat<cols,arr,rows,cols,HLS_8UC1>(output11,cols,OUTPUTL);
	    hls::Array2Mat<cols,arr,rows,cols,HLS_8UC1>(output22,cols,OUTPUTR);
	    hlsMat2cvMat(outputD,x5);
	    hlsMat2cvMat(OUTPUTL,x6);
	    hlsMat2cvMat(OUTPUTR,x7);
	    cv::imwrite("E:/important/it/stereo/6.jpg",x5);
	    cv::imwrite("E:/important/it/stereo/6l.jpg",x6);
	    cv::imwrite("E:/important/it/stereo/6r.jpg",x7);
	   /*
	        cv::Mat x1=cv::imread("E:/important/it/stereo/mm3.png");
		    cv::Mat x2=cv::imread("E:/important/it/stereo/mm4.png");

		    cv::Mat x5=cv::Mat::zeros(x1.rows,x1.cols,CV_8UC1);
		    cv::Mat x6=cv::Mat::zeros(x1.rows,x1.cols,CV_8UC1);
			hls::Mat<rows,cols,HLS_8UC3> x3;
			hls::Mat<rows,cols,HLS_8UC3> x4;
			cvMat2hlsMat(x1,x3);
			cvMat2hlsMat(x2,x4);
			GRAY img1, img2;
		    hls::CvtColor<HLS_RGB2GRAY,HLS_8UC3,HLS_8UC1,rows,cols>(x3,img1);
		    hls::CvtColor<HLS_RGB2GRAY,HLS_8UC3,HLS_8UC1,rows,cols>(x4,img2);
            hlsMat2cvMat(img1,x5)
            hlsMat2cvMat(img2,x6);
		    cv::imwrite("E:/important/it/stereo/kkkklll.jpg",x5);
		    cv::imwrite("E:/important/it/stereo/kkkkrrr.jpg",x6);  */

	    /*
	    hls::Mat<rows,cols,HLS_16SC2> map11,map21;
	    hls::Mat<rows,cols,HLS_12UC1> map12,map22;
	    getMap(map11,map12,map21,map22);
	    GRAY img1,img2,img1r,img2r;
	    cvMat2hlsMat(x3,img1);
	    cvMat2hlsMat(x4,img2);
	    hls::Remap_linear<32,rows,cols,HLS_8UC1,HLS_8UC1,HLS_16SC2,HLS_12UC1>(img1, img1r, map11, map12);
	    hls::Remap_linear<32,rows,cols,HLS_8UC1,HLS_8UC1,HLS_16SC2,HLS_12UC1>(img2, img2r, map21, map22);
	    hlsMat2cvMat(img1r,x5);
	    hlsMat2cvMat(img2r,x6);
	    cv::imwrite("E:/important/it/stereo/finalBESTll12345.jpg",x5);
	    cv::imwrite("E:/important/it/stereo/finalBESTrr12345.jpg",x6);
	    */
        /*
	    cv::Mat map22=cv::Mat::zeros(rows,cols,CV_16UC1);
	    	cv::Mat map12=cv::Mat::zeros(rows,cols,CV_16UC1);
	    	cv::Mat map11=cv::Mat::zeros(rows,cols,CV_16SC2);
	        cv::Mat map21=cv::Mat::zeros(rows,cols,CV_16SC2);
	    	//cvMat2AXIvideo(x3,input1);
	        //cvMat2AXIvideo(x4,input2);
	        //cvMat2hlsMat(x3,input1);
	        //cvMat2hlsMat(x4,input2);
	        hls::Mat<rows,cols,HLS_16SC2> m11,m21;
	        hls::Mat<rows,cols,HLS_16UC1> m12,m22;
	        getMap(m11,m12,m21,m22);
	        hlsMat2cvMat(m11,map11);
	        hlsMat2cvMat(m12,map12);
	        hlsMat2cvMat(m21,map21);
	        hlsMat2cvMat(m22,map22);


	        cv::Mat img1r, img2r,disp;
	        cv::remap(x3, img1r, map11, map12, CV_INTER_LINEAR);
	        cv::remap(x4, img2r, map21, map22, CV_INTER_LINEAR);
	        //cv::imwrite("E:/important/it/stereo/lllll.jpg",img1r);
	        //cv::imwrite("E:/important/it/stereo/rrrrr.jpg",img2r);
	    	// 初始化 stereoBMstate 结构体
	        cv::StereoBM bm;

	    	int unitDisparity = 3;//40
	    	int numberOfDisparities = unitDisparity * 16;
	    	bm.state->roi1 = roi1;
	        bm.state->roi2 = roi2;
	        bm.state->preFilterCap = 13;
	        bm.state->SADWindowSize = 9;                                     // 窗口大小
	        bm.state->minDisparity = 0;                                       // 确定匹配搜索从哪里开始  默认值是0
	        bm.state->numberOfDisparities = numberOfDisparities;                // 在该数值确定的视差范围内进行搜索
	        bm.state->textureThreshold = 10;//10                                  // 保证有足够的纹理以克服噪声
	        bm.state->uniquenessRatio = 15;     //10                               // !!使用匹配功能模式
	        bm.state->speckleWindowSize = 13;   //13                             // 检查视差连通区域变化度的窗口大小, 值为 0 时取消 speckle 检查
	        bm.state->speckleRange = 25;    //32                                  // 视差变化阈值，当窗口内视差变化大于阈值时，该窗口内的视差清零，int 型
	        bm.state->disp12MaxDiff = -1;
	        bm(img1r, img2r, disp);
	        disp.convertTo(disp, CV_8U, 255/(numberOfDisparities*16.));
	        cv::imwrite("E:/important/it/stereo/DISPtest.jpg",disp);
        */

        /*
	    hls::Mat<rows,cols,HLS_16SC2> map11h,map21h;
	    hls::Mat<rows,cols,HLS_16UC1> map12h,map22h;
	    cvMat2hlsMat(map11,map11h);
	    cvMat2hlsMat(map12,map12h);
	    cvMat2hlsMat(map21,map21h);
	    cvMat2hlsMat(map22,map22h);
        */

    //AXI_STREAML input1;
    //AXI_STREAMR input2;
	//AXI_STREAMO outputD;


	//hls::Mat<rows,cols,HLS_8UC1> input1,input2,outputD;


    /*
            fs.open("E:/important/it/stereo/map11.yml", CV_STORAGE_WRITE);
    	    if(!fs.isOpened())
    	    {
    	        std::cout<<"Failed to open file "<<"ERR"<<endl;
    	        return -1;
    	    }
    		//cv::Mat M1, D1, M2, D2;      //左右相机的内参数矩阵和畸变系数
    	    fs<<"m11"<<map11;

    	    fs.open("E:/important/it/stereo/map12.yml", CV_STORAGE_WRITE);
    	       	    if(!fs.isOpened())
    	       	    {
    	       	        std::cout<<"Failed to open file "<<"ERR"<<endl;
    	       	        return -1;
    	       	    }
    	       		//cv::Mat M1, D1, M2, D2;      //左右相机的内参数矩阵和畸变系数
    	       	    fs<<"m12"<<map12;
    	    fs.open("E:/important/it/stereo/map21.yml", CV_STORAGE_WRITE);
    	       	    	    if(!fs.isOpened())
    	       	    	    {
    	       	    	        std::cout<<"Failed to open file "<<"ERR"<<endl;
    	       	    	        return -1;
    	       	    	    }
    	       	    		//cv::Mat M1, D1, M2, D2;      //左右相机的内参数矩阵和畸变系数
    	       	    	    fs<<"m21"<<map21;
    	    fs.open("E:/important/it/stereo/map22.yml", CV_STORAGE_WRITE);
    	       	    	     	       	    	    if(!fs.isOpened())
    	       	    	     	       	    	    {
    	       	    	     	       	    	        std::cout<<"Failed to open file "<<"ERR"<<endl;
    	       	    	     	       	    	        return -1;
    	       	    	     	       	    	    }
    	       	    	     	       	    		//cv::Mat M1, D1, M2, D2;      //左右相机的内参数矩阵和畸变系数
    	       	    	     	       	    	    fs<<"m22"<<map22;

    //hls::Mat <rows,cols,HLS_16SC1>disp;
   	//hls::Mat <rows,cols,HLS_8UC1>disp8;

    //hls::ConvertScaleAbs(disp,outputD,255/(240*16.));    // 将16位符号整形的视差矩阵转换为8位无符号整形矩阵
	//IplImage2AXIvideo(x3,input1);


	//hlsMat2cvMat(disp,x6);
	//x6.convertTo(x5,CV_8U,255/(240*16.));
	//hlsMat2cvMat(img1r,x6);
	//hlsMat2cvMat(outputD,x5);
	//AXIvideo2cvMat(outputD,x5);
	//hlsMat2IplImage(outputD,x5);;
    //hlsMat2cvMat(input1,x3);
	//cv::imwrite("E:/stereo/DISP_final.jpg", x5);


	//cv::Mat disp=cv::Mat::zeros(rows,cols,CV_16SC1);
	//bm(img1r, img2r, disp);
	//disp.convertTo(disp8, CV_8U, 255/(numberOfDisparities*16.));
	//hls::Mat<rows,cols,HLS_16SC1> tmp;
	//hls::Mat<rows,cols,HLS_8UC1> outputD;
	//cvMat2hlsMat(disp,tmp);
	//hls::ConvertScaleAbs(tmp,outputD,255/(numberOfDisparities*16.));
	//hlsMat2cvMat(outputD,x5);
	//cv::imwrite("DISP11ggqq.jpg",x5);
     */
	return 0;
}
