#include "maxarray.h"
#include<QDebug>

MaxArray::MaxArray()
{
}

MaxArray::~MaxArray()
{
}

Result MaxArray::MaxArrayReturn( QList<double> listInput)//程序初始入口.
{

    int low=0;
    int high=listInput.length()-1;
    int mid=0;
     Result *lResult,*rResult,*cResult,*re;
     lResult=new Result();//左部分最大子数组
     rResult=new Result();//右部分最大子数组
     cResult=new Result();//包含中间项的最大子数组
     re=new Result();
    if(low==high)//当数组只有一个元素.
    {
        Result *re=new Result();
        re->lowAns=low;
        re->highAns=high;
        re->sumAns=listInput.at(low);
        return *re;
            }
    else
        {//当数组有两个以上的元素的时候,继续分三种情况寻找最大子数组.
            mid=(int)((low+high)/2);
           * lResult=this->FindLeft(low,mid,listInput);
             *rResult=this->FindRight(mid+1,high,listInput);
             *cResult=this->FindCross(low,mid,high,listInput);

    if((lResult->sumAns>=rResult->sumAns)&(lResult->sumAns>=cResult->sumAns))
     {   return *lResult;}
    else
    { if((rResult->sumAns>=lResult->sumAns)&(rResult->sumAns>=cResult->sumAns))
        {return *rResult;}
    else
        {return *cResult;}
    }

}

}

Result MaxArray::FindLeft(int low, int high, QList<double> listInput)//寻找左部分最大子数组
{
    int mid;
    Result *lResult,*rResult,*cResult,*re;
    lResult=new Result();//左侧最大子数组.
    rResult=new Result();//右侧最大子数组.
    cResult=new Result();//中间最大子数组.
    re=new Result();
    if(low==high)//当数组只有一个元素的时候.
    {

        re->lowAns=low;
        re->highAns=high;
        re->sumAns=listInput.at(low);
        return *re;
    }
    else{//当数组有两个以上的元素的时候,继续寻找最大子数组.
           mid=(int)((low+high)/2);
        *lResult=this->FindLeft(low,mid,listInput);
         *rResult=this->FindRight(mid+1,high,listInput);
         *cResult=this->FindCross(low,mid,high,listInput);

      //比较三种情况的数值大小并返回最大值.
    if((lResult->sumAns>=rResult->sumAns)&(lResult->sumAns>=cResult->sumAns))
     {   return *lResult;}
    else
    { if((rResult->sumAns>=lResult->sumAns)&(rResult->sumAns>=cResult->sumAns))
        {return *rResult;}
    else
        {return *cResult;}
    }
}
}

Result MaxArray::FindRight(int low, int high, QList<double> listInput)//寻找左部分最大子数组
{

    int mid=0;
    Result *lResult,*rResult,*cResult,*re;
    lResult=new Result();//左侧最大子数组.
    rResult=new Result();//右侧最大子数组.
    cResult=new Result();//中间最大子数组.
    re=new Result();
    if(low==high)//当数组只有一个元素的时候.
    {
        re->lowAns=low;
        re->highAns=high;
        re->sumAns=listInput.at(low);
        return *re;
    }
    else{//当数组有两个以上的元素的时候.
        mid=(int)((low+high)/2);

        *lResult=this->FindLeft(low,mid,listInput);
         *rResult=this->FindRight(mid+1,high,listInput);
         *cResult=this->FindCross(low,mid,high,listInput);

    if((lResult->sumAns>=rResult->sumAns)&(lResult->sumAns>=cResult->sumAns))
     {   return *lResult;}
    else
    { if((rResult->sumAns>=lResult->sumAns)&(rResult->sumAns>=cResult->sumAns))
        {return *rResult;}
    else
        {return *cResult;}
    }
}

}

Result MaxArray::FindCross(int low,  int mid, int high,QList<double> listInput)//寻找包含中间项部分最大子数组
{
    double lSum,rSum,sum1,sum2;
    int maxLeft=0,maxRight=0;
    Result *cResult;
    sum1=0;
    lSum=-1000;
    rSum=-1000;
    for(int i=mid;i>=low;i--)//mid左边的最大子数组
    {
              sum1=sum1+listInput.at(i);
        if(sum1>lSum)
        {
            lSum=sum1;
            maxLeft=i;
        }

    }

    sum2=0;
    for(int j=mid+1;j<=high;j++)//mid右边的最大子数组
    {

        sum2=sum2+listInput.at(j);
        if(sum2>rSum)
        {
            rSum=sum2;
            maxRight=j;
        }

    }

    cResult=new Result();
    cResult->lowAns=maxLeft;
    cResult->highAns=maxRight;
    cResult->sumAns=lSum+rSum;

    return *cResult;
}

QList<double> MaxArray::InputData(QString path)//从文件中读取股票走势.
{
    QFile file(path);//path为文件路径.
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream in(&file);
   QStringList listStr= in.readAll().split(",");
   qDebug()<<listStr;
   QList<double> list;
   for(int i=0;i<listStr.length();i++)
   {
   list.append(listStr.at(i).toInt());
   }
   return list;
}
