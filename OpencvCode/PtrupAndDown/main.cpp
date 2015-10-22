#include <QCoreApplication>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<QString>
#include<QDebug>
#include<iostream>

using namespace cv;
Mat src,dst,temp;
QString windowName="Pyramids Demo";


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    src=imread("C:\\Users\\lenovo\\Desktop\\12W4O5101cP-245915.jpg");
    if (!src.data)
    {
        qDebug()<<"No data! -- Exiting the program \n";
        return -1;
    }


    temp=src;
    dst=temp;
    namedWindow(windowName.toStdString(),CV_WINDOW_AUTOSIZE);
    imshow(windowName.toStdString(),dst);

    while(true)
    {
        int c;
        c=waitKey(10);
        if ((char)c=='o')
        {
            break;
        }
        else if ((char)c=='u')
        {
            pyrUp(temp,dst,cv::Size(temp.cols*2,temp.rows*2));
            qDebug()<<"** Zoom In: Image x 2 \n";
        }
        else if((char)c=='d')
        {
            pyrDown(temp,dst,cv::Size(temp.cols/2,temp.rows/2));
            qDebug()<<"** Zoom Out: Image / 2 \n";
        }
        imshow(windowName.toStdString(),dst);
        temp=dst;
    }

    return a.exec();
}
