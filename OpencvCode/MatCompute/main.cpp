#include <QCoreApplication>
#include<opencv2/core/core.hpp>
#include<iostream>
#include<vector>
using namespace cv;
using namespace std;

Mat f(Mat x){
    return x;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
//    cv::Mat m1(1,4,CV_64F,cv::Scalar::all(1));
//    cv::Mat m=m1.t()*m1;
//    std::cout<<m<<std::endl;
//    std::cout<<m1*m1.t()<<std::endl;


//    std::vector<double> vec(10,5);
//    cv::Mat vecMat(vec);
//    vecMat.resize(2);
//    std::cout<<vecMat<<std::endl;

//    cv::Mat mat1(2,2,CV_64F,cv::Scalar(2));
//    cv::Mat mat2(2,2,CV_64F,cv::Scalar(0));
//    double sour[]={1,2,3,4,5,6,7,8,9,10};
//    cv::Mat mat3(2,5,CV_64F,sour);
//    std::cout<<mat3;
//    cv::Vec myVec(10,)

//    // allocates a 30x40 floating-point matrix  // CV_32F
//    Mat A(30, 40, DataType<float>::type);
//    Mat B = Mat_<std::complex<double> >(3, 3);
//    // the statement below will print 6, 2 /*, that is depth == CV_64F, channels == 2*/  CV_64FC2
//    cout << B.depth() << ", " << B.channels() << endl;
//    cout<<B.total()<<endl;
//    cv::Vec<int,9>* v=new Vec<int,9>(465,465,498,798,465,165,4,74,6);
//    cout<<*v<<endl;

//    Mat m1(3,3,CV_64F,Scalar(2));
//    Mat m2=f(m1);
//    m2.at<double>(1,1)=7;
//    cout<<m1<<endl;
//    m2=Mat::ones(5,6,CV_64F);
//    cout<<m2<<endl;
//    cout<<m1<<endl;

     double sour[]={1,10,3,2,4,5,6,7,8,9};
     vector<double> vec(sour,sour+10);
     cv::Mat mat3(2,5,CV_64F,sour);
     cv::Mat mat4(vec);
      cout<<mat3<<endl;
     std::sort(mat3.begin<double>(),mat3.end<double>());
     cout<<mat3<<endl;

     cout<<mat4<<endl;
     cout<<mat3.at<double>(1,2)<<endl;
//     double minv=0;
//     cv::min(minv, mat3);
//     cout<<sum(mat3)<<endl;//矩阵求和
//     cout<<mean(mat3)<<endl;//矩阵求均值
//     cv::Mat m,s;
//     meanStdDev(mat3,m,s);
//     cout<<m<<"***"<<s<<endl;//矩阵求均方差
//     cout<<norm(mat3)<<endl;//矩阵求范数
//     cv::exp(mat3,m);
//     cout<<m<<s<<endl;

//     cout<<trace(mat3)<<endl;
//     eigen(mat3,m);
//     cout<<m<<endl;

//     uchar v1=89;
//     int v2= v1*(-878);
//     cout<<v1*(-6)<<endl;
//     cout<<v1*78<<endl;
//     cout<<v2<<endl;
//     cout<<static_cast<int>(v1)<<endl;

//     double x=98;
//     cout<<(int)(static_cast<uchar>(x));

    return a.exec();
}
