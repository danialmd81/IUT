#include <stdio.h>

int main(){
   int rows,i, j,k=1;
   unsigned long long int coef=1;
   scanf("%d", &rows);
    for (i = rows-1; i >=0; i--) {
      for (j = 0; j <= i; j++) {
         if (j == 0 || i == 0)
            coef = 1;
         else
            coef = coef * (i-j + 1)/j ;
         printf("%llu ", coef);
         
      }
      printf("\n");
      k++;
   }
   return 0;
}