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

int bw1, bw2, bw3, ds1, ds2;
char  type1, type2, type3, gs1, gs2, gs3, cream1, cream2, cream3, cream4, str1;
double temp1, temp2, temp3;

bw1=250;
bw2=500;
bw3=1000;
ds1=6;
ds2=10;
type1= 'l';
type2= 'B';
type3 = 'L';
gs1 = 'c';
gs2 = 'F';
gs3 = 'f';
cream1 = 'y';
cream2 = 'N';
cream3 = 'n';
cream4 = 'R';
str1 = 'm';
temp1 = 65.7;
temp2 = 70.0;
temp3 = 80.5;

printf("Take a Break - Coffee Shop\n");
printf("==========================\n\n");

printf("Enter the coffee product information being sold today...\n\n");

printf("COFFEE-1...\n");
printf("Type ([L]ight,[B]lend): ");
scanf(" %c",&type1);
printf("Grind size ([C]ourse,[F]ine): ");
scanf(" %c",&gs1);
printf("Bag weight (g): ");
scanf(" %d",&bw1);
printf("Best served with cream ([Y]es,[N]o): ");
scanf(" %c",&cream1);
printf("Ideal serving temperature (Celsius): ");
scanf(" %lf",&temp1);

printf("\nCOFFEE-2...\n");
printf("Type ([L]ight,[B]lend): ");
scanf(" %c",&type2);
printf("Grind size ([C]ourse,[F]ine): ");
scanf(" %c",&gs2);
printf("Bag weight (g): ");
scanf(" %d",&bw2);
printf("Best served with cream ([Y]es,[N]o): ");
scanf(" %c",&cream2);
printf("Ideal serving temperature (Celsius): ");
scanf(" %lf",&temp2);

printf("\nCOFFEE-3...\n");
printf("Type ([L]ight,[B]lend): ");
scanf(" %c",&type3);
printf("Grind size ([C]ourse,[F]ine): ");
scanf(" %c",&gs3);
printf("Bag weight (g): ");
scanf(" %d",&bw3);
printf("Best served with cream ([Y]es,[N]o): ");
scanf(" %c",&cream3);
printf("Ideal serving temperature (Celsius): ");
scanf(" %lf",&temp3);

printf("\n---+---------------+---------------+---------------+-------+--------------\n");
printf("   |    Coffee     |    Coffee     |   Packaged    | Best  |   Serving\n");
printf("   |     Type      |  Grind Size   |  Bag Weight   | Served| Temperature\n");
printf("   +---------------+---------------+---------------+ With  +--------------\n");
printf("ID | Light | Blend | Course | Fine |  (G) | Lbs    | Cream |   (C) |   (F)\n");
printf("---+---------------+---------------+---------------+-------+--------------\n");
printf(" 1 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n", type1 == 'l', type1 == 'B', gs1 == 'c', gs1 == 'F', bw1, bw1 / 453.5924, cream1 == 'y', temp1, (temp1*1.8) + 32);
printf(" 2 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n", type2 == 'l', type2 == 'B', gs2 == 'c', gs2 == 'F', bw2, bw2 / 453.5924, cream2 == 'y', temp2, (temp2*1.8) + 32);
printf(" 3 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n\n", type3 == 'L', cream3 == 'B', gs3 == 'c', cream3== 'n', bw3, bw3 / 453.5924, cream3 == 'y', temp3, (temp3*1.8) + 32);

printf("Enter how you like your coffee and the coffee maker equipment you use...\n\n");
printf("Coffee strength ([M]ild,[R]ich): ");
scanf(" %c",&str1);
printf("Do you like your coffee with cream ([Y]es,[N]o): ");
scanf(" %c",&cream4);
printf("Typical number of daily servings: ");
scanf(" %d",&ds1);
printf("Maker ([R]esidential,[C]ommercial): ");
scanf(" %c",&gs1);

printf("\nThe below table shows how your preferences align to the available products:\n\n");
printf("--------------------+--------------------+-------------+-------+--------------\n");
printf("  |     Coffee      |       Coffee       |  Packaged   | With  |   Serving\n");
printf("ID|      Type       |     Grind Size     | Bag Weight  | Cream | Temperature\n");
printf("--+-----------------+--------------------+-------------+-------+--------------\n");
printf(" 1|       %d         |         %d          |      %d      |   %d   |      %d\n", str1 == 'm', str1 == 'R', gs1 == 'm', cream1 == 'y', cream2 == 'y');
printf(" 2|       %d         |         %d          |      %d      |   %d   |      %d\n", type2 == 'y', type3 == 'L', gs3 == 'f', type1 == 'n', str1 == 'm');
printf(" 3|       %d         |         %d          |      %d      |   %d   |      %d\n\n", type1=='l', type2=='B', type3=='f', cream2=='n', cream1=='y');

printf("Enter how you like your coffee and the coffee maker equipment you use...\n\n");

printf("Coffee strength ([M]ild,[R]ich): ");
scanf(" %c",&cream4);
printf("Do you like your coffee with cream ([Y]es,[N]o): ");
scanf(" %c",&cream2);
printf("Typical number of daily servings: ");
scanf(" %d",&ds2);
printf("Maker ([R]esidential,[C]ommercial): ");
scanf(" %c",&cream4);
printf("\nThe below table shows how your preferences align to the available products:\n\n");
printf("--------------------+--------------------+-------------+-------+--------------\n");
printf("  |     Coffee      |       Coffee       |  Packaged   | With  |   Serving\n");
printf("ID|      Type       |     Grind Size     | Bag Weight  | Cream | Temperature\n");
printf("--+-----------------+--------------------+-------------+-------+--------------\n");
printf(" 1|       %d         |         %d          |      %d      |   %d   |      %d\n", type1 == 'c', gs1 == 'c', cream1 == 'l', gs2 == 'y', gs2 == 'F');
printf(" 2|       %d         |         %d          |      %d      |   %d   |      %d\n", type2 == 'B', str1 == 'f',  cream4 == 'c', cream4 == 'R', cream4 == 'y');
printf(" 3|       %d         |         %d          |      %d      |   %d   |      %d\n\n", gs2=='R', str1=='R', str1=='m', gs3=='f', gs3=='L');

printf("Hope you found a product that suits your likes!\n");

return 0;
}