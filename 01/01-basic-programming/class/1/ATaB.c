#include<stdio.h>
#include<math.h>
int main()
{
 int a,b,c,d,e,f;
 scanf("%d %d",&a,&b);
 c=(a-b)/10;
 d=(a-b)%10;
 f=round(d/(d-0.1));
 e=f+c;
 printf("%d",e);
 
}
