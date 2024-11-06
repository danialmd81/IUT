    #include<stdio.h>
    int main()
    {
        int a[10],n,i,f,b=0,c=0,d,e,g;
        scanf("%d %d",&n,&f);
        for(i=0;n>0;i++)
        {
            if(i%2==0)
            {
                a[i]=n%f;
                n=n/f;
                b=b+a[i];
            }
            else
            {
                a[i]=n%f;
                n=n/f;
                c=c+a[i];
            }
        }
        if(b==c)
        printf("Yes");
        else
        printf("No");
    }