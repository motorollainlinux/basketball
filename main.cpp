#include <stdio.h>
#include <iostream>
#include <stdlib.h>

void WinTour(int *score, int *playersA, int *playersB, int &lastwin) {
    int ProgramChoiseWiner, ProgramChoiseWhy, ProgramChoisePlayer;
    srand(time(NULL));
    ProgramChoiseWiner = rand() % 2;
    ProgramChoiseWhy = rand() % 4;
    if (ProgramChoiseWiner == 0) {
        score[0]++;
        ProgramChoisePlayer = playersA[rand() % 6];
        lastwin = 0;
    } else {
        score[1]++;
        ProgramChoisePlayer = playersB[rand() % 6];
        lastwin = 1;
    }
    if (ProgramChoiseWhy == 0)
    printf("%d A %d\n", ProgramChoiseWiner, ProgramChoisePlayer); else
    if (ProgramChoiseWhy == 1)
    printf("%d B %d\n", ProgramChoiseWiner, ProgramChoisePlayer); else
    if (ProgramChoiseWhy == 2)
    printf("%d S %d\n", ProgramChoiseWiner, ProgramChoisePlayer); else
    if (ProgramChoiseWhy == 3) 
    printf("%d E \n", ProgramChoiseWiner);
    // Atak - Атака; Block - Блок; Serve - Подача; Error - Ошибка.
} 
void CommandEnter(int *playersA, int *playersB) {
    printf("lineup of teams\n");
    printf("%d %d %d     %d %d %d\n", playersA[0], playersA[1], playersA[2], playersB[0], playersB[1], playersB[2]);
    printf("%d %d %d     %d %d %d\n", playersA[5], playersA[4], playersA[3], playersB[5], playersB[4], playersB[3]);
}

void ChangePlayer(int *players) {
    int playerChangedNumber, changeto;
    bool playerfound = false, IsValidEnter = false;
    do {
    printf("How player you wanna change?");
    scanf("%d", &playerChangedNumber);
    for (int i = 0; i < 6; i++) {
        if (players[i] == playerChangedNumber) {
            playerChangedNumber = i;
            playerfound = true;
        }
    }
    if (playerfound == false)
    printf("this player not found.\n");
    } while(!playerfound);
    do {
        printf("How player replace him?\n");
        scanf("%d", &changeto);
        if (changeto >= 100)
        printf("It's too much.\n"); else
        if (changeto < 0)
        printf("It's too smal.\n"); else
        IsValidEnter = true;
    } while(!IsValidEnter);
    players[playerChangedNumber] = changeto;
    printf("successfully!\n");
}

void revers(int *players) {
    for (int i = 0, j = 0, k = 0; i < 6; i++) {
        if (i == 0) {
            j = players[0];
            players[0] = players[5];
        } else {
            k = players[i];
            players[i] = j;
            j = k;
        }
    }
}
void Game(int *scores, int *wins, int *playersA, int *playersB) {
    bool GameIsEnd = false, IsValidEnter = false;
    int UserChoise, lastwin = -1, prevwin = -1;
    wins[0] = 0; 
    wins[1] = 0;
    printf("In this game team A vs team B.\n");
    CommandEnter(playersA, playersB);
    do {
        if (wins[0] >= 3) {
            printf("win team A!\n");
            GameIsEnd = true;
            return;
        } else if (wins[1] >= 3) {
            printf("win team B!\n");
            GameIsEnd = true;
            return;
        }
        prevwin = lastwin;
        printf("0 - continue watchin; 1 - change player.\n");
        do {
            scanf("%d", &UserChoise);
            if (UserChoise == 0 || UserChoise == 1) {
                IsValidEnter = true;
            } else printf("Is not valid enter.\n");
        }while(!IsValidEnter);
        IsValidEnter = false;
        if (UserChoise == 0) {
            printf("This score: ");
            WinTour(scores, playersA, playersB, lastwin);
            printf("%d(%d) : %d(%d)\n", wins[0], scores[0], wins[1], scores[1]);
                if (prevwin == 1 && lastwin == 0) {
                    printf("team A has been changed!\n");
                    revers(playersA);
                    CommandEnter(playersA, playersB);
                } else if (prevwin == 0 && lastwin == 1) {
                    printf("team B has been changed!\n");
                    revers(playersB);
                    CommandEnter(playersA, playersB);
                }
            if (scores[0] >= 25 && scores[0] - scores[1] >= 2) {
                printf("team A win this round!\n");
                wins[0]++;
                scores[0] = 0;
                scores[1] = 0;
            } else if (scores[1] >= 25 && scores[1] - scores[0] >= 2) {
                printf("team B win this round!\n");
                wins[1]++;
                scores[0] = 0;
                scores[1] = 0;
            }
        } else {
            printf("Enter team a player. 0 - A team; 1 - B team\n");
            do {
                scanf("%d", &UserChoise);
                if (UserChoise == 0 || UserChoise == 1) {
                    IsValidEnter = true;
                } else printf("Is not valid enter.\n");
            } while(!IsValidEnter);
            IsValidEnter = false;
            if (UserChoise == 0)
            ChangePlayer(playersA); else
            ChangePlayer(playersB);
            CommandEnter(playersA, playersB);
        }
    } while(!GameIsEnd);
}
int main() {
    int scores[2], wins[2], playersA[6], playersB[6];
    srand(time(NULL));
    for (int i = 0; i < 6; i++) {
        playersA[i] = i + rand()  % 99;
        playersB[i] = i + rand()  % 99;
    }
    Game(scores, wins, playersA, playersB);
}
