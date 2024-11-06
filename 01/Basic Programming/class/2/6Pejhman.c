#include <stdio.h>
void sorting(int arr[] , int n) 
{
	for (int i=0; i<n; i++)
    {
        for (int j =i+1; j<n; j++)
        {
            if (arr[i] > arr[j])
            {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j]= temp;
			}
        }
			
    }
}
int SUM(int arr[] , int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    return sum;
}
int main ()
{
	int cardsj[30],n,k,cardsm[30],sumj=0,i,j;
    scanf("%d%d",&n,&k);
    for (int i=0; i<n; i++)
    {
        scanf ("%d", &cardsj[i]);
    }
    for (int i=0; i<n; i++)
    {
        scanf ("%d", &cardsm[i]);
    }		
	sorting (cardsj,n);
	sorting (cardsm,n);
    for(i=n-1,j=0;j<k;i--,j++)
    {
        if(cardsm[i]>cardsj[j])
        {
            cardsj[j]=cardsm[i];
        }
    }
    sumj=SUM(cardsj,n);
    printf("%d",sumj);
	return 0;
}