#include<stdio.h>
int main()
{
    char color;
    int g=0,y=0,r=0;
    for(int i=0;i<6;i++)
    {
        scanf("%c",&color);
        if(color=='G')
        g++;
        if(color=='Y')
        y++;
        if(color=='R')
        r++;
    }
    if (r>=3)
    printf("nakhor lite");
    else if (r>=2&&y>=2)
    printf("nakhor lite");
    else if (y==5)
    printf("nakhor lite");
    else if (y==4&&r==1)
    printf("nakhor lite");
    else
    printf("rahat baash");
    
    
}