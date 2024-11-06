#include<stdio.h>
#include<math.h>
int main()
{
    int i,j,n,a;
    scanf("%d",&n);
    for(i=1;i<=pow(2,n+1)-1;i++)
    {
        for(j=1;j<=pow(2,n+1)-1;j++)
        {
            a=pow(2,n);
            if(n%2==0)
            {
                if(i==1 || i==pow(2,n+1)-1 || j==1 || j==pow(2,n+1)-1||(i+j)%a==2||(i+j)%a==pow(2,n+1)-2||(j-i)%a==2||(j-i)%a==-2)
                {
                    printf("#");
                    
                }
                else
                {
                printf(".");
                }
            }
            else
            {
                if(i==1 || i==pow(2,n+1)-1 || j==1 || j==pow(2,n+1)-1||(i+j)==10||(i+j)==22||(j-i)==6||(j-i)==-6)
                {
                    printf("#");
                }
                else
                {
                    if(i==5&&i+j<17&&i+j>10)
                    printf("#");
                    else if(i==11&&i+j<23&&i+j>16)
                    printf("#");
                    else if(j==5&&i+j<17&&i+j>10)
                    printf("#");
                    else if(j==11&&i+j<23&&i+j>16)
                    printf("#");
                    else
                    printf(".");
                }
            }
        }
        printf("\n");
    }
}