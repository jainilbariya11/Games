#include <stdio.h>

int main() {
    int matchsticks = 21; // total matchsticks
    int pick;
    int turn = 1; // 1 for Player 1, 2 for Player 2

    printf("\nMatchstick Game\n");
    printf("Rules: Pick 1 to 4 matchsticks. The player who picks the last matchstick loses.\n\n");

    while (matchsticks > 0) 
    {
        printf("\nPlayer %d's turn. Matchsticks left: %d\n", turn, matchsticks);
        printf("Pick 1 to 4 matchsticks: ");
        scanf("%d/\n", &pick);

        // Validate input
        if (pick < 1 || pick > 4 || pick > matchsticks)   
        {
            printf("\nInvalid choice! Try again.\n");
            continue; // ask again
        }

        matchsticks -= pick; // reduce pile

        // Check if game ends
        if (matchsticks == 0) 
        {
            printf("\nPlayer %d picked the last matchstick.\n", turn);
            printf("----------------------------------------------------------------\n");
            printf("---> Player %d loses! Player %d wins!\n", turn, (turn == 1 ? 2 : 1));
            printf("----------------------------------------------------------------\n");
            break;
        }

        // Switch turn
        turn = (turn == 1) ? 2 : 1;
    }

    return 0;
}