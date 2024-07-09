#include<stdio.h>
#include<math.h>
int main (){
    int a,b,c,d,e,f,g,h;
    scanf("%d\n%d",&a,&b);
    
    if(b==0)
    e=0;
    else
        e=log10(b);
    for(c=e+1;c>0;c--)
    {
        d=a/pow(10,c-1);
        f=b/pow(10,c-1);
        a=a-d*pow(10,c-1);
        b=b-f*pow(10,c-1);
        printf("%d%d",d,f);

    }
}