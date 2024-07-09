#include <stdio.h>
#include <math.h>

int main()
{
    int o=0,e=0,i=0;
    int even[1000]={};
    int odd[1000]={};
    int n;
    while(scanf("%d",&n)==1)
    {
        //scanf("%d",&n);    
        if(n%2==0)
        {
            even[e]=n;
            e++;
            }
            else
            {
            odd[o]=n;
            o++;
         }
    }
    printf("Even:\n");
    for (int i=0;i<e;i++)
    {
        printf("%d\n",even[i]);
    }
    printf("Odd:\n");
    for (int i=0;i<o;i++)
    {
        printf("%d\n",odd[i]);
    }
}