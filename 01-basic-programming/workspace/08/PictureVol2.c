#include <stdio.h>
#include <stdlib.h>
int**pic;
int**kern;
int**res;
int findindex(int i1, int j1, int space) 
{  
    int Iindex,Jindex,sum = 0;
    for (int i = 0; i < 2 * space + 1; i++) 
    {
        for (int j = 0; j < 2 * space + 1; j++) 
        {
            Iindex = i1 - space + i;
            Jindex = j1 - space + j;
            sum += pic[Iindex][Jindex] * kern[i][j];
        }
    }
    if (sum > 255) 
    {
        return 255;
    }
    else if (sum < 0) 
    {
        return 0;
    }
    else 
    {
        return sum;
    }
}

int** find(int spic, int skern) {

    int space = skern / 2;
    for (int i = 0; i < spic; i++) 
    {
        for (int j = 0; j < spic; j++) 
        {
            res[i][j] = 0;
        }
    }
    int sum = 0;
    for (int i = space; i < spic - space; i++) 
    {
        for (int j = space; j < spic - space; j++) 
        {
            res[i][j] = findindex(i, j, space);
        }
    }
    return res;

}
int main(void) 
{
    int spic, skern; 
    scanf("%d",& spic);
    pic=malloc(spic*sizeof(int*));
    for(int i=0;i<spic;i++)
    {
        pic[i]=malloc(spic*sizeof(int));
    }
    for(int i=0;i<spic;i++)
    {
        for(int j=0;j<spic;j++)
        {
            scanf("%d",&pic[i][j]);
        }
    }
    
    scanf("%d",&skern);
    kern=malloc(skern*sizeof(int*));
    for(int i=0;i<skern;i++)
    {
        kern[i]=malloc(skern*sizeof(int));
    }
    for(int i=0;i<skern;i++)
    {
        for(int j=0;j<skern;j++)
        {
            scanf("%d",&kern[i][j]);
        }
    }
    res=malloc(spic*sizeof(int*));
    for(int i=0;i<spic;i++)
    {
        res[i]=malloc(spic*sizeof(int));
    }
    find(spic, skern);
    for(int i=0;i<spic;i++)
    {
        for(int j=0;j<spic;j++)
        {
            printf("%d ",res[i][j]);
        }
        printf("\n");
    }
}
	
