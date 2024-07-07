#include <stdio.h>
#include <math.h>
long long int Arm (long long int n, int nd)
{
  int s=0,r;
  if (n>0)
  {
    r=n%10;
    s=s+pow(r,nd)+Arm(n/10,nd);
    return s;
  }
  else
  return 0;
}

int main()
{
  long long int n,arm;
  int  nd=3 ;
  scanf("%lld", &n);
  //nd=log10(n)+1;
  arm=Arm(n,nd);
  if(n==arm)
  printf("Yes");
  else
  printf("No");
  return 0;
}