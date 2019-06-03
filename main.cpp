#include <opencv2/highgui.hpp>
#include <opencv2/ximgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <opencv2/xfeatures2d/nonfree.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/cudafeatures2d.hpp>
#include <opencv2/xfeatures2d/cuda.hpp>
#include <opencv2/cudacodec.hpp>
#include <opencv2/cudaimgproc.hpp>

#include <iostream>
#include <stdio.h>
//#include <chrono>
#include <vector>
#include <string>
#include <time.h>
#include <ctime>

using namespace cv;
using namespace std;
using namespace cv::xfeatures2d;
using namespace cv::cuda;
 
int main()
{
  double alpha = 0.5; double beta; double input;
  Mat src1, src2, dst;
  /// Ask the user enter alpha
    cout << " Simple Linear Blender " << endl;
    cout << " ----------------------- " <<endl;
    cout << " * Enter alpha [0-1]: ";
    cin >> input;
  /// We use the alpha provided by the user if it is between 0 and 1
  if (input >= 0.0 && input <= 1.0)
  {
    alpha = input;
  }
  /// Read image ( same size, same type )
  src1 = imread("1.jpg");
  src2 = imread("2.jpg");
  if (!src1.data) 
  {
    cout<<" Error loading src1";
    return -1; 
  }
 
  if (!src2.data) 
  {
    cout<<" Error loading src2 \n";
    return -1;
  }
  /// Create Windows
 
  namedWindow("Blend1",1);
  imshow("Blend1", src1);
 
 
  namedWindow("Blend2", 1);
  imshow("Blend2", src2);
 
  namedWindow("Linear Blend", 1);
  beta = (1.0 - alpha);
  //addWeighted(src1, alpha, src2, beta, 0.0, dst);
 
  //imshow("Linear Blend", dst);
  waitKey(0);
  return 0;
}