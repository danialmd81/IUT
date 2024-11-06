#include<stdio.h>
int ncards=0;
int rt(int n)
{
    int h;
    if(n==0)
    return 0;
    scanf("%d",&h);
    ncards=ncards+h*(h-1);
    rt(n-1);
}
int main()
{
    int n,h,maxh;
    scanf("%d",&n);
    rt(n);
    for(maxh=0;;maxh++)
    {
        if(maxh*(maxh-1)>=ncards)
        break;
    }
    printf("%d",maxh);
}