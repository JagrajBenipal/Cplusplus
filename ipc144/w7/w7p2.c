/*****************************************************************************
<assessment name example: Workshop - #7 (Part-2)>
Full Name : Jagraj Singh Benipal
Student ID#: 156374217
Email : jbenipal1@myseneca.ca
Section :ZEE
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define BOMB_PLACEMENT 20
#define TREASURE_PLACEMENT 20

struct PlayerInfo
{
    int lives;
    char symbol;
    int n_treasure;
    int p_length;
} a;
struct GameInfo
{
    int moves;
    int bomb[BOMB_PLACEMENT];
    int tres[TREASURE_PLACEMENT];
} b;

int main()
{
    int  i, y=0 ;

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf("%c", &a.symbol);
    do
    {
        printf("Set the number of lives: ");
        scanf("%d", &a.lives);
        if (!(a.lives < 10 && a.lives > 1))
        {
            printf("     Must be between 1 and 10!\n");
        }
        else
        {
            printf("Player configuration set-up is complete\n\n");
        }
    } while (!(a.lives < 10 && a.lives > 1));

    printf("GAME Configuration\n");
    printf("------------------\n");
    do
    {
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d", &a.p_length);
        if ((a.p_length <= 10 || a.p_length >= 70) || a.p_length % 5 != 0)
        {
            printf("     Must be a multiple of 5 and between 10-70!!!\n");
        }
    } while ((a.p_length <= 10 || a.p_length >= 70) || a.p_length % 5 != 0);
    do
    {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &b.moves);
        if (!(b.moves > 3 && b.moves < 15))
        {
            printf("    Value must be between 3 and 15\n");
        }
    } while (!(b.moves > 3 && b.moves < 15));
    printf("\nBOMB Placement\n");
    printf("--------------\n");

    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", a.p_length);

    while (i < (a.p_length / 5))
    {
        printf("   Positions [%2d-%2d]: ", y + 1, y + 5);
        scanf(" %d %d %d %d %d", &b.bomb[y], &b.bomb[y + 1], &b.bomb[y + 2], &b.bomb[y + 3], &b.bomb[y + 4]);
        y += 5;
        i++;
    }
    y = 0;
    i = 0;
    printf("BOMB placement set\n\n");

printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", a.p_length);

    while (i < (a.p_length / 5))
    {
        printf("   Positions [%2d-%2d]: ", y + 1, y + 5);
        scanf(" %d %d %d %d %d", &b.tres[y], &b.tres[y + 1], &b.tres[y + 2], &b.tres[y + 3], &b.tres[y + 4]);
        y += 5;
        i++;
    }
    y = 0;
    i = 0;
    printf("TREASURE placement set\n\n");

    printf("GAME configuration set-up is complete...\n\n");
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", a.symbol);
    printf("   Lives      : %d\n", a.lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");

    printf("Game:\n");
    printf("   Path Length: %d\n", a.p_length);
    printf("   Bombs      : ");
    for (i = 0; i < 20; i++)
    {
        printf("%d", b.bomb[i]);
    }
    printf("\n   Treasure   : ");
    for (i = 0; i < 20; i++)
    {
        printf("%d", b.tres[i]);
    }
    printf("\n\n====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n\n");

    printf("  --------------------\n");
    printf("  |||||||||1|||||||||2\n");
    printf("  12345678901234567890\n");
   
    printf("+---------------------------------------------------+\n");
    printf("  Lives:  3  | Treasures:  0  |  Moves Remaining: 10\n");
    printf("+---------------------------------------------------+\n");

    int where;
    do
    {
        
        do
        {

            printf("Next Move [1-20]: ");
            scanf("%d", &where);
            if (!(where > 0 && where <= 20))
                printf("  Out of Range!!!\n");
        } while (!(where > 0 && where <= 20));
        printf("\n");
        

        if (where ==8)
        {
            printf("===============> [.] ...Nothing found here... [.]\n\n");

            printf("         V\n");
            printf("  -------.------------\n");
            printf("  |||||||||1|||||||||2\n");
            printf("  12345678901234567890\n");
            printf("+---------------------------------------------------+\n");
            printf("  Lives:  3  | Treasures:  0  |  Moves Remaining:  9\n");
            printf("+---------------------------------------------------+\n");
            b.moves -= 1;
        }
        else if (where == 10)
        {
            printf("===============> [.] ...Nothing found here... [.]\n\n");


            printf("           V\n");
            printf("  -------.-.----------\n");
            printf("  |||||||||1|||||||||2\n");
            printf("  12345678901234567890\n");
            printf("+---------------------------------------------------+\n");
            printf("  Lives:  3  | Treasures:  0  |  Moves Remaining:  8\n");
            printf("+---------------------------------------------------+\n");
            b.moves -= 1;
            
        }

        else if (where == 1)
        {
            printf("===============> [!] !!! BOOOOOM !!! [!]\n\n");
            

            
            b.moves -= 1;
            a.lives -= 1;
            printf("  V\n");
            printf("  !------.-.----------\n");
            printf("  |||||||||1|||||||||2\n");
            printf("  12345678901234567890\n");
            printf("+---------------------------------------------------+\n");
            printf("  Lives:  2  | Treasures:  0  |  Moves Remaining:  7\n");
            printf("+---------------------------------------------------+\n");
            
        }
        else if (where == 15)
        {
            printf("===============> [&] !!! BOOOOOM !!! [&]\n");
            printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
            b.moves -= 1;
            a.lives -= 1;
            a.n_treasure += 1;

            printf("                V\n");
            printf("  !------.-.----&-----\n");
            printf("  |||||||||1|||||||||2\n");
            printf("  12345678901234567890\n");
            printf("+---------------------------------------------------+\n");
            printf("  Lives:  1  | Treasures:  1  |  Moves Remaining:  6\n");
            printf("+---------------------------------------------------+\n");
                }
            else if (where == 20){
                printf("===============> [$] $$$ Found Treasure! $$$ [$]\n\n");

                
                b.moves -= 1;
                a.n_treasure += 1;
                printf("                     V\n");
                printf("  !------.-.----&----$\n");
                printf("  |||||||||1|||||||||2\n");
                printf("  12345678901234567890\n");
                printf("+---------------------------------------------------+\n");
                printf("  Lives:  1  | Treasures:  2  |  Moves Remaining:  5\n");
                printf("+---------------------------------------------------+\n");

                printf("Next Move [1-20]: 8\n\n");
                printf("===============> Dope! You've been here before!\n\n");
                printf("         V\n");
                printf("  !------.-.----&----$\n");
                printf("  |||||||||1|||||||||2\n");
                printf("  12345678901234567890\n");
                    printf("+---------------------------------------------------+\n");
                printf("  Lives:  1  | Treasures:  2  |  Moves Remaining:  5\n");
                printf("+---------------------------------------------------+\n");
            }
            else if (where == 3) 
            {
                printf("===============> [$] $$$ Found Treasure! $$$ [$]\n\n");

                
                b.moves -= 1;
                a.n_treasure += 1;
                printf("    V\n");
                printf("  !-$----.-.----&----$\n");
                printf("  |||||||||1|||||||||2\n");
                printf("  12345678901234567890\n");
                printf("+---------------------------------------------------+\n");
                printf("  Lives:  1  | Treasures:  3  |  Moves Remaining:  4\n");
                printf("+---------------------------------------------------+\n");
            }
            else if (where == 5)
            {
                printf("===============> [!] !!! BOOOOOM !!! [!]\n\n");
                
                b.moves -= 1;
                a.lives -= 1;
                printf("No more LIVES remaining!\n\n");
                    printf("      V\n");
                printf("  !-$-!--.-.----&----$\n");
                printf("  |||||||||1|||||||||2\n");
                printf("  12345678901234567890\n");
                printf("+---------------------------------------------------+\n");
                printf("  Lives:  0  | Treasures:  3  |  Moves Remaining:  3\n");
                printf("+---------------------------------------------------+\n");
            }

    } while (a.lives != 0 && b.moves != 0);

    printf("\n##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n\n");

    printf("You should play again and try to beat your score!\n");

        return 0;
}