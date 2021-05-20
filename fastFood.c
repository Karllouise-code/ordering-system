/* //* REQUIREMENT
1. Select an item from the menu
2. Add or remove item from the customer’s order
3. Accept payment from the customer
4. Create a digital Receipt of the transaction */
/* //* GUIDE
1. Display Menu
2. Get Orders
3. Review Orders
4. Payment
5. Receipt
6. Change
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//*SET NAME AND PRICE
char *productName[5] = {"Chicken", "Rice", "Spaghetti", "Diet Coke", "Juice"};
float productPrice[5] = {79, 20, 50, 20, 10};
float productQty[5] = {0, 0, 0, 0, 0};
int numberOfProducts = sizeof(productName) / 4;
float total = 0;
int code;
int qty;
int next;
int longest;
float cash, change;
int numberOfSpace;
char *receiptName;

//* FUNCTION PROTOTYPE
void menu();
int getOrders();
void reviewOrders();
void payment();
void receipt();
void spacer();

int main()
{

	printf("\n\t--Ordering System--\n\n");

	do
	{
		menu();
		printf("   (Press 0 to finish orders)\n");
		reviewOrders();
		next = getOrders();
		system("cls");
	} while (next);
	payment();
	receipt();
}

void menu()
{
	//*GET LENGTH OF LONGEST PRODUCT NAME
	longest = 0;
	for (int i = 0; i < numberOfProducts; i++)
	{
		if (longest < strlen(productName[i]))
		{
			longest = strlen(productName[i]);
		}
	}

	//* PRINT PRODUCTS
	printf("Code \tProductName \t   Price");
	for (int i = 0; i < numberOfProducts; i++)
	{
		printf("\n%d\t%s", i + 1, productName[i]);

		numberOfSpace = longest - strlen(productName[i]) + 10;
		spacer();

		printf("%.2f", productPrice[i]);
	}
	printf("\n");
}

int getOrders()
{

	printf("\nOrder\nCODE: ");
	scanf("%d", &code);
	if (code == 0)
	{
		return 0;
	}
	else
	{
		printf("QUANTITY: ");
		scanf("%d", &qty);
		productQty[code - 1] += qty;
		if (productQty[code - 1] < 0)
		{
			productQty[code - 1] = 0;
		}

		return 1;
	}
}

void reviewOrders()
{
	total = 0;
	printf("\nReview Orders\n");
	for (int i = 0; i < numberOfProducts; i++)
	{
		if (productQty[i] > 0)
		{
			printf("Code: %d\t\tPrice: %.2f\tQuantity: %.0f\tSubTotal: %.2f\n", i + 1, productPrice[i], productQty[i], productPrice[i] * productQty[i]);
		}
	}
	for (int i = 0; i < numberOfProducts; i++)
	{
		total += productPrice[i] * productQty[i];
	}
	printf("\nTotal: %.2f", total);
}

void payment()
{

	do
	{
		printf("Total: %.2f", total);
		printf("\nCash: ");
		scanf("%f", &cash);
		if (cash >= total)
		{
			change = cash - total;
			printf("Change: %.2f", change);
			break;
		}
		else
		{
			system("cls");
			printf("\tInsufficient Cash Try Again!\n");
		}
	} while (1);
}

void receipt()
{
	printf("\n\n\t\t\t   Trimex Colleges");
	printf("\n\t\tTrojan Building, Plaza Limaco, Poblacion, \n\t\t\tBinan City, Laguna");
	printf("\n\t\t\tTin#: 978-971-134309-5");
	printf("\n\nProduct Name \tQuantity\t  Price\t     Total\n");

	for (int i = 0; i < numberOfProducts; i++)
	{
		if (longest < strlen(productName[i]))
		{
			longest = strlen(productName[i]);
		}
	}

	for (int i = 0; i < numberOfProducts; i++)
	{
		if (productQty[i] > 0)
		{
			printf("%s", productName[i]);
			numberOfSpace = longest - strlen(productName[i]) + 10;
			spacer();
			printf("%.0f", productQty[i]);

			if (productQty[i] > 9)
			{
				numberOfSpace = 13;
				spacer();
				printf("%.2f", productPrice[i]);
			}
			else
			{

				numberOfSpace = 14;
				spacer();
				printf("%.2f", productPrice[i]);
			}
			if (productPrice[i] > 99)
			{
				numberOfSpace = 5;
				spacer();
				printf("%.2f\n", productPrice[i] * productQty[i]);
			}
			else
			{

				numberOfSpace = 6;
				spacer();
				printf("%.2f\n", productPrice[i] * productQty[i]);
			}
		}
	}
	total = 0;
	for (int i = 0; i < numberOfProducts; i++)
	{
		total += productPrice[i] * productQty[i];
	}
	printf("\n \t\t\t\t\t------");
	printf("\nTOTAL:   \t\t\t\t%.2f", total);
	printf("\nCASH:   \t\t\t\t%.2f\n", cash);
	printf("CHANGE:    \t\t\t\t%.2f", change);
}

void spacer()
{

	for (int j = 0; j < numberOfSpace; j++)
	{
		printf(" ");
	}
}
