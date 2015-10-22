#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<iostream>
#include<string>

using namespace cv;

/// 全局变量
Mat src, dst;
int top, bottom, left, right;
int borderType;
Scalar value;
std::string window_name = "copyMakeBorder Demo";
RNG rng(12345);

/** @函数 main  */
int main()
{

  int c;

  /// 装载图像
  src = imread("12W4O5101cP-245915.jpg" );

  if( !src.data )
  { return -1;
  }



  /// 创建显示窗口
  namedWindow( window_name, CV_WINDOW_AUTOSIZE );

  /// 初始化输入参数
  top = (int) (0.05*src.rows); bottom = (int) (0.05*src.rows);
  left = (int) (0.05*src.cols); right = (int) (0.05*src.cols);
  dst = src;

  imshow( window_name, dst );

  while( true )
    {
      c = waitKey(500);

      if( (char)c == 27 )
        { break; }
      else if( (char)c == 'c' )
        { borderType = BORDER_CONSTANT; }
      else if( (char)c == 'r' )
        { borderType = BORDER_REPLICATE; }

      value = Scalar( rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255) );
      copyMakeBorder( src, dst, top, bottom, left, right, borderType, value );

      imshow( window_name, dst );
    }

  return 0;
}
