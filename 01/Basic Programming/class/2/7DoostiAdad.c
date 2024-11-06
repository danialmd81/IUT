#include <stdio.h>
#include<stdlib.h>
int main()
{
    int n,even=0,prime=0,k;
    int *arr;
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        if(arr[i] % 2 == 0)
        even++;

        else
        prime++;
    }
    if(prime==0||even==0)
        printf("Yes");
    
    else if(prime==even&&even%2==0)
        printf("Yes");
    
    else
    {
        k=0;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                if(abs(arr[i]-arr[j])==1)
                k++;

        if(k==1)
        printf("Yes");
    
        else if(k!=1)
        printf("No");
    }
    
}