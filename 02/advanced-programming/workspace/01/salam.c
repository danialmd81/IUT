#include<stdio.h>

int main()
{
    int n=0;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        printf("Salam\t");
        if(i%10==0)
        printf("\n");
    }
}