#include <stdio.h>
#include <iostream>

void WinTour(int *score) {
    char UserChoise, UserChoiseWhy;
    bool EnterValid = false;
    printf("who win this score? 0 - team A; 1 - team B.\n");
    do {
        std::cin.get(UserChoise);
        if (UserChoise == '1' || UserChoise == '0') {
            EnterValid = true;
        } else printf ("Enter is invalid.\n");
    } while (!EnterValid);
    EnterValid = false;
    if (UserChoise == '0')
    score[0]++;
    if (UserChoise == '1')
    score[1]++;
    printf("Why this team win score? a - atac; b - block; s - serve; e - error.\n");
    do {
        std::cin.get(UserChoiseWhy);
        if (UserChoiseWhy == 'a' || UserChoiseWhy == 'b' || UserChoiseWhy == 's' || UserChoiseWhy == 'e') {
            EnterValid = true;
        } else printf("Enter is invalid.\n");
    } while(!EnterValid);
} 
void CommandEnter(int *playersA, int *playersB) {
    printf("lineup of teams\n");
    printf("%d %d %d     %d %d %d\n", playersA[0], playersA[1], playersA[2], playersB[0], playersB[1], playersB[2]);
    printf("%d %d %d     %d %d %d\n", playersA[5], playersA[4], playersA[3], playersB[5], playersB[4], playersB[3]);
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

int main() {
    int scores[2], wins[2], playersA[6], playersB[6];
    for (int i = 0; i < 6; i++) {
        playersA[i] = i;
        playersB[i] = i;
    }
    WinTour(scores);
    revers(playersA);
    CommandEnter(playersA, playersB);
}
