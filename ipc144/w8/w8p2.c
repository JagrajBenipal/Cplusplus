#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "w8p2.h"
int getIntPositive(int *no1)
{
    int number;
    do
    {
        scanf("%d", &number);
        if (number <= 0)
        {
            printf("ERROR: Enter a positive value: ");
        }
    } while (number <= 0);

    if (no1 != NULL)
    {
        *no1 = number;
    }
    return number;
}

double getDoublePositive(double *no2)
{
    double double_number;
    do
    {
        scanf("%lf", &double_number);
        if (double_number <= 0)
        {
            printf("ERROR: Enter a positive value: ");
        }
    } while (double_number <= 0);
    if (no2 != NULL)
    {
        *no2 = double_number;
    }
    return double_number;
}


void openingMessage(const int no_of_prods)
{
    printf("Cat Food Cost Analysis\n");
    printf("======================\n");
    printf("\n");
    printf("Enter the details for %d dry food bags of product data for analysis.\n", no_of_prods);
    printf("NOTE: A 'serving' is %dg\n\n", GRAMS);
    return;
}


struct CatFoodInfo getCatFoodInfo(const int prod_num)
{
    struct CatFoodInfo c;
    printf("Cat Food Product #%d\n", prod_num + 1);
    printf("--------------------\n");
    printf("SKU           : ");
    getIntPositive(&c.prod_sku_num);
    printf("PRICE         : $");
    getDoublePositive(&c.prod_price);
    printf("WEIGHT (LBS)  : ");
    getDoublePositive(&c.prod_weight);
    printf("CALORIES/SERV.: ");
    getIntPositive(&c.calories_per_serv);
    printf("\n");
    return c;
}


void displayCatFoodHeader(void)
{
    printf("SKU         $Price    Bag-lbs Cal/Serv\n");
    printf("------- ---------- ---------- --------\n");
}


void displayCatFoodData(int sku, double *price, int calories, double *weight)
{
    printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calories);
    return;
}


double convertLbsKg(const double *pounds, double *kg)
{
    double kg_value;
    
    kg_value = *pounds / CONVERSION_FACT;
    if (kg != NULL)
    {
        *kg = kg_value;
    }
    return kg_value;
}

int convertLbsG(const double *pounds, int *grams)
{
    double kgs = 0.0;
    double kg;
    
    int g;
    kg = convertLbsKg(pounds, &kgs);
    g = kg * 1000;
    if (grams != NULL)
    {
        *grams = g;
    }
    return g;
}

void convertLbs(const double *pounds, double *kgs, int *grams)
{
    double KG1 = 0.0;
    int g1 = 0;
    double kg2, g2;
    kg2 = convertLbsKg(pounds, &KG1);
    *kgs = kg2;
    g2 = convertLbsG(pounds, &g1);
    *grams = g2;
}


double calculateServings(const int size, const int grams, double *serving)
{
    double servings;
    servings = (double)grams / (double)size;
    if (serving != NULL)
    {
        *serving = servings;
    }
    return servings;
}


double calculateCostPerServing(const double *price, const double *serving, double *cost_pr_serv)
{
    double cost;
    cost = *price / *serving;
    if (cost_pr_serv != NULL)
    {
        *cost_pr_serv = cost;
    }
    return cost;
}


double calculateCostPerCal(const double *price1, const double *cal, double *cost_pr_cal)
{
    double costs;
    costs = *price1 / *cal;
    if (cost_pr_cal != NULL)
    {
        *cost_pr_cal = costs;
    }
    return costs;
}


struct ReportData calculateReportData(const struct CatFoodInfo c)
{
    double klg = 0.0, serv = 0.0, costserv = 0.0, costprcal, total_cal = 0.0;
    int grm = 0.0;
    struct ReportData r;
    r.prod_sku = c.prod_sku_num;
    r.price = c.prod_price;
    r.calories = c.calories_per_serv;
    r.pound_weight = c.prod_weight;
    r.kilo_weight = convertLbsKg(&c.prod_weight, &klg);
    r.gram_weight = convertLbsG(&c.prod_weight, &grm);
    r.total_serving = calculateServings(GRAMS, r.gram_weight, &serv);
    r.cost = calculateCostPerServing(&c.prod_price, &r.total_serving, &costserv);
    total_cal = c.calories_per_serv * r.total_serving;
    r.calory_cost = calculateCostPerCal(&c.prod_price, &total_cal, &costprcal);
    return r;
}

void displayReportHeader(void)
{
    printf("\nAnalysis Report (Note: Serving = %dg)\n", GRAMS);
    printf("---------------\n");
    printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
    printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------");
}


void displayReportData(const struct ReportData r, const int c)
{
    if (c == 1)
    {
        printf("\n%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", r.prod_sku, r.price, r.pound_weight, r.kilo_weight, r.gram_weight, r.calories, r.total_serving, r.cost, r.calory_cost);
    }
    else
    {
        printf("\n%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf ***", r.prod_sku, r.price, r.pound_weight, r.kilo_weight, r.gram_weight, r.calories, r.total_serving, r.cost, r.calory_cost);
    }
}


void displayFinalAnalysis(const struct CatFoodInfo c)
{
    printf("\n\nFinal Analysis");
    printf("\n--------------");
    printf("\nBased on the comparison data, the PURRR-fect economical option is:");
    printf("\nSKU:%07d Price: $%.2lf", c.prod_sku_num, c.prod_price);
    printf("\n\nHappy shopping!");
}

void start()
{
    struct CatFoodInfo c[PRODUCTS] = {{0}};
    struct ReportData r[PRODUCTS] = {{0}};
    int np = 3, i;
    openingMessage(np);
    for (i = 0; i < np; i++)
    {
        c[i] = getCatFoodInfo(i);
        r[i] = calculateReportData(c[i]);
    }
    displayCatFoodHeader();
    for (i = 0; i < np; i++)
    {
        displayCatFoodData(c[i].prod_sku_num, &c[i].prod_price, c[i].calories_per_serv, &c[i].prod_weight);
    }
    double min = r[0].calory_cost; 
    for (i = 0; i < np; i++)
    {

        if (r[i].calory_cost < min)
            min = r[i].calory_cost;
    }

    displayReportHeader();
    for (i = 0; i < np; i++)
    {
        if (min == r[i].calory_cost)
        {
            displayReportData(r[i], 0);
        }
        else
        {
            displayReportData(r[i], 1);
        }
    }

    for (i = 0; i < np; i++)
    {
        if (min == r[i].calory_cost)
        {
            displayFinalAnalysis(c[i]);
        }
    }
    printf("\n\n");
    return;
}