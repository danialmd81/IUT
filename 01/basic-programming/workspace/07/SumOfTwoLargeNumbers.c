    #include<stdio.h>
    int sumnum[256],k=0;
    
    int* sum (char s1[256],char s2[256])
    {
        int num1[256], num2[256];
        int l1, l2;
        for (l1 = 0; s1[l1] != '\0'; l1++)
        {
            num1[l1] = s1[l1] - '0';
        }
        for (l2 = 0; s2[l2] != '\0'; l2++)
        {
            num2[l2] = s2[l2] - '0';
        }
        int carry = 0;
        int i = l1 - 1;
        int j = l2 - 1;
        for (; i >= 0 && j >= 0; i--, j--, k++)
        {
            sumnum[k] = (num1[i] + num2[j] + carry) % 10;
            carry = (num1[i] + num2[j] + carry) / 10;
        }
        if (l1 > l2)
        {
            while (i >= 0)
            {
                sumnum[k++] = (num1[i] + carry) % 10;
                carry = (num1[i--] + carry) / 10;
            }
         }
        else if (l1 < l2)
        {
            while (j >= 0)
            {
                sumnum[k++] = (num2[j] + carry) % 10;
                carry = (num2[j--] + carry) / 10;
            }
        }
        else
        {
            if (carry > 0)
            sumnum[k++] = carry;
        }
    }
    int main()
    {
        char s1[256];
        char s2[256];
        scanf("%s",& s1);
        scanf("%s",& s2);
        sum(s1,s2);
        for (k--; k >= 0; k--)
        printf("%d", sumnum[k]);
    }