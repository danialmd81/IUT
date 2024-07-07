#include <stdio.h>
int main(void) {
 int n,remain,answer,loop,t;
 scanf("%d",&t);
 for (loop=0; loop<t; loop++) {
  scanf("%d",&n);
  remain=n%11;
  answer=n/11;
  if (n%11==0){
   printf("YES\n");
  }
  else if (n%111== 0){
   printf("YES\n");
  }
  else if (answer-(10*remain)>=0){
   printf("YES\n");
   }
  else  
  {
    printf("NO\n");
    }
 }
}