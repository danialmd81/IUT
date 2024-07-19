    #include<stdio.h>
	#include<string.h>
    int subnum[256],num1[256], num2[256],l1,l2,k,i,j;
    void sub (char s1[256],char s2[256])
    {
        for (i=0; s1[i] != '\0'; l1--,i++)
        {
            num1[l1] = s1[i] - '0';
        }
        for (j=0; s2[j] != '\0'; l2--,j++)
        {
            num2[l2] = s2[j] - '0';
        }
		if(strlen(s1)>strlen(s2))
		{
			
			for (i=2,j=2,k=1; i <strlen(s1)+2 ; i++, j++, k++) 
        	{
				if(num1[i-1]>=num2[j-1])
				{
					subnum[k-1] = num1[i-1] - num2[j-1];
				}
				else
				{
					subnum[k-1] = (num1[i-1] - num2[j-1])+10;
					num1[i]--;
				}
    		}
		}
		 else
		{
			for (i=2,j=2,k=1; i <strlen(s2)+2 ; i++, j++, k++) 
        	{
				if(num2[j-1]>=num1[i-1])
				{
					subnum[k-1] =   num2[j-1]-num1[i-1];
				}
				else
				{
					subnum[k-1] = (num2[j-1] - num1[i-1])+10;
					num2[i]--;
				}
    		}
			printf("-");
		}
    }
    int main() 
    {
        char s1[256];
        char s2[256];
        gets(s1);
        gets(s2);
		l1=strlen(s1);
		l2=strlen(s2);
        sub(s1,s2);
		
		//printf("-");
        for (k-=2; k >=0; k--)
		{
			printf("%d", subnum[k]);
		}   
    }