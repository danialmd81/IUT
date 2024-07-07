#include <stdio.h>
#include<stdlib.h>
void CreateMatrix(int mi , int mj , int***arr )
{
    *arr = (int**) malloc(mi*sizeof(int*));
    for(int i=0 ; i<mj; i++)
    {
        (*arr)[i]=(int*)malloc(mj*sizeof(int));
    }

}
void FillMatrix( int mi,int mj,int**arr )
{
    for(int i=0;i<mi;i++)
    {   
        for(int j=0;j<mj;j++)
        {
            scanf("%d",&arr[i][j]);
        }
        
    }
}
void PrintMatrix( int mi,int mj,int**arr )
{
    for(int i=0;i<mi;i++)
    {
        for(int j=0;j<mj;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
void MUL(int ia,int ja,int jb,int **arr1,int **arr2,int **arrs)
{
    for(int i=0;i<ia;i++)
        { 
            for(int j=0;j<jb;j++)
            {
                arrs[i][j]=0;
                for(int k=0;k<ja;k++)
                {
                    arrs[i][j]=arrs[i][j]+(arr1[i][k]) * (arr2[k][j]);
                }         
            }
        }
}
void memory_leak(int*** arr,int mi)
{
    for(int i=0;i<mi;i++)
    {
        free((*arr)[i]);
    }
}
int main()
{
    int ai,aj,bi,bj;
    int** arr1;
    int** arr2;
    int** arrs;
    scanf("%d%d%d",&ai,&aj,&bj);
    bi=aj;
    CreateMatrix(ai,aj,&arr1);
    CreateMatrix(bi,bj,&arr2);
    CreateMatrix(ai,bj,&arrs);
    FillMatrix(ai,aj,arr1);
    FillMatrix(bi,bj,arr2);
    MUL(ai,aj,bj,arr1,arr2,arrs);
    PrintMatrix(ai,bj,arrs);
    memory_leak(&arr1,ai);
    memory_leak(&arr2,ai);
    memory_leak(&arrs,ai);
}
