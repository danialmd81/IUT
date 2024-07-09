#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct player {
	int playerId;
	char name[30];
	int price;
	int speed;
	int finishing;
	int defence;
	int flag;
	// if bool==true means player has a team
};
struct team
{
	int teamId;
	char name[30];
	int money;
	struct player arrayteamplayers[50];
	int countplayers;
	//numbers of players 
	int point;
	int wins;
	int losses;
};
void newplayer(int playerid, char name[30], int price, int speed, int finishing, int defence, struct player array[1000]) {
	array[playerid - 1].playerId = playerid;
	strcpy(array[playerid - 1].name, name);
	array[playerid - 1].price = price;
	array[playerid - 1].defence = defence;
	array[playerid - 1].finishing = finishing;
	array[playerid - 1].speed = speed;
}
void newteam(char name[30], int money, int teamid, struct team array[100]) {

	array[teamid - 1].teamId = teamid;
	array[teamid - 1].money = money;
	strcpy(array[teamid - 1].name, name);
}

int buyplayer(int playeridwant, int playerid, int teamidwant, int teamid, struct player playerarray[1000], struct team teamarray[100]) {
	if (playeridwant >= playerid) {

		printf("player with the id %d doesnt exist\n", playeridwant);
		return 0;


	}
	if (teamidwant >= teamid) {
		printf("team with the id %d doesnt exist\n", teamidwant);
		return 0;

	}
	if (teamarray[teamidwant - 1].money < playerarray[playeridwant - 1].price) {


		printf("the team cant afford to buy this player\n");
		return 0;


	}
	if (playerarray[playeridwant - 1].flag == 1) {

		printf("player already has a team\n");
		return 0;

	}

	teamarray[teamidwant - 1].money -= playerarray[playeridwant - 1].price;
	playerarray[playeridwant - 1].flag = 1;
	teamarray[teamidwant - 1].arrayteamplayers[teamarray[teamidwant - 1].countplayers] = playerarray[playeridwant - 1];
	++teamarray[teamidwant - 1].countplayers;


	printf("player added to the team succesfully\n");

	return 0;
}
int selplayer(int playeridwant, struct  player playerarray[1000], int teamidwant, int teamid, struct team teamarray[100]) {

	if (teamidwant >= teamid) {
		printf("team doesnt exist\n");
		return 0;

	}
	int flag = 0;
	int flag2;
	for (int i = 0; i <= teamarray[teamidwant - 1].countplayers; ++i) {
		if (playeridwant == teamarray[teamidwant - 1].arrayteamplayers[i].playerId) {

			flag2 = i;
			++flag;
			break;

		}
	}
	if (flag == 0) {
		printf("team doesnt have this player\n");
		return 0;
	}

	teamarray[teamidwant - 1].money += playerarray[playeridwant - 1].price;
	playerarray[playeridwant - 1].flag = 0;
	for (int i = flag2; i < teamarray[teamidwant - 1].countplayers; ++i) {

		teamarray[teamidwant - 1].arrayteamplayers[i] = teamarray[teamidwant - 1].arrayteamplayers[i + 1];
	}
	--teamarray[teamidwant - 1].countplayers;

	printf("player sold succesfully\n");
	return 0;
}

int match(int teamid1, int teamid2, int teamid, struct team array[1000]) {

	if (teamid1 >= teamid) {
		printf("team doesnt exist\n");
		return 0;
	}
	if (teamid2 >= teamid) {
		printf("team doesnt exist\n");
		return 0;
	}
	if (array[teamid1 - 1].countplayers < 11) {

		printf("the game can not be held due to loss of the players\n");
		return 0;
	}

	if (array[teamid2 - 1].countplayers < 11) {
		printf("the game can not be held due to loss of the players\n");
		return 0;
	}

	int pow1 = 0, pow2 = 0;
	for (int i = 0; i < 11; ++i) {
		pow1 += array[teamid1 - 1].arrayteamplayers[i].speed;
		pow1 += array[teamid1 - 1].arrayteamplayers[i].finishing;

	}
	for (int i = 0; i < 11; ++i) {
		pow2 += array[teamid2 - 1].arrayteamplayers[i].speed;
		pow2 += array[teamid2 - 1].arrayteamplayers[i].defence;

	}

	if (pow1 > pow2) {
		++array[teamid1 - 1].wins;
		++array[teamid2 - 1].losses;
		array[teamid1 - 1].money += 1000;
		return 0;

	}
	if (pow2 > pow1) {
		++array[teamid2 - 1].wins;
		++array[teamid1 - 1].losses;
		array[teamid2 - 1].money += 1000;
		return 0;

	}

	return 0;
}

void rank(int teamid, struct team array[100]) {
	int count = teamid - 1;
	for (; count > 0; --count) {
		for (int i = 0; i < count - 1; ++i) {
			if (array[i].wins < array[i + 1].wins) {
				struct team help = array[i];
				array[i] = array[i + 1];
				array[i + 1] = help;
			}
			else if (array[i].wins == array[i + 1].wins) {
				if (array[i].losses > array[i + 1].losses) {
					struct team help = array[i];
					array[i] = array[i + 1];
					array[i + 1] = help;
				}
			}
		}
	}
	for (int i = 0; i < teamid - 1; ++i) {
		printf("%d. %s\n", i + 1, array[i].name);
	}
}

int main(void) {
	struct team teamarray[100];
	struct player playerarray[1000];
	for (int i = 0; i < 1000; ++i) {
		playerarray[i].defence = 0;
		playerarray[i].finishing = 0;
		playerarray[i].flag = 0;
		playerarray[i].playerId = 0;
		playerarray[i].price = 0;
		playerarray[i].speed = 0;
	}
	for (int w = 0; w < 100; ++w) {
		teamarray[w].losses = 0;
		teamarray[w].money = 0;
		teamarray[w].point = 0;
		teamarray[w].wins = 0;
		teamarray[w].countplayers = 0;
	}
	int playerid = 1;
	int teamid = 1;

	char in[20];
	for (;;) {
		scanf("%s", in);
		if (strcmp(in, "new") == 0)
		{
			scanf("%s", in);
			if (strcmp(in, "player") == 0) {
				char name[30];
				int price, speed, finishing, defence;
				scanf("%s%d%d%d%d", name, &price, &speed, &finishing, &defence);
				newplayer(playerid, name, price, speed, finishing, defence, playerarray);
				++playerid;
			}
			else if (strcmp(in, "team") == 0) {
				int money;
				char tname[30];
				scanf("%s%d", tname, &money);
				newteam(tname, money, teamid, teamarray);
				++teamid;
			}
		}
		else if (strcmp(in, "buy") == 0) {
			int p1, t2;
			scanf("%d%d", &p1, &t2);
			buyplayer(p1, playerid, t2, teamid, playerarray, teamarray);




		}
		else if (strcmp(in, "sell") == 0)
		{
			int pid;
			int tid;
			scanf("%d%d", &pid, &tid);
			selplayer(pid, playerarray, tid, teamid, teamarray);

		}
		else if (strcmp(in, "match") == 0)
		{
			int t1, t2;
			scanf("%d%d", &t1, &t2);
			match(t1, t2, teamid, teamarray);


		}
		else if (strcmp(in, "rank") == 0) {

			rank(teamid, teamarray);


		}
		else if (strcmp(in, "end") == 0)
			return 0;



	}

}