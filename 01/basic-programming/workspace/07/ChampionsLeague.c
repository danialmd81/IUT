#include <stdio.h>
#include<stdlib.h>
int main() 
{
    int number_of_teams=0,number_of_last_team,delete=0,lowest_score=0,i=0;
    int * score_of_teams=malloc(100*sizeof(int));

    scanf("%d %d", &number_of_teams, &number_of_last_team);

    for (i = 0; i < number_of_teams; i++) 
    {
        scanf("%d",(score_of_teams+i));
    }
    lowest_score=*(score_of_teams+number_of_last_team-1);

    for (i = 0; i < number_of_teams; i++) 
    {
        if(*(score_of_teams+i)<lowest_score||*(score_of_teams+i)==0)
        {
            delete++; 
        }
    }  
    printf("%d",number_of_teams-delete);

}