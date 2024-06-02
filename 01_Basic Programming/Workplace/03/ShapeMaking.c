#include <stdio.h>
int main()
{
    int n,i,j,k=0;
    scanf("%d",&n);
    for (i=1;i<=4*n+1;i++)
    {
        for(j=1;j<=8*n+1;j++)
        {
            if(n%2!=0)
            {
                if((i+j)%8==6||(j-i)%8==4||i==4*k+1||(j-i)%8==-4)
                {
                    if(4*n+1<(i+j)&&(j-i)<4*n+1)
                    printf("*");
                    else if((j-i)<4*n+1)
                    printf(" ");
                    
                }
                else if((j-i)<4*n+1)
                printf(" ");
                
            }
            else
            {
                if((i+j)%8==2||(j-i)%8==0||i==4*k+1)
                {
                    if(4*n+1<(i+j)&&(j-i)<4*n+1)
                    printf("*");
                    else if((j-i)<4*n+1)
                    printf(" ");
                }
                else if((j-i)<4*n+1)
                printf(" ");
            }
            
        }
        printf("\n");
        
        if(i%4==0)
        k++;
    }
}