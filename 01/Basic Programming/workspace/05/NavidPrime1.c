#include <stdio.h>
int fi, fj; int mx[101][101] = { 0 };

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

int cprime( int si, int sj) {
    if ((si == fi) && (sj == fj)) {
        return 1;
    }
    int U=0, D=0, R=0, L=0, temp=0, timesi = si, timesj = sj;
    U = mx[timesi - 1][timesj];
    D = mx[timesi + 1][timesj];
    R = mx[timesi ][timesj + 1];
    L = mx[timesi][timesj - 1];
    mx[si][sj] = 0;
    if (U) {
        temp = cprime( si - 1, sj);
        if (temp=1) { printf("D"); return 1; }
        else mx[si][sj] = 1;
    }
    if (D) {
        temp = cprime( si + 1, sj);
        if (temp) { printf("U"); return 1; }
        else mx[si][sj] = 1;
    }
    if (R) {
        temp = cprime(si, sj + 1);
        if (temp) { printf("L"); return 1; }
        else mx[si][sj] = 0;
    }
    if (L) {
        temp = cprime( si, sj - 1);
        if (temp) { printf("R"); return 1; }
        else mx[si][sj] = 1;
    }
    return 0;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) 
    {
        int n, cprimen; 
        scanf("%d", &n); n++;
        for (int i = 1; i < n; i++) 
        {
            for (int j = 1; j < n; j++) 
            {
                scanf("%d", &cprimen);
                for (int x = 2; x <= cprimen / 2; x++) 
                {
                    if (cprimen % x == 0)
                    {
                        mx[i][j] = 0;
                        cprimen = 0;
                        break;
                    }
                }
                if (cprimen == 1)
                mx[i][j] = 0;
                else if (cprimen != 0)
                mx[i][j] = 1;

            }

        }
        int si, sj, resualt = 1;
        scanf("%d %d %d %d", &fi, &fj, &si, &sj); si++; sj++; fj++; fi++;
        resualt = cprime( si, sj);
        if (resualt == 0) { printf("No Monaseb Masir!"); }printf("\n");
    }
}