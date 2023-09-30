/*****************************************************************************
<assessment name example: Workshop - #7 (Part-1)>
Full Name : Jagraj Singh Benipal
Student ID#: 156374217
Email : jbenipal1@myseneca.ca
Section :ZEE
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation
*****************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define P_LENGTH
#define BOMB_PLACEMENT 35
#define TREASURE_PLACEMENT 35
int i;
struct PlayerInfo
{
    int lives;
    char symbol;
    int n_treasure;
    int p_length[P_LENGTH];
} a;
struct GameInfo
{
    int moves;
    int bomb[BOMB_PLACEMENT];
    int tres[TREASURE_PLACEMENT];
} b;
int main(){

 printf("================================\n");
 printf("         Treasure Hunt!\n");
 printf("================================\n\n");
 printf("PLAYER Configuration\n");
 printf("--------------------\n");
 printf("Enter a single character to represent the player: ");
 scanf("%c", &a.symbol);
do{
    printf("Set the number of lives: ");
    scanf("%d", &a.lives);
    if (!(a.lives < 10 && a.lives > 1)){
    printf("     Must be between 1 and 10!\n");}
    else{
        printf("Player configuration set-up is complete\n\n");
    }
} while (!(a.lives < 10 && a.lives > 1));

printf("GAME Configuration\n");
printf("------------------\n");
do
{
    printf("Set the path length (a multiple of 5 between 10-70): ");
    scanf("%d", &a.p_length[0]);
    if ((a.p_length[0] <= 10 || a.p_length[0] >= 70) || a.p_length[0] % 5 != 0)
    {
        printf("     Must be a multiple of 5 and between 10-70!!!\n");
    }
} while ((a.p_length[0] <= 10 || a.p_length[0] >= 70) || a.p_length[0] % 5 != 0);
do
{
    printf("Set the limit for number of moves allowed: ");
    scanf("%d", &b.moves);
    if (!(b.moves > 3 && b.moves < 26))
    {
        printf("    Value must be between 3 and 26\n");
    }
} while (!(b.moves > 3 && b.moves < 26));
printf("\nBOMB Placement\n");
printf("--------------\n");
printf("Enter the bomb positions in sets of 5 where a value\n");
printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", a.p_length[0]);
printf("   Positions [ 1- 5]: ");
scanf("%d %d %d %d %d", &b.bomb[0], &b.bomb[1], &b.bomb[2], &b.bomb[3], &b.bomb[4]);
printf("   Positions [ 6-10]: ");
scanf("%d %d %d %d %d", &b.bomb[5], &b.bomb[6], &b.bomb[7], &b.bomb[8], &b.bomb[9]);
printf("   Positions [11-15]: ");
scanf("%d %d %d %d %d", &b.bomb[10], &b.bomb[11], &b.bomb[12], &b.bomb[13], &b.bomb[14]);
printf("   Positions [16-20]: ");
scanf("%d %d %d %d %d", &b.bomb[15], &b.bomb[16], &b.bomb[17], &b.bomb[18], &b.bomb[19]);
printf("   Positions [21-25]: ");
scanf("%d %d %d %d %d", &b.bomb[20], &b.bomb[21], &b.bomb[22], &b.bomb[23], &b.bomb[24]);
printf("   Positions [26-30]: ");
scanf("%d %d %d %d %d", &b.bomb[25], &b.bomb[26], &b.bomb[27], &b.bomb[28], &b.bomb[29]);
printf("   Positions [31-35]: ");
scanf("%d %d %d %d %d", &b.bomb[30], &b.bomb[31], &b.bomb[32], &b.bomb[33], &b.bomb[34]);
printf("BOMB placement set\n");

printf("\nTREASURE Placement\n");
printf("------------------\n");
printf("Enter the treasure placements in sets of 5 where a value\n");
printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", a.p_length[0]);
printf("   Positions [ 1- 5]: ");
scanf("%d %d %d %d %d", &b.tres[0], &b.tres[1], &b.tres[2], &b.tres[3], &b.tres[4]);
printf("   Positions [ 6-10]: ");
scanf("%d %d %d %d %d", &b.tres[5], &b.tres[6], &b.tres[7], &b.tres[8], &b.tres[9]);
printf("   Positions [11-15]: ");
scanf("%d %d %d %d %d", &b.tres[10], &b.tres[11], &b.tres[12], &b.tres[13], &b.tres[14]);
printf("   Positions [16-20]: ");
scanf("%d %d %d %d %d", &b.tres[15], &b.tres[16], &b.tres[17], &b.tres[18], &b.tres[19]);
printf("   Positions [21-25]: ");
scanf("%d %d %d %d %d", &b.tres[20], &b.tres[21], &b.tres[22], &b.tres[23], &b.tres[24]);
printf("   Positions [26-30]: ");
scanf("%d %d %d %d %d", &b.tres[25], &b.tres[26], &b.tres[27], &b.tres[28], &b.tres[29]);
printf("   Positions [31-35]: ");
scanf("%d %d %d %d %d", &b.tres[30], &b.tres[31], &b.tres[32], &b.tres[33], &b.tres[34]);
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
printf("   Path Length: %d\n", a.p_length[0]);
printf("   Bombs      : ");
for (i = 0; i < 35; i++)
{
    printf("%d", b.bomb[i]);
}
printf("\n   Treasure   : ");
for (i = 0; i < 35; i++)
{
    printf("%d", b.tres[i]);
}
printf("\n\n====================================\n");
printf("~ Get ready to play TREASURE HUNT! ~\n");
printf("====================================\n");

return 0;
}