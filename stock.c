#include "stock.h"
#include <stdio.h>
#include <string.h>

struct CattoName cattoname[7] = {{1,"produce"},{2,"bakery"},{3,"meat"},{4,"dairy"},{5,"baking"},{6,"house wares"},{7,"miscellaneous"}
};

struct IdtoName idtoname[100] = {{0," "} };


int readStockItems(struct StockRecord * item, int max_ent , int ent)
{

	extern struct CattoName cattoname[7];
	extern struct IdtoName idtoname[100];

	int i;
	char str1[100];
	char tmp_name[20];
	int counter=0;

	for (i=0; i<100;i++) 
	{

	while (1) {

	counter++;

	fgets(str1,100,stdin);

	sscanf(str1,"%d,%d,%f,%d,%s", &item[counter].s1.balqty,&item[counter].s1.cat,&item[counter].s1.price,&item[counter].byweight,tmp_name);

	if (item[counter].s1.balqty==0) return counter--;

	if (item[counter].s1.cat <1 || item[counter].s1.cat > 7) {
		printf("Invalid Category - Enter a number between 1 and 7:");
	item[counter].s1.balqty = 0;
	item[counter].s1.cat = 0;
	item[counter].s1.price = 0;
	item[counter].byweight = 0;
	idtoname[counter].id = '\0';
	idtoname[counter].name[0] = '\0';
	}
	
	if (item[counter].byweight !=0 && item[counter].byweight !=1) {
		printf("Invalid oldByWeight - Enter a number between and 1 :");
	item[counter].s1.balqty = 0;
	item[counter].s1.cat = 0;
	item[counter].s1.price = 0;
	item[counter].byweight = 0;
	idtoname[counter].id = 0;
	idtoname[counter].name[0] = '\0';

	}	
	counter --;
	}

	item[counter].s1.id = counter;
	idtoname[counter].id=counter;
	strcpy(idtoname[counter].name,tmp_name);


	}


return counter;

	}

void printStockReport(struct StockRecord * storeStock, int numStockItems)
{

	int i;

	for (i=0;i<numStockItems;i++)
	{
	printf("%d",storeStock[i].s1.id);
	printf("%15s",s_iton(storeStock[i].s1.id));
	printf("%30s",s_cton(storeStock[i].s1.cat));
	printf("%f",storeStock[i].s1.price);
	printf("%d",storeStock[i].s1.balqty);
	printf("\n");
	}



}

char * s_iton(int id)
{

	int i;

	for (i = 0; i<= 100; i++)
	{
		if (idtoname[i].id == id) 
		       return idtoname[i].name;
	}	

	return NULL;
}

char * s_cton(int cat)
{
	int i;
	for (i = 0; i<= 100; i++)
	{
		if (cattoname[i].cat == cat) 
		       return cattoname[i].name;
	}	

	return NULL;

}
