#include<stdio.h>
#include<dirent.h>
#include <ctype.h>
#include <string.h>
#include<stdlib.h>

typedef struct player
{
    int price,speed,finishing,defence,teamID;
    char *name;
    struct player *next;
}player;

player playerZ;

typedef struct team
{
    int money,win,loss,equal,point;
    char *name;
    int *playerID;
    struct team *next;
}team;

team teamZ;


player *createPlayer(char *name,int price,int speed,int finishing,int defence)
{
    struct player *newPlayer;
    newPlayer = (struct player *)malloc(sizeof(struct player));
    if(newPlayer == NULL) 
    {
        printf(" Memory can not be allocated->");
        exit(0);
    }
    else
    {
        newPlayer->price = price;
        newPlayer->speed=speed;
        newPlayer->finishing=finishing;
        newPlayer->defence=defence;
        newPlayer->name=(char *)malloc(64*sizeof(char));
        newPlayer->name=name;
        newPlayer->teamID=0;
        newPlayer->next = NULL;
        return newPlayer;
    }
}

team *createTeam(int money,char *name)
{
    team *newTeam;
    newTeam = (struct team *)malloc(sizeof(team));
    if(newTeam == NULL) 
    {
        printf(" Memory can not be allocated->");
        exit(0);
    }
    else
    {
        newTeam->point=0;
        newTeam->equal=0;
        newTeam->loss=0;
        newTeam->win=0;
        newTeam->money = money;
        newTeam->name=(char *)malloc(64*sizeof(char));
        newTeam->name=name;
        newTeam->playerID=malloc(30*sizeof(int));
        for(int i=0;i<30;i++)
        {
            newTeam->playerID[i]=0;
        }
        newTeam->next = NULL;
        return newTeam;
    }
}

void push_back_player()
{
    int price ,speed ,finishing ,defence;
    char *name=malloc(64*sizeof(char));
    scanf("%s%d%d%d%d", name, &price, &speed, &finishing, &defence);
    struct player *newPlayer ;
    newPlayer = createPlayer (name , price , speed , finishing , defence);
    struct player *last;
    last = playerZ.next;
    if (playerZ.next == NULL)
    {
        playerZ.next=newPlayer;
        return;
    }
    else
    {
        while (last->next!= NULL)
        {
            last = last->next;
        }
        last->next = newPlayer;
        return;
    }
        
}

void push_back_team()
{
    char *name=malloc(64*sizeof(char));
    int money;
    scanf("%s%d",name,&money);
    team *newTeam = createTeam(money,name);
    team *last = teamZ.next;
    if (teamZ.next == NULL)
    {
        teamZ.next = newTeam;
        return;
    }
    else
    {
        while (last->next!= NULL)
        {
            last = last->next;
        }
        last->next = newTeam;
        return;
    }       
}

player *find_player(int ID)
{
    player *wanted ;
    wanted=playerZ.next;
    for(int i=0;i<ID-1;i++)
    {
        wanted=wanted->next;
    }
    return wanted;
}

team *find_team(int ID)
{
    team *wanted ;
    wanted=teamZ.next;
    for(int i=0;i<ID-1;i++)
    {
        wanted=wanted->next;
    }
    return wanted;
}

int size_player()
{
    int size=0;
    player *last =playerZ.next;
    while (last!= NULL)
    {
        last = last->next;
        size++;
    }
    return size;
}

int size_team()
{
    int size=0;
    team *last =teamZ.next;
    while (last!= NULL)
    {
        last = last->next;
        size++;
    }
    return size;
}

void buy(int playerID,int teamID)
{
    
    if(playerID>size_player())
    {
        printf("player with the id %d doesnt exist\n",playerID);
        return;
    }
    if(teamID>size_team())
    {
        printf("team with the id %d doesnt exist\n",teamID);
        return;
    }
    team  *team=find_team(teamID);
    player *player=find_player(playerID);
    if((team->money)<(player->price))
    {
        printf("the team cant afford to buy this player\n");
        return;
    }
    if(player->teamID!=0)
    {
        printf("player already has a team\n");
        return;
    }
    player->teamID=teamID;
    for(int i=0;i<30;i++)
    {
        if(team->playerID[i]==0)
        {
            
            team->playerID[i]=playerID;
            break;
        }
    }
    printf("player added to the team succesfully\n");
    return;
}

