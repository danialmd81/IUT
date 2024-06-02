#include<stdio.h>
int dimen,arr[256][256] ,i,j;
int PrintImage(int dimen , int arr)
{
    printf("%d ",arr);
}
int Convert2Negative(int arr)
{
    return arr=255-arr;
}
int main()
{
    scanf("%d\n",&dimen);
    for(i =0 ; i<dimen; i++)
    {
        for(j =0 ; j<dimen; j++)
        {
            scanf("%d",&arr[i][j]);
            arr[i][j]=Convert2Negative(arr[i][j]);
            //printf("%d ",arr[i][j]);
            PrintImage(dimen,arr[i][j]);
        }
        printf("\n");
    }
    
}