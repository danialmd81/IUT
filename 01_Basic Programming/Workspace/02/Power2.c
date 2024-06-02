#include<stdio.h>
#include<math.h>
int main(){
    int n , a ,b ;
    
    scanf("%d", &n);
    if (n==1){
        printf("2");
    }
    else{
        a=log2(n);
        b= pow(2,a+1);
        printf("%d", b);


    }

}