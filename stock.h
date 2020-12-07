
struct S1
{
	int id;
	int cat;
	float price;
	int balqty;
};


struct StockRecord
{
	struct S1 s1;
	int byweight;
	float ex_cost;

};

struct IdtoName
{
	int id;
	char name[20];
};

struct CattoName
{
	int cat;
	char name[20];
};



int readStockItems(struct StockRecord * , int , int ); 
void printStockReport(struct StockRecord *, int numStockItems);
char * s_iton(int id);
char * s_cton(int cat);

