#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>

struct player {
	int player_ID;
	char name[30];
	int price;
	int speed;
	int finishing;
	int defence;
	int tmp;
}players[100];

struct team {
	int team_ID;
	char name[30];
	int money;
	int win;
	int lose;
	struct player players_of_team[50];
	int countplayer;
}teams[50];

void add_player(char name[30], int price, int speed, int finishing, int defence, struct player players[], int i) {
	players[i].defence = defence;
	players[i].finishing = finishing;
	players[i].player_ID = i + 1;
	players[i].price = price;
	players[i].speed = speed;
	players[i].tmp = 0;
	strcpy(players[i].name, name);
}

void add_team(char name[30], int money, int j, struct team teams[50]) {
	teams[j].team_ID = j + 1;
	strcpy(teams[j].name, name);
	teams[j].money = money;
}

// number whole of players i        i=0
// number whole of teams j          j=0

void buy(int p, int t, int i, int j) {
	if (p > i) {//
		printf("player with the id %d doesnt exist\n", p);
		return;
	}
	if (t > j) {//
		printf("team with the id %d doesnt exist\n", t);
		return;
	}
	if (teams[t - 1].money < players[p - 1].price) {
		printf("the team cant afford to buy this player\n");
		return;
	}
	if (players[p - 1].tmp == 1) {
		printf("player already has a team\n");
		return;
	}
	teams[t - 1].money -= players[p - 1].price;
	players[p - 1].tmp = 1;
	teams[t - 1].players_of_team[teams->countplayer] = players[p - 1];
	++teams[t - 1].countplayer;
	printf("player added to the team succesfully\n");
}

void sell(int p, int t, int i, int j) {
	if (t > j) {
		printf("team doesnt exist\n");
		return;
	}
	for (int g = 0; g < teams[t - 1].countplayer; ++g) {
		if (teams[t - 1].players_of_team[g].player_ID == players[p - 1].player_ID) {
			players[p - 1].tmp = 0;
			teams[t - 1].money += players[p - 1].price;
			for (int l = g; l < teams[t - 1].countplayer; ++g) {
				teams[t - 1].players_of_team[g] = teams[t - 1].players_of_team[g + 1];
			}
			--teams[t - 1].countplayer;
			printf("player sold succesfully\n");
			return;
		}
	}
	printf("team doesnt have this player\n");
	return;
}

void match(int t1, int t2, int j) {
	if (t1 > j || t2 > j) {
		printf("team doesnt exist\n");
		return;
	}
	if (teams[t1 - 1].countplayer < 11 || teams[t2 - 1].countplayer < 11) {
		printf("the game can not be held due to loss of the players\n");
		return;
	}
	int pow1 = 0, pow2 = 0;
	for (int i = 0; i < 11; ++i) {
		pow1 += teams[t1 - 1].players_of_team[i].speed + teams[t1 - 1].players_of_team[i].finishing;
	}
	for (int i = 0; i < 11; ++i) {
		pow2 += teams[t2 - 1].players_of_team[i].speed + teams[t2 - 1].players_of_team[i].defence;
	}
	if (pow1 == pow2) {
		return;
	}
	if (pow1 > pow2) {
		++teams[t1 - 1].win;
		++teams[t2 - 1].lose;
		teams[t1 - 1].money += 1000;
	}
	else {
		++teams[t2 - 1].win;
		++teams[t1 - 1].lose;
		teams[t2 - 1].money += 1000;
	}
}

void rank(int j) {
	for (int m = 0; m < j; ++m) {
		for (int n = 0; n < j - 1; ++n) {
			if (teams[n].win < teams[n + 1].win) {
				struct team tmp1 = teams[n];
				teams[n] = teams[n + 1];
				teams[n + 1] = tmp1;
			}
			else if (teams[n].win == teams[n + 1].win) {
				if (teams[n].lose > teams[n + 1].lose);
				struct team tmp1 = teams[n];
				teams[n] = teams[n + 1];
				teams[n + 1] = tmp1;
			}
		}
	}
	for (int m = 0; m < j; ++m) {
		printf("%d. %s\n", m + 1, teams[m].name);
	}
}

int main(void) {
	int i = 0, j = 0;

	for (int i = 0; i < 50; ++i) {
		players[i].defence = 0;
		players[i].speed = 0;
		players[i].price = 0;
		players[i].finishing = 0;
		players[i].tmp = 0;
	}
	for (int i = 0; i < 50; ++i) {
		teams[i].lose = 0;
		teams[i].countplayer = 0;
		teams[i].win = 0;
		teams[i].money = 0;
	}
	char str1[30];
	while (1) {
		scanf("%s", str1);
		if (strcmp(str1, "end") == 0)
			break;
		else if (strcmp(str1, "new") == 0) {
			scanf("%s", str1);
			if (strcmp(str1, "player") == 0) {
				char name[30];
				int price, speed, finishing, defence;
				scanf("%s%d%d%d%d", name, &price, &speed, &finishing, &defence);
				add_player(name, price, speed, finishing, defence, players, i);
				++i;
			}
			else if (strcmp(str1, "team") == 0) {
				int money;
				char name[30];
				scanf("%s%d", name, &money);
				add_team(name, money, j, teams);
				++j;
			}
		}
		else if (strcmp(str1, "buy") == 0) {
			int t1, t2;
			scanf("%d%d", &t1, &t2);
			buy(t1, t2, i, j);
		}
		else if (strcmp(str1, "rank") == 0) {
			rank(j);
		}
		else if (strcmp(str1, "sell") == 0) {
			int pid;
			int tid;
			scanf("%d%d", &pid, &tid);
			sell(pid, tid, i, j);
		}
		else if (strcmp(str1, "match")) {
			int t1, t2;
			scanf("%d%d", &t1, &t2);
			match(t1, t2, j);
		}
	}

	return 0;
}