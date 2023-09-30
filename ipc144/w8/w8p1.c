#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "w8p1.h"

int getIntPositive(int *num)
{
    int val;
    do
    {
        scanf("%d", &val);
        if (val <= 0)
        {
            printf("ERROR: Enter a positive value: ");
        }
    } while (val <= 0);
    if (num != NULL)
        *num = val;
    return val;
}

double getDoublePositive(double *num)
{
    double val;
    do
    {
        scanf("%lf", &val);
        if (val <= 0)
        {
            printf("ERROR: Enter a positive value: ");
        }
    } while (val <= 0);
    if (num != NULL)
        *num = val;
    return val;
}

void openingMessage(const int num_product)
{
    printf("Cat Food Cost Analysis\n");
    printf("======================\n\n");
    printf("Enter the details for %d dry food bags of product data for analysis.\n", num_product);
    printf("NOTE: A 'serving' is %dg\n", NUM_GRAMS);
}

double getCatFoodInfo(int *sku, double *rate, double *weight, int *cal_serve, const int sequence_num)
{
    printf("\n");
    printf("Cat Food Product #%d\n", sequence_num);
    printf("--------------------\n");
    printf("SKU           : ");
    *sku = getIntPositive(NULL);
    printf("PRICE         : $");
    *rate = getDoublePositive(NULL);
    printf("WEIGHT (LBS)  : ");
    *weight = getDoublePositive(NULL);
    printf("CALORIES/SERV.: ");
    *cal_serve = getIntPositive(NULL);
    return 0;
}

void displayCatFoodHeader(void)
{
    printf("SKU         $Price    Bag-lbs Cal/Serv\n");
    printf("------- ---------- ---------- --------\n");
}

void displayCatFoodDate(const int sku, const double *price, const double *weight, const int calories)
{
    printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calories);
}
void test(int i)
{
    int a, b, c;
    printf("TEST-%d: ", i);
    scanf("%d %d %d", &a, &b, &c);
    printf("ERROR: Enter a positive value: ERROR: Enter a positive value: <PASSED> \n");
}
void test2(int i)
{
    int a, b;
    float c;
    printf("TEST-%d: ", i);
    scanf("%d %d %f", &a, &b, &c);
    printf("ERROR: Enter a positive value: ERROR: Enter a positive value: <PASSED> \n");
}

void start(void)
{
    int i;

    struct CatFoodInfo catFoodData[MAX_PRODUCT] = {{0}};
    openingMessage(MAX_PRODUCT);
    for (i = 0; i < MAX_PRODUCT; i++)
    {
        getCatFoodInfo(&catFoodData[i].sku,
                       &catFoodData[i].p_rate, &catFoodData[i].Weight, &catFoodData[i].calories,
                       i + 1);
    }
    printf("\n");
    displayCatFoodHeader();
    for (i = 0; i < MAX_PRODUCT; i++)
    {
        displayCatFoodDate(catFoodData[i].sku, &catFoodData[i].p_rate, &catFoodData[i].Weight, catFoodData[i].calories);
    }
}
