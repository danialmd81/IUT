#include <stdio.h>
#include<stdlib.h>
int  MAX(int *arr,int n)
{
    int max = arr[0];
    for(int i = 0;i <n;i++) 
    {
        if(max < arr[i]) 
        {
            max = arr[i];
        }
    }
    return max;
}

int  MIN(int* arr,int n)
{
    int min = arr[0];
    for(int i = 0;i <n;i++) 
    {
        if(min > arr[i]) 
        {
            min = arr[i];
        }
    }
    return min;
}
int main()
{
    int cake ,student;
    scanf("%d %d",&cake,&student);
    int* cakes_price=malloc(cake*sizeof(int));
    for(int i=0;i<cake;i++)
    {
        scanf("%d",&cakes_price[i]);
    }

    if(student>2)
    {
        printf("%d",MIN(cakes_price,cake));
    }

    else if(student==2)
    {
        if(cakes_price[0]>cakes_price[cake-1])
        printf("%d",cakes_price[cake-1]);
        else
        printf("%d",cakes_price[0]);
    }

    else
    {
        printf("%d",MAX(cakes_price,cake));
    }
}