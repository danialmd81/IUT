#include <stdio.h>
#include <math.h>

int main(){
int n, i;
float x, sum=0, j, y=1;
scanf("%f%d", &x, &n);
    for(i=1; i<n; i++){
        y=y*i;
        j=(round(pow(x,i)))/y;
        sum+=j;
    }
    sum++;
    printf("%.3f", sum);
    return 0;
}