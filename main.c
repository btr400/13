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


      int  numStockItems = 0, numSales = 0, numSaleItems, totalSaleItems = 0, cat;

      double sale, totalSales = 0.0;

 

      // Read existing stock from stdin

      printf("Enter current stock in format amount, category, price, byWeight, name (0 amount to end):\n");

 

      numStockItems = readStockItems(storeStock, MAX_STOCK_ENTRIES, STOCK_FROM_STDIN);

      printf("\n");
      // centreText(70, '*', " Seneca Groceries - Opening Stock ");
      printf("\n");
      // centreText(70, '=', "");
      printf("\n");
      printStockReport(storeStock, numStockItems);

	
      return 0;
} 
