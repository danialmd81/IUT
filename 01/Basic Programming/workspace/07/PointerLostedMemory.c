#include<stdio.h>

int* f(int n)
{
    int* x;
    for(int i = 0; i < n; i++)
    {
        x[i]=i*i;
    }
return x;
    
}
int main()
{
    int n;
    scanf("%d", &n);
    int* b=f(n);
    for(int i = 0; i < n; i++)
    {
        printf("%d ", b[i]);
    }
}