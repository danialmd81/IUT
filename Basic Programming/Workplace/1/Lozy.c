#include <stdio.h>
int main()
{
 int n;
 scanf("%d",&n);
 for (int i=1;i<=n;i+=2)
 {
  for (int j=0;j<n/2-i/2;j++)
   printf(" ");
  for(int j=1;j<=i;j++)
   printf("*");
  for(int j=1;j<=n-i;j++)
   printf(" ");
  for(int j=1;j<=i;j++)
   printf("*");
  printf("\n");
 }
    for (int i=n-2;i>=1;i-=2)
    {
        for (int j=0;j<n/2-i/2;j++)
            printf(" ");
        for(int j=1;j<=i;j++)
            printf("*");
        for(int j=1;j<=n-i;j++)
            printf(" ");
        for(int j=1;j<=i;j++)
            printf("*");
        printf("\n");
    }
}