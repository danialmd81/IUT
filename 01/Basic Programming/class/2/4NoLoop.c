#include<stdio.h>

int recursion(int n)
{
    char a[100];
    if(n==0)
    return 0;
        scanf("%s",&a);
        recursion(n-1);
        printf("%s\n",a);
}

int main()
{
    int n;
    scanf("%d",&n);
    recursion(n);
}
