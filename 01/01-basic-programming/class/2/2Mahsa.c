#include<stdio.h>
#include<math.h>
void recursive(int cnum)
{
    int a;
    if(cnum==0)
    return;
    if(cnum%10==0)
    {
        a=cnum%1000/10;
        a=a+96;
        cnum=cnum/1000;
    }
    else
    {
        a=cnum%10;
        a=a+96;
        cnum=cnum/10;
    }
    recursive(cnum);
    printf("%c",a);
}
int main()
{
    int n;
    scanf("%d\n",&n);
    int num;
    scanf("%d",&num);
    recursive(num);
}