#include <stdio.h>

int main(void)
{
    int a[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

    int i=0,j=0;
    for (i=0;i<4;++i)
    {
        for (j=0;j<4;++j)
            printf("%d\t",a[i][j]);
        printf("\n");
    }
    int ** b=(int **)a;

    i=0.j=0;
    for (i=0;i<4;++i)
    {
        for (j=0;j<4;++j)
            printf("%d\t",b[i][j]);
        printf("\n");
    }
    return 0;
}

