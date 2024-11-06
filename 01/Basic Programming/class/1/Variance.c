#include <stdio.h>
int main(){
    float a1,a2,a3,a4,a5,j,m,v;
    scanf("%f%f%f%f%f",&a1,&a2,&a3,&a4,&a5);
    j=a1+a2+a3+a4+a5;
    m=j/5;
    v=(((a1-m)*(a1-m))+((a2-m)*(a2-m))+((a3-m)*(a3-m))+((a4-m)*(a4-m))+((a5-m)*(a5-m)))/5;
    printf("%.3f\n%.3f\n%.3f",j,m,v);
}