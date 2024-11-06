#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
   int i,j,count,z[1000];
   char s[1000][1000],temp[1000],s1[1000][1000];
   for(i=0;;i++)
    {
        scanf("%s",&s[i]);
        if(s[i][0]=='0')
        break;
    }
    count=i-1;
    for(i=0;i<=count;i++)
        for(j=i+1;j<=count;j++)
        {
            if((int)s[i][0]==(int)s[j][0]&&strlen(s[j])>strlen(s[i]))
            {
                strcpy(temp,s[i]);
                strcpy(s[i],s[j]);
                strcpy(s[j],temp);
            }
            if((int)s[i][0]>(int)s[j][0])
                {
                    strcpy(temp,s[i]);
                    strcpy(s[i],s[j]);
                    strcpy(s[j],temp);
                }
            s1[i][0]=tolower(s[i][0]);
            s1[j][0]=tolower(s[j][0]);
            if((int)s1[i][0]>(int)s1[j][0])
            {
                strcpy(temp,s[i]);
                strcpy(s[i],s[j]);
                strcpy(s[j],temp);
            }
            if((int)s[i][0]==(int)s[j][0]&&s[i][1]>(int)s[j][1])
            {
                strcpy(temp,s[i]);
                strcpy(s[i],s[j]);
                strcpy(s[j],temp);
            }

        }
    for(i=0;i<=count;i++)
    printf("%s ",s[i]);

   return 0;
}