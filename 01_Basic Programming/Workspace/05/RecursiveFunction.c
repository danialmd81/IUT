#include<stdio.h>

int recursion(int n,int i)
{
    int a;
    if(i==0)
    {
        scanf("%d",&a);
        recursion(n,i+1);
        printf("%d",a);
    }
    if(i>0&&i<n)
    {
        scanf("%d",&a);
        recursion(n,i+1);
        printf("%d --> ",a);
    }
    
    
}

int main()
{
    int n;
    scanf("%d",&n);
    if(n>0)
    recursion(n,0);
}
