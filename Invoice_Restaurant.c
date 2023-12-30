#include <stdio.h>

struct items
{
	char item[20];
	float price;
	int quantity;
};

struct orders
{
	char customer[50];
	char date[50];
	int numOfItems;
	struct items itm[50];
};

void generatedBillHeader(char name[50], char date[30])
{
	printf("\n");
	printf("\t Acui Restaurant");
	printf("\n\t ----------------");
	printf("\nDate : %s", date);
	printf("\nInvoice to : %s", name);
	printf("\n");
	printf("------------------------------");
	printf("Items\t\t");
	printf("Quantity\t\t");
	printf("Total\t\t");
	printf("------------------------------");
	printf("\n\n");
}

void generatedBillBody(char item[30], int quantity, float price)
{
	printf("%s\t\t", item);
	printf("%d\t\t", quantity);
	printf("\n");
}

void generatedBillFooter(float total)
{
	printf("\n");
	float dis = 0.1 * total;
	float netTotal = total - dis;
	float cgst = 0.09 * netTotal, grandTotal = netTotal + 2;
	printf("---------------------------------");
	printf("Sub Total\t\t\t%.2f", total);
	printf("\nDiscount @10%s\t\t\t%.2f","%", dis);
	printf("\n\t\t\t\t----------");
	printf("\nNet Total\t\t\t%.2f", netTotal);
	printf("\nCGST @9%s\t\t\t%.2f","%",cgst);
	printf("\nSGST @9%s\t\t\t%.2f","%",cgst);
	printf("\n---------------------------------");
	printf("\nGrand Total\t\t\t%.2f", grandTotal);
	printf("\n---------------------------------");
}

int main()
{
	float total = 0;
	int opt, n;
	struct orders ord;

	printf("==========================================\n"); 
	printf("   Generate Invoice Restaurant Project\n");
	printf("==========================================\n");
	printf("\tPlease select your preferred operations :\n");
	printf("\t 1. Generate Invoice\n");
	printf("\t 2. Show all Invoice\n");
	printf("\t 3. Search Invoices\n");
	printf("\t 4. Exit\n");

	printf("Your choice : ");
	scanf_s("%d",&opt);

	fgetc(stdin); // put this first before use fgets 

	switch (opt)
	{
	case 1 :
		printf("\nPlease enter customer name : ");
		fgets(ord.customer, 50, stdin); // follow this format
		ord.customer[strlen(ord.customer) - 1] = 0;
		strcpy(ord.date, __DATE__);
		printf("\nPlease enter number of the items : ");
		scanf_s("%d", &n);
		ord.numOfItems = n;

		for (int i = 0; i < n; i++)
		{
			fgetc(stdin);
			printf("\nPlease enter the items %d : ", i+1);
			fgets(ord.itm[i].item, 20, stdin);
			ord.itm[1].item[strlen(ord.itm[i].item) - 1] = 0;
			printf("Please enter the quantity : ");
			scanf_s("%d", &ord.itm[i].quantity);
			printf("Please enter the unit price : ");
			scanf_s("%f", &ord.itm[i].price);
			total += ord.itm[i].quantity * ord.itm[i].price;
		}

		generatedBillHeader(ord.customer, ord.date);
		for (int i = 0; i < ord.numOfItems; i++)
		{
			generatedBillBody(ord.itm[i].item, ord.itm[i].quantity, ord.itm[i].price);
		}
		generatedBillFooter(total);
	}



	return 0;
}