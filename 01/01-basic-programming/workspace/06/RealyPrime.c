#include <stdio.h>
int boolprime(long long int numprime) 
{
    long long int i, flag = 0;
    if (numprime == 0 || numprime == 1)
        flag = 1;
    for (i = 2; i <= numprime / 2; ++i) 
    {
        if (numprime % i == 0) 
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        return 1;
    else
        return 0;
}
int prime(long long int m) 
{
    long long int i, j, flag,numprime=0,a=0;
	for (i = 2; i <= 100000; i++) 
	{
		flag = 1;
		for (j = 2; j < i ; ++j) 
		{
			if (i % j == 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
        {
            numprime++;
            if(boolprime(numprime)==1)
                a++;
        }
			if(a==m)
            {
                printf("%lld\n", i);
                return 0;
            }       
	}
}
int main()
{
    long long int n,m;
    scanf("%lld",&n);
    for(int t=0;t<n;t++)
    {
        scanf("%lld",&m);
        prime(m);
    }
}