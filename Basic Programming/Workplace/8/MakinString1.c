#include <stdio.h>
#include<math.h>
char *make(char s[])
{
    for(int i=0,x=1;i<16;i++,x++)
    {
        for(int j=0;j<pow(2,x);j++)
        {
        if (s[j]==0)
        s[j+(int)pow(2,x)]=1;
        }
    }
    return s;
}
int main()
{
    int R=0,L=0;
    scanf("%d%d",&L,&R);
    char s[100000]={0};
    s[0]=1;
    s[1]=0;
    make(s);
    for(int i=L-1;i<R;i++)
    {
        printf("%d",s[i]);
    }
}