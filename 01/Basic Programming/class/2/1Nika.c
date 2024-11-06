#include<stdio.h>
int main()
{
    int count,h,min;
    char h1,h2,min1,min2;
    scanf("%d:%d",&h,&min);
    for(count=0;;min++,count++)
    {
        if(min==60)
        {
            ++h;
            min=0;
        }
        if(h==24)
        {
            h=0;
        }
        h1=h/10;
        h2=h%10;
        min1=min/10;
        min2=min%10;
        if(h1==min2&&h2==min1)
        break;
    }
    printf("%d",count);
}