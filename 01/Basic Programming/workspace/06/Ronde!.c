#include <stdio.h>

int main()
{
    int t,a;
    scanf("%d",&t);
    for(a=0;a<t&&t!=0;a++)
    {
        char pnum[9];
        int triple=0,count0=0,count1=0,count2=0,count3=0,count4=0,count5=0,count6=0,count7=0,count8=0,count9=0;
        for(int i=0;i<9&&t!=0;i++)
        {
            scanf("%c",&pnum[i]);
            if(pnum[i-2]==pnum[i-1]&&pnum[i-1]==pnum[i]&&i>=3)
            triple=1;
            if(pnum[i]=='0')
            count0++;
            if(pnum[i]=='1')
            count1++;
            if(pnum[i]=='2')
            count2++;
            if(pnum[i]=='3')
            count3++;
            if(pnum[i]=='4')
            count4++;
            if(pnum[i]=='5')
            count5++;
            if(pnum[i]=='6')
            count6++;
            if(pnum[i]=='7')
            count7++;
            if(pnum[i]=='8')
            count8++;
            if(pnum[i]=='9')
            count9++;  
        }
    if(pnum[1]==pnum[8]&&pnum[2]==pnum[7]&&pnum[3]==pnum[6]&&pnum[4]==pnum[5])
    printf("Ronde!\n");
    else if(count0>=4||count1>=4||count2>=4||count3>=4||count4>=4||count5>=4||count6>=4||count7>=4||count8>=4||count9>=4)
    printf("Ronde!\n");
    else if(triple==1)
    printf("Ronde!\n");
    else
    printf("Rond Nist\n");
    }

}