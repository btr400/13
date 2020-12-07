//==============================================
// Name:           Brandon An
// Student Number: 152900197
// Email:          ban4@myseneca.ca
// Section:        NUU
// Date:           Wednesday December 9
//==============================================
// Final Part 2
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stock.h"

  
int readStockItems(struct StockRecord storestock, const int MAX_STOCK_ENTRIES, const int STOCK_FROM_STDIN)
{
struct StoreStock item[MAX_STOCK_ENTRIES] = { 0 };
int i;

printf("Enter current stock in format amount, category, price, byWeight, name (0 amount to end):\n");

for (i = 0; i < MAX_STOCK_ENTRIES; i++)
{
char buf[100];

fgets(buf, 100, stdin);

sscanf(buf, "%d %d %f %d %s", &item[i].amount, &item[i].category, &item[i].price, &item[i].weight, item[i].name);

if (item[i].amount == 0) break;

if (item[i].category > 1 || item[i].category < 7) {
printf("Invalid Category - Enter a number between 1 and 7:");
item[i].amount = '\0';
item[i].category = '\0';
item[i].price = '\0';
item[i].weight = '\0';
*item[i].name = '\0';
}

if (item[i].weight != 0 && item[i].weight != 1) {
printf("Invalid soldByWeight - Enter a number between 0 and 1:");
item[i].amount = '\0';
item[i].category = '\0';
item[i].price = '\0';
item[i].weight = '\0';
*item[i].name = '\0';
}
}
return i;
}


void centreText(int column, char line, char text[36])
{
int i;

for (i = 0; i < column; i++) {
printf("%c", line);
if (i == 10)
printf(" %s ", text);
}
}

void printStockReport(struct StockRecord item, int items)
{
int i;
printf("ID                        Product        Category   Price Quantity\n");
for (i = 0; i <= items; i++)
{
item[i].id = i + 1;
printf("%2d %30s %15d %7.2f %8d\n", item[i].id, item[i].name, item[i].category, item[i].price, item[i].amount);
}
return 0;
}

int readSale(struct StockRecord storestock, int items, struct Salesrecord saleitems)
{
char buf[100];
int i;
for (i = 0; i <= items; i++)
{
printf("Enter a product ID to purchase, and the quantity (0 to stop): ");
fgets(buf, 100, stdin);
sscanf(buf, "%d,%d", saleitems[i].id, saleitems[i].quantity);

if (saleitems[i].id == 0) break;

if (saleitems[i].id > 14 || saleitems[i].id < 0) {
printf("Invalid Product - Enter a number between 0 and 14: ");
saleitems[i].id = '\0';
saleitems[i].quantity = '\0';
}

if (saleitems[i].quantity < 0.1 || saleitems[i].quantity < 100) {
printf("Invalid quantity - Enter a number between 0.10 and 100.00: ");
saleitems[i].id = '\0';
saleitems[i].quantity = '\0';
}
return 0;
}
}



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "stock.h"



#define MAX_STOCK_ENTRIES 100

/***************************************************************/

/* Students who are implementing the file reading version for  */

/* bonus marks are allowed to change STOCK_FROM_STDIN to 0     */

/* to enable the program to read from a file.                  */

/***************************************************************/

#define STOCK_FROM_STDIN 1



int main(void)

{

    struct StockRecord storeStock[MAX_STOCK_ENTRIES] = { {{0, 0, 0.0, 0}, 0, 0.0} };

    struct SalesRecord saleItems[MAX_ITEMS_IN_SALE];

    struct SalesRecord topSellers[5];



    int  numStockItems = 0, numSales = 0, numSaleItems, totalSaleItems = 0, cat;

    double sale, totalSales = 0.0;



    // Read existing stock from stdin

    printf("Enter current stock in format amount, category, price, byWeight, name (0 amount to end):\n");



    numStockItems = readStockItems(storeStock, MAX_STOCK_ENTRIES, STOCK_FROM_STDIN);



    printf("\n");

    centreText(70, '*', " Seneca Groceries - Opening Stock ");

    printf("\n");

    centreText(70, '=', "");

    printf("\n");

    printStockReport(storeStock, numStockItems);



    printf("\n");

    centreText(70, '*', " Now in Sales Mode ");

    printf("\n");

    centreText(70, '=', "");

    printf("\n");

    do

    {

        numSaleItems = readSale(storeStock, numStockItems, saleItems);

        if (numSaleItems > 0)

        {

            sale = printSalesReport(storeStock, saleItems, numSaleItems);

            totalSales += sale;

            totalSaleItems += numSaleItems;

            numSales++;

        }

    } while (numSaleItems > 0);



    printf("\n");

    centreText(70, '*', " End of Day Summary ");

    printf("\n");

    centreText(70, '=', "");

    printf("\n");

    printf("%35s%8.2lf\n", "Cost of items sold before taxes", totalSales);

    printf("%35s%8d\n", "Number of Sales", numSales);

    printf("%35s%8.2lf\n\n", "Average items per sale", totalSaleItems / (double)numSales);



    printf("\n");

    centreText(70, '*', " Closing Stock ");

    printf("\n");

    centreText(70, '=', "");

    printf("\n");

    printStockReport(storeStock, numStockItems);

    printf("\n");

    for (cat = 0; cat < 5; cat++)

    {

        getTopSellers(storeStock, numStockItems, topSellers, 3, cat);

        printTopSellers(storeStock, topSellers, 3, cat);

    }

    for (cat = 5; cat < NUM_CATS; cat++)

    {

        getTopSellers(storeStock, numStockItems, topSellers, 2, cat);

        printTopSellers(storeStock, topSellers, 2, cat);

    }

    return 0;

}



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_STOCK_ENTRIES 100
#define STOCK_FROM_STDIN 1

void clearKeyboard(void)
{
while (getchar() != '\n'); // empty execution code block on purpose
}

struct StoreStock
{
int weight;
char name[20];
int category;
float price;
int amount;
int id;
};


struct SalesRecord
{
int id;
int quantity;
};



//struct SalesRecord saleItems[1] = { 0 };

struct StoreStock item[MAX_STOCK_ENTRIES] = { {1, "broccoli", 3, 3, 21 }, {10, "Chocolate cup cakes", 200, 4.4, 4} };

double printSalesReport(struct StoreStock* storestock, struct SaleRecord* saleitems, int items);

double printSalesReport(struct StoreStock* storestock, struct SaleRecord* saleitems, int items)
{
int i;
int sub;
int tax;
int total;
char label[10];
//struct SalesRecord storestock[20];

for (i = 0; i <= items; i++)
{

printf("%s %f %f\n", nameSearch(storestock->id,storestock), storestock[i].price, storestock[i].price * sale);
sub += storestock[i].price;

if (storestock[i].category == 6 || storestock[i].category == 7)
tax += storestock[i].price * 0.13;
}
return 0;
}

char* nameSearch(int id, struct StoreStock* storestock) {
int i;
int counter = 10;
for (i = 0; i < counter; i++) {
if (storestock[i].id == id)
return storestock[i].name;

}
}





int main()
{
printSales();
return 0;
}


//==============================================
// Name:           Brandon An
// Student Number: 152900197
// Email:          ban4@myseneca.ca
// Section:        NUU
// Date:           Wednesday December 9
//==============================================
// Final Part 2
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_STOCK_ENTRIES 100
#define STOCK_FROM_STDIN 1

struct StoreStock
{
int amount;
int category;
float price;
int weight;
char name[20];
int id;
};

struct SalesRecord
{
int id;
int quantity;
};


int readStockItems(struct StockRecord* storestock, int max, int input);

void centreText(int column, char line, char text[36]);

void printStockReport(struct StockRecord* storestock, int items);

int readSale(struct StockRecord* storestock, int items, struct SalesRecord* saleitems);

double printSalesReport(struct StockRecord* storestock, int sale, int items);

void getTopSellers(struct StockRecord* storestock, int numStockItems, struct SalesRecord* topSellers, int num, int loop);

void printTopSellers(struct StockRecord* storestock, struct SalesRecord* topSellers, int num, int loop);
