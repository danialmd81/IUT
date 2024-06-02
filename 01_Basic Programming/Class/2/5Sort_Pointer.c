#include <stdio.h>

void sorting(int* arr , int s) 
{
	for (int i=0; i<s; i++)
	{
		for (int j =i+1; j<s; j++)
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


void print (int* arr, int n)
{
	for (int i=0; i<n; i++)
    {
        printf ("%d ", arr[i]);
    }
		
}

int main ()
{

	int arr [100],n;
    scanf("%d",&n);
    for (int i=0; i<n; i++)
    {
        scanf ("%d", &arr[i]);
    }	
	sorting (arr,n);
	print (arr,n);
	return 0;
}
