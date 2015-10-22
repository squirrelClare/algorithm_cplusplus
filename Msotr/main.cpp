#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#define MAXSIZE 10000
/* 归并排序********************************** */

/* 将有序的SR[i..m]和SR[m+1..n]归并为有序的TR[i..n] */
void Merge(int SR[],int TR[],int i,int m,int n)
{
    int j,k,l;//i,j供SR使用,k供TR
    for(j=m+1,k=i;i<=m && j<=n;k++)	/* 将SR中记录由小到大地并入TR */
    {
        if(SR[i]<SR[j])
            TR[k]=SR[i++];
        else
            TR[k]=SR[j++];
    }
    --k;
    --i;
    --j;
    if(i<=m)
    {
        for(l=1;l<=m-i;l++)
            TR[k+l]=SR[i+l];		/* 将剩余的SR[i..m]复制到TR */
    }
    if(j<=n)
    {
        for(l=1;l<=n-j;l++)
            TR[k+l]=SR[j+l];		/* 将剩余的SR[j..n]复制到TR */
    }
}


/* 递归法 */
/* 将SR[s..t]归并排序为TR1[s..t] */
void MSort(int SR[3],int TR1[3],int s, int t)
{
    int m;
    int TR2[MAXSIZE+1];
    if(s==t)
        TR1[s]=SR[s];
    else
    {
        m=(s+t)/2;				/* 将SR[s..t]平分为SR[s..m]和SR[m+1..t] */
        MSort(SR,TR2,s,m);		/* 递归地将SR[s..m]归并为有序的TR2[s..m] */
        MSort(SR,TR2,m+1,t);	/* 递归地将SR[m+1..t]归并为有序的TR2[m+1..t] */
        Merge(TR2,TR1,s,m,t);	/* 将TR2[s..m]和TR2[m+1..t]归并到TR1[s..t] */
    }
}

int main()
{
    //int a[9] = {50,10,90,30,70,40,80,60,20};
    int a[3] = {50,10,90};
    int b[3];

    //int i = 0;
    //printf("Hello world!%d,%d\n",a[i++],i);
    MSort(a,b,0,2);
    for(int i=0;i<3;++i)
    {
        std::cout<<b[i]<<'\t';
    }
    return 0;
}
