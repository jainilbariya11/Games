
#include <stdio.h>

int main()
{
    char name1[30], name2[30];
    char board[3][3];
    long int symbol;
     long int i, j, choice;
    int row, col;
    int moves = 0;
    int winner = 0;

    printf("Enter Player 1 name: ");
    scanf("%29s", name1);

    printf("Enter Player 2 name: ");
    scanf("%29s", name2);

    // Initialize the board
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }

    // Game starts
    while(moves < 9 && winner == 0)
    {
        // Display board
        printf("\n");

        for(i = 0; i < 3; i++)
        {
            for(j = 0; j < 3; j++)
            {
                if(board[i][j] == ' ')
                    printf(" ⬜ ");
                else if(board[i][j] == 'X')
                    printf(" ❌️ ");
                else 
                    printf(" ⭕️ ");

                if(j < 2)
                    printf("|");
            }

            printf("\n");
            if(i < 2)
                printf("----+----+----\n");
        }

        // Select player using modulo
        if(moves % 2 == 0)
        {
            printf("\n%s (*), enter row and column (1-3): ",
                   name1);
            symbol = '*';
        }
        else
        {
            printf("\n%s (O), enter row and column (1-3): ",
                   name2);
            symbol = 'O';
        }

        scanf("%d %d", &row, &col);

        // Check valid position
        if(row < 1 || row > 3 || col < 1 || col > 3)
        {
            printf("Invalid position! Try again.\n");
            continue;
        }

        row--; // For According to C language Index Adjustment
        col--; // Index start from 0 but we have enter from 1.

        // Check empty cell
        if(board[row][col] != ' ')
        {
            printf("This cell is already occupied! Try again.\n");
            continue;
        }

        board[row][col] = symbol;
        moves++;

        // Check rows and columns
        for(i = 0; i < 3; i++)
        {
            if(board[i][0] == symbol &&
               board[i][1] == symbol &&
               board[i][2] == symbol)
                winner = 1;

            if(board[0][i] == symbol &&
               board[1][i] == symbol &&
               board[2][i] == symbol)
                winner = 1;
        }

        // Check diagonals
        if(board[0][0] == symbol &&
           board[1][1] == symbol &&
           board[2][2] == symbol)
            winner = 1;

        if(board[0][2] == symbol &&
           board[1][1] == symbol &&
           board[2][0] == symbol)
            winner = 1;

        // Declare winner
        if(winner == 1)
        {
            printf("\n");

            for(i = 0; i < 3; i++)
            {
                for(j = 0; j < 3; j++)
                {
                    if(board[i][j] == ' ')
                        printf(" ⬜ ");
                    else if(board[i][j] == 'X')
                        printf(" ❌️ ");
                    else
                        printf(" ⭕️ ");

                    if(j < 2)
                        printf("|");
                }

                printf("\n");
                if(i < 2)
                    printf("---+---+---\n");
            }

            if(symbol == 'X')
                printf("\nCongratulations %s! You are the winner!\n",
                       name1);
            else
                printf("\nCongratulations %s! You are the winner!\n",
                       name2);
        }
    }

    if(winner == 0)
        printf("\nGame Draw! Nobody wins.\n");

    return 0;
}

