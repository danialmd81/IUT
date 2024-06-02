#include <stdio.h>
int main()
{
 float a , b ,c, x;
    scanf("%f%f%f",&a,&b,&c);
    if(a<b)
    {
        x=a;
        a=b;
        b=x;
    }
    if (a<c)
    {
        x=a;
        a=c;
        c=x;
    }
    if (b*b + c*c == a*a && a<b+c)
    {
        printf("RT");
    }
    else if (a<b+c)
    {
        printf("T");
    }
    else
        printf("N");
}