/******************************************************************************
<assessment name example: Workshop - #2 (Part-1)>
Full Name : Jagraj Singh Benipal
Student ID#: 156374217
Email : jbenipal1@myseneca.ca
Section : ZEE
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation
******************************************************************************/

#include <stdio.h> 
int main()
{
    
    int nos;
   float ps, pm, pl;
   float taxes=18.6800;

    printf("Set Shirt Prices\n");
    printf("================\n");
    printf("Enter the price for a SMALL shirt: $");
    scanf("%f", &ps);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%f", &pm);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%f", &pl);

    printf("\nShirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2f\n", ps);
    printf("MEDIUM : $%.2f\n", pm);
    printf("LARGE  : $%.2f\n\n", pl);

    printf("Patty's shirt size is 'S'\n");
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &nos);

    printf("\nPatty's shopping cart...\n");
    printf("Contains : %d shirts\n", nos);
    printf("Sub-total: $%8.4lf\n", 8*ps);
    printf("Taxes    : $%8.4lf\n", taxes);
    printf("Total    : $%8.4lf\n", taxes+8*ps);

    return 0;
}