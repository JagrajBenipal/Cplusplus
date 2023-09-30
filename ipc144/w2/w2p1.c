/******************************************************************************
<assessment name example: Workshop - #2 (Part-1)>
Full Name : Jagraj Singh Benipal
Student ID#: 156374217
Email : jbenipal1@myseneca.ca
Section : ZEE
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
******************************************************************************/
#include <stdio.h>
int main ()
{
int pr1id=111;
char pr1tax='Y';
float pr1p= 111.49;

int pr2id=222;
char pr2tax='N';
float pr2p= 222.99;

int pr3id=111;
char pr3tax='N';
float pr3p= 334.49;


printf("Product Information\n");
printf("===================\n");

printf("Product-1 (ID:%d)\n",pr1id);
printf("  Taxed: %c\n", pr1tax);
printf("  Price: $%.4lf\n\n", pr1p);

printf("Product-2 (ID:%d)\n",pr2id);
printf("  Taxed: %c\n",pr2tax );
printf("  Price: $%.4lf\n\n",pr2p );

printf("Product-3 (ID:%d)\n",pr3id);
printf("  Taxed: %c\n", pr3tax);
printf("  Price: $%.4lf\n\n", pr3p);

printf("The average of all prices is: $%.4lf\n\n",pr2p );

printf("About Relational and Logical Expressions!\n");
printf("========================================\n");
printf("1. These expressions evaluate to TRUE or FALSE\n");
printf("2. FALSE: is always represented by integer value 0\n");
printf("3. TRUE : is represented by any integer value other than 0\n\n");

char Y;
Y=1;
float test;
test=330.99;


printf("Some Data Analysis...\n");
printf("=====================\n");

if (Y==1)
printf("1. Is product 1 taxable? -> 1\n\n");
else
printf("1. Is product 1 taxable? -> 0\n\n");
if (Y==1)
printf("2. Are products 2 and 3 both NOT taxable (N)? -> 1\n\n");
else
printf("2. Are products 2 and 3 both NOT taxable (N)? -> 0\n\n");
if (pr3p<test)
printf("3. Is product 3 less than testValue ($%.2lf)? -> 1\n\n", test);
else
printf("3. Is product 3 less than testValue ($%.2lf)? -> 0\n\n", test);
if (pr3p> pr1p+pr2p)
printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> 1\n\n");
else
printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> 0\n\n");
printf("5. Is the price of product 1 equal to or more than the price difference\n");
if (pr1p>=pr3p-pr2p)
printf("   of product 3 LESS product 2? ->  1 (price difference: $%.2lf)\n\n",pr3p-pr2p);
else
printf("   of product 3 LESS product 2? ->  0 (price difference: $%.2lf)\n\n",pr3p-pr2p);
if (pr2p>=(pr1p+pr2p+pr3p)/3)
printf("6. Is the price of product 2 equal to or more than the average price? -> 1\n\n");
else
printf("6. Is the price of product 2 equal to or more than the average price? -> 0\n\n");
if (pr1id!=pr2id&&pr1id!=pr3id)
printf("7. Based on product ID, product 1 is unique -> 1\n\n");
else
printf("7. Based on product ID, product 1 is unique -> 0\n\n");
if  (pr1id!=pr2id&&pr2id!=pr3id)
printf("8. Based on product ID, product 2 is unique -> 1\n\n");
else
printf("8. Based on product ID, product 2 is unique -> 0\n\n");
if  (pr3id!=pr2id&&pr1id!=pr3id)
printf("9. Based on product ID, product 3 is unique -> 1\n\n");
else 
printf("9. Based on product ID, product 3 is unique -> 0\n\n");



return 0;
}
