#include<stdio.h>
int main()
{
    char harf1[50],harf2[50],last,first;
    int i;
    for(i=0;i<51;i++)
    {
        scanf("%c",&harf1[i]);
        if(harf1[i]=='\n')
        break;
        
    }
    first=harf1[0];
    //printf("%c\n",first);
    for(i=0;i<51;i++)
    {
        scanf("%c",&harf2[i]);
        if(harf2[i]=='\n')
        break;
    }
    last=harf2[i-1];
    
    if (first==last)
    printf("YES");
    else if(first!=last)
    printf("NO");
}
