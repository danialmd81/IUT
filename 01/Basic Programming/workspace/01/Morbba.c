#include <stdio.h>
int main()
{
 int a , b;
    scanf("%d%d",&a,&b);
    if(b>=a)
    {
        printf("Wrong order!");
    }
    else if((a-b)%2==1)
        printf("Wrong difference!");
    else
    {
        int i=0;
        while (i<(a-b)/2)
        {
            int j=0;
            while (j<a)
            {
                printf("* ");
                j++;
            }
            i++;
            printf("\n");
        }
        i=0;
        while(i<b)
        {
            int j=0;
            while(j<(a-b)/2)
            {
                printf("* ");
                j++;
            }
            j=0;
            while(j<b)
            {
                printf("  ");
                j++;
            }
            j=0;
            while(j<(a-b)/2)
            {
                printf("* ");
                j++;
            }
            printf("\n");
            i++;
        }
        i=0;
        while (i<(a-b)/2)
        {
            int j=0;
            while (j<a)
            {
                printf("* ");
                j++;
            }
            i++;
            printf("\n");

        }
    }
}
