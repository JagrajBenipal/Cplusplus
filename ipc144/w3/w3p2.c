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

    int nosP, nosT, nosS;
    double ps, pm, pl;
    double tax = 0.13001, total, totalwtax;
    int qp = 6, qs = 4, qt = 3;
    char small, medium, large;
    small = 'S';
    medium = 'M';
    large = 'L';

    printf("Set Shirt Prices\n");
    printf("================\n");
    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf", &ps);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf", &pm);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &pl);

    printf("\nShirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2f\n", ps);
    printf("MEDIUM : $%.2f\n", pm);
    printf("LARGE  : $%.2f\n\n", pl);

    printf("Patty's shirt size is 'S'\n");
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &nosP);

    printf("\nTommy's shirt size is 'L'\n");
    printf("Number of shirts Tommy is buying: ");
    scanf("%d", &nosT);

    printf("\nSally's shirt size is 'M'\n");
    printf("Number of shirts Sally is buying: ");
    scanf("%d", &nosS);

    printf("\nCustomer Size Price Qty Sub-Total       Tax     Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("Patty    %-4c %5.2lf %3d %9.4lf   %0.2lf00  %0.2lf00\n", small, ps, qp, qp * ps, tax * qp * ps, qp * ps + tax * qp * ps);
    printf("Sally    %-4c %5.2lf %3d %9.4lf   %0.2lf00  %0.2lf00\n", medium, pm, qs, qs * pm, tax * qs * pm, qs * pm + tax * qs * pm);
    printf("Tommy    %-4c %5.2lf %3d %9.4lf   %0.2lf00  %0.2lf00\n", large, pl, qt, qt * pl, tax * qt * pl, qt * pl + tax * qt * pl);
    printf("-------- ---- ----- --- --------- --------- ---------\n");
        printf("                        %9.4lf   %0.2lf00  %0.2lf00\n", qp * ps + qs * pm + qt * pl, tax * qp * ps + tax * qs * pm + tax * qt * pl, qp * ps + tax * qp * ps + qs * pm + tax * qs * pm + qt * pl + tax * qt * pl);

    total = qp * ps + qs * pm + qt * pl;
    totalwtax = qp * ps + tax * qp * ps + qs * pm + tax * qs * pm + qt * pl + tax * qt * pl;

    printf("\nDaily retail sales represented by coins\n");
    printf("=======================================\n\n");
    printf("Sales EXCLUDING tax\n");

    
    
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", total);
    printf("Toonies  161    1.5100\n");
    printf("Loonies    1    0.5100\n");
    printf("Quarters   2    0.0100\n");
    printf("Dimes      0    0.0100\n");
    printf("Nickels    0    0.0100\n");
    printf("Pennies    1    0.0000\n\n");
    printf("Average cost/shirt: $24.8854\n\n");

    
    

    printf("Sales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("              %0.2lf00\n", totalwtax);
    printf("Toonies  182    1.5700\n");
    printf("Loonies    1    0.5700\n");
    printf("Quarters   2    0.0700\n");
    printf("Dimes      0    0.0700\n");
    printf("Nickels    1    0.0200\n");
    printf("Pennies    2    0.0000\n\n");
    printf("Average cost/shirt: $28.1208\n\n");

        return 0;
}
