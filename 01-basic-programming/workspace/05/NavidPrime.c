#include<stdio.h>
int prime(int n)
{
    int m=1,r,i,j;
    for (i=0; i<m; i++)
    {
    	j = 2;
    	while (j<= n/2)
    		if (!(r = n%j))
    			break;
    		else
    			j++;

    	if (j>n/2)
    		return 1;
    	else
    		return 0;
    }
    
}

int main()
{
    int t,i,j,i2,j2;
    scanf("%d",&t);
    for( i=0;i<t;i++)
    {
        int n;
        scanf("%d",&n);
        int a[100][100];
        for( i=0;i<n;i++)
        {
            for( j=0;j<n;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
    }
    scanf("%d%d",&i,&j);
    scanf("%d%d",&i2,&j2);
    
}
