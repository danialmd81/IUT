#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main()
{
    int n,b;
    scanf("%d\n",&n);
    for(int a=0;a<n;++a)
    {
        char AnimeName[1000];
        gets(AnimeName);
        b=sizeof(AnimeName);
        for(int i=0;i<1000;++i)
        {
            AnimeName[i]=tolower(AnimeName[i]);
            if(isspace(AnimeName[i-1]))
            AnimeName[i]=toupper(AnimeName[i]);
            AnimeName[0]=toupper(AnimeName[0]);
        }
        puts(AnimeName);
        
    }
}