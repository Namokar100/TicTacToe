#include <stdio.h>

void printBox();
int winCondition();
void system();

int main()
{
    
    char x = 'x', o = 'o';
    int ch = 100;
    int gameCount = 1;

    

    do
    {
        char a[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        int num, i;

        //printf("Game %d begins \n\n",gameCount);
        
        printBox(a);

        for (i = 1; i <= 9; i++)
        {
            if (i % 2 == 1)
            {
                printf("\n\n\t\t\t\t\t\t\t\t  Player 1 turn: \n\n\t\t\t\t\t\t\t\t  ");
                scanf("%d", &num);
                if (num < 1 || num > 9)
                {
                    printf("\t\t\t\t\t\t\t\t  Invalid input. Enter digit between 1 and 9:\n");
                    i = i - 1;
                    continue;
                }
                a[num - 1] = x;
                printBox(a);
            }
            else
            {
                printf("\n\n\t\t\t\t\t\t\t\t  Player 2 turn: \n\n\t\t\t\t\t\t\t\t  ");
                scanf("%d", &num);
                if (num < 1 || num > 9)
                {
                    printf("\t\t\t\t\t\t\t\t  Invalid input. Enter digit between 1 and 9:\n");
                    i = i - 1;
                    continue;  
                }
                a[num - 1] = o;
                printBox(a);
            }

            int result = winCondition(a, i);

            if (i % 2 == 1)
            {
                if (result == 1)
                {
                    printf("\n\n\t\t\t\t\t\t\t\t  Player 1 won the game \n\n\n");
                    i = 10;
                    printf("\t\t\t\t\t\t\t\t  Type 100 for rematch:\n\n\n\t\t\t\t\t\t\t\t  ");
                    scanf("%d", &ch);
                }
                if (result == 2)
                {
                    printf("\n\n\t\t\t\t\t\t\t\t  Draw! \n\n\n\n\n\t\t\t\t\t\t\t\t  ");
                    i = 10;
                    printf("\t\t\t\t\t\t\t\t  Type 100 for rematch:\n\n\n\t\t\t\t\t\t\t\t  ");
                    scanf("%d", &ch);
                }
            }
            else
            {
                if (result == 1)
                {
                    printf("\n\n\t\t\t\t\t\t\t\t  Player 2 won the game \n\n\n");
                    i = 10;
                    printf("\t\t\t\t\t\t\t\t  Type 100 for rematch:\n");
                    scanf("%d", &ch);
                }
                if (result == 2)
                {
                    printf("\n\n\t\t\t\t\t\t\t\t  Draw! \n\n\n\n\n\t\t\t\t\t\t\t\t  ");
                    i = 10;
                    printf("\t\t\t\t\t\t\t\t  Type 100 for rematch:\n\n\n\t\t\t\t\t\t\t\t  ");
                    scanf("%d", &ch);
                }
            }
        }
        gameCount++;
    } while (ch == 100);
}

void printBox(char a[])
{
    system("cls");
    printf("\t\t\t\t\t\t\t\t  === Tic Tac Toe ===\n\n\n");
    printf("\t\t\t\t\t\t\t\t        |      |   \n");
    printf("\t\t\t\t\t\t\t\t    %c   |  %c   |  %c \n", a[0], a[1], a[2]);
    printf("\t\t\t\t\t\t\t\t  ------|------|------   \n");
    printf("\t\t\t\t\t\t\t\t        |      |   \n");
    printf("\t\t\t\t\t\t\t\t    %c   |  %c   |  %c \n", a[3], a[4], a[5]);
    printf("\t\t\t\t\t\t\t\t  ------|------|------   \n");
    printf("\t\t\t\t\t\t\t\t        |      |   \n");
    printf("\t\t\t\t\t\t\t\t    %c   |  %c   |  %c \n", a[6], a[7], a[8]);
}

int winCondition(char a[], int i)
{

    if (a[0] == a[1] && a[1] == a[2])
    {
        return 1;
    }

    else if (a[3] == a[4] && a[4] == a[5])
    {
        return 1;
    }

    else if (a[6] == a[7] && a[7] == a[8])
    {
        return 1;
    }

    else if (a[0] == a[3] && a[3] == a[6])
    {
        return 1;
    }

    else if (a[1] == a[4] && a[4] == a[7])
    {
        return 1;
    }

    else if (a[2] == a[5] && a[5] == a[8])
    {
        return 1;
    }

    else if (a[0] == a[4] && a[4] == a[8])
    {
        return 1;
    }

    else if (a[2] == a[4] && a[4] == a[6])
    {
        return 1;
    }

    else if (i == 9)
    {
        return 2;
    }

    else
    {
        return -1;
    }
}