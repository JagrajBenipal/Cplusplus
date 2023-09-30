#define MAX_PRODUCT 3
#define NUM_GRAMS 64
struct CatFoodInfo
{
	int sku;
	double p_rate;
	double Weight;
	int calories;
};
int getIntPositive(int* num);
double getDoublePositive(double* num);
void openingMessage(const int num_product);
double getCatFoodInfo(int* sku, double* rate, double* weight, int* cal_serve, const
	int sequence_num);
void displayCatFoodHeader(void);
void displayCatFoodDate(const int sku, const double* price, const double*
	weight, const int calories);
void start(void);
