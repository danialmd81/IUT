#include<stdio.h>
#include<math.h>
int main()
{
    int n,a,b;
    unsigned long long int t,adad;
    scanf("%llu",&t);
    for(;t>0;t--){
        scanf("%d%llu",&n,&adad);
        a=adad/(pow(10,n-1));
        if(a==3){
            b=(adad-a*(pow(10,n-1)))/(pow(10,n-2));
            if(b==2){
                n--;
                    }

                }
                 }
                 printf("%d",n);

}
