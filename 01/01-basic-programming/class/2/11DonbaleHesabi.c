#include<stdio.h>
#include<stdlib.h>

int checkAP(int *arr, int n)
{
    if (n == 1)
    {
        return 0;
    }
    int d = arr[1] - arr[0];
    for (int i=2; i<n; i++)
    {
        if (arr[i] - arr[i-1] != d)
        return -1;
    }
    return d;
}

void sort (int* a, int s)
{
	for (int i=0; i<s-1; i++)
    {
        for (int j =i+1; j<s; j++)
        {
            if (a[i] > a[j])
            {
				int temp = a[i];
				a[i] = a[j];
				a[j]= temp;
			}
        }
			
    }
}

int main()
{
    int n,i,j,z=0,a,b=0;
    scanf("%d",&n);
    int *arr=malloc(n*sizeof(int)),*arrm=malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    for (i = 0; i < n; i++)      
    {
        for (j = 0; j < i; j++)   
        {
            if (arr[i] == arr[j])   
            {
                break;          
            }
        }
        if (i == j)
        {
            arrm[z]=arr[i];
            z++;     
        }
    }
    sort(arrm,z);
    int *arrlast=malloc(z*sizeof(int));
    for(i=0;i<z;i++)
    {
        a=0;
        for(j=0;j<n;j++)
        {
            if(arrm[i]==arr[j])
            {
                arrlast[a]=j;
                a++;
            }
        }
        if(checkAP(arrlast,a)!=-1)
    {
        b++;
    }
    }

    printf("%d\n",b);
    for(i=0;i<z;i++)
    {
        a=0;
        for(j=0;j<n;j++)
        {
            if(arrm[i]==arr[j])
            {
                arrlast[a]=j;
                a++;
            }
        }
        if(checkAP(arrlast,a)!=-1)
        printf("%d %d\n",arrm[i],checkAP(arrlast,a));
    }
}

    

    
