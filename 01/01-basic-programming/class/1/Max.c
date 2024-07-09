#include<stdio.h>
int
main ()
{
  int x, n, y, k,r;
  scanf ("%d %d %d", &x, &y, &n);
  r=(n-x)%y;
  k=n-r;
  printf ("%d", k);
}