void sell(int playerID,int teamID)
{
    int check=0;
    if(playerID>size_player())
    {
        printf("player doesnt exist\n");
        return;
    }
    if(teamID>size_team())
    {
        printf("team doesnt exist\n");
        return;
    }
    team *team=find_team(teamID);
    player *player=find_player(playerID);
    for(int i=0;i<30;i++)
    {
        if(team->playerID[i]==playerID)
        {
            check++;
            team->playerID[i]=0;
        }
    }
    if(check!=1)
    {
        printf("team doesnt have this player\n");
        return;
    }
    team->money=team->money+player->price;
    player->teamID=0;
    printf("player sold succesfully\n");
    return;
}

void match (int teamID1,int teamID2)
{
    int npt1=0,npt2=0,powerT1=0,powerT2=0;
    team *team1,*team2;
    if(teamID1>size_team()||teamID2>size_team())
    {
        printf("team doesnt exist\n");
        return;
    }
    team1=find_team(teamID1);
    team2=find_team(teamID2);
    for(int i=0;i<30;i++)
    {
        if(team1->playerID[i]!=0)
        {
            npt1++;
        }
        if(team2->playerID[i]!=0)
        {
            npt2++;
        }
    }
    if(npt1<11||npt2<11)
    {
        printf("the game can not be held due to loss of the players\n");
    }
    npt1=0;
    npt2=0;
    for(int i=0;i<30;i++)
    {
        if(team1->playerID[i]!=0&&npt1<12)
        {
            player *playerT1=find_player(team1->playerID[i]);
            powerT1=powerT1+(playerT1->speed)+(playerT1->finishing);
            npt1++;
        }
        if(team2->playerID[i]!=0&&npt2<12)
        {
            player *playerT2=find_player(team2->playerID[i]);
            powerT2=powerT2+(playerT2->defence)+(playerT2->speed);
            npt2++;
        }
    }
    if(powerT1>powerT2)
    {
        (team1->win)++;
        (team1->point)++;
        team1->money+=1000;
        (team2->loss)++;
        (team2->point)--;
    }
    if(powerT1<powerT2)
    {
        (team2->win)++;
        (team2->point)++;
        team2->money+=1000;
        (team1->loss)++;
        (team1->point)--;
    }
    if(powerT1==powerT2)
    {
        (team1->equal)++;
        (team2->equal)++;
    }
    return;
}

void rank()
{
    team *team1,*team2,*team3,*tmp;
    team1=teamZ.next;
    if((teamZ.next)==NULL)
    {
        printf("no team\n");
        return;
    }
    team2=(team1->next);
    if(team2==NULL)
    {
        printf("1. %s\n",team1->name);
            return;
    }
    team3=team2->next;
    if(team3==NULL)
    {
        if((team1->point)>=(team2->point))
        {
            printf("1. %s\n",team1->name);
            printf("2. %s\n",team2->name);
            return;
        }
        else
        {
            printf("1. %s\n",team2->name);
            printf("2. %s\n",team1->name);
            return;
        }  
    }
    else
    {
        while(team3!=NULL)
        {
            if((team2->point)<(team3->point))
            {
                tmp=team3->next;
                team3->next=team2;
                team2->next=tmp;
                team1->next=team3;
            }
            team1=team1->next;
            team2=team2->next;
            team3=team3->next;
        }
        int i=1;
        team1=teamZ.next;
        while(team1!=NULL)
        {
            printf("%d. %s\n",i,(team1->name));
            i++;
            team1=team1->next;
        }
        return;
    }
    return;
}

int main ()
{
    int playerID,teamID,teamID1,teamID2;
    char *input,*input2;
    input=malloc(30*sizeof(char));
    input2=malloc(30*sizeof(char));
    player *player1=playerZ.next;
    while(1)
    {
        scanf("%s", input);
        if(strcmp(input,"new")==0)
        {
            scanf("%s", input2);
            if(strcmp(input2, "player")==0)
            {
                push_back_player();
            }
            if(strcmp(input2,"team")==0)
            {
                push_back_team();
            }
        }
        if(strcmp(input,"buy")==0)
        {
            scanf("%d %d",&playerID,&teamID);
            buy(playerID,teamID);
        }
        if(strcmp(input,"sell")==0)
        {
            scanf("%d %d",&playerID,&teamID);
            sell(playerID,teamID);
        }
        if(strcmp(input,"match")==0)
        {
            scanf("%d %d",&teamID1,&teamID2);
            match(teamID1,teamID2);
        }
        if(strcmp(input,"rank")==0)
        {
            rank();
        }
        if(strcmp(input,"end")==0)
        {
            return 0;
        }
       
        
    }
    

}