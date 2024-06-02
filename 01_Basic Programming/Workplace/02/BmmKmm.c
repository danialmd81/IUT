    #include <stdio.h>  
    #include <math.h>  
    int main()
    {  
    long long int  n1, n2, g;
    scanf("%lld %lld", &n1, &n2);
    if (n1 > n2) {
        long long int x = n1;
        n1 = n2;
        n2 = x;
    }
    
    if (n2 % n1 == 0) {
        g = n1;


    }if (n2 % n1 == 0) {
        g = n1;
    }else if(n2%(n1/2)==0){


        g=n1/2;
    }else if(n2%(n1/3)==0){
        g=n1/3;
    }else if(n2%(n1/4)==0){
        g=n1/4;
    }else if(n2%(n1/5)==0){


        g=n1/5;
    }else if(n2%(n1/6)==0){
        g=n1/6;
    }else if(n2%(n1/7)==0){
        g=n1/7;
    }else if(n2%(n1/8)==0){
        g=n1/8;
    }else if(n2%(n1/9)==0){
        g=n1/9;
    }else if(n2%(n1/10)==0){
        g=n1/10;
    }
    else if(n2%(n1/11)==0){
        g=n1/11;
    }
    else if(n2%(n1/12)==0){


        g=n1/12;
    }
    else if(n2%(n1/13)==0){
        g=n1/13;
    }
    else if(n2%(n1/14)==0){
        g=n1/14;
    }
    else if(n2%(n1/15)==0){
        g=n1/15;
    }
    else {


        for (int i = 1; i <= n1/15; ++i)
        {


            if (n1 % i == 0 && n2 % i == 0)
                g = i;
        }
    }
        printf("%lld %lld",g , n1*n2/ g);
    }
    
    