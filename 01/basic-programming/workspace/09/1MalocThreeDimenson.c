#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int x,y,z;
    scanf("%d %d %d",&x,&y,&z);
    int ***arr=(int***)malloc(x*sizeof(int**));
    for(int i=0;i<x;i++)
    {
        arr[i]=(int**)malloc(y*sizeof(int*));
    }
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            arr[i][j]=(int*)malloc(z*sizeof(int));
        }
    }

}