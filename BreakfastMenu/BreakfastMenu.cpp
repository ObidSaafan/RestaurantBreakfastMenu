#include <iostream>
#include <cstring>

using namespace std;

const int Num_Item = 8;

struct menuItemType
{
	string menuItem;
	double menuPrice;
};

void showMenu(menuItemType mList[], int listSize);
void printCheck(menuItemType fullList[], int itemsNums[], double orderMoney, int ordersMade);



int main()
{
	menuItemType menuList[Num_Item];
	int ordersMade = 0, item_num, itemsNums[Num_Item];

	double totalPrice = 0;
	char next_order = 'y';

	menuList[0].menuItem = { "Plain Egg" };
	menuList[1].menuItem = { "Bacon and Egg" };
	menuList[2].menuItem = { "Muffin" };
	menuList[3].menuItem = { "French Toast" };
	menuList[4].menuItem = { "Fruit Basket" };
	menuList[5].menuItem = { "Cereal" };
	menuList[6].menuItem = { "Coffee" };
	menuList[7].menuItem = { "Tea" };

	menuList[0].menuPrice = 1.45;
	menuList[1].menuPrice = 2.45;
	menuList[2].menuPrice = 0.99;
	menuList[3].menuPrice = 1.99;
	menuList[4].menuPrice = 2.49;
	menuList[5].menuPrice = 0.69;
	menuList[6].menuPrice = 0.50;
	menuList[7].menuPrice = 0.75;

	showMenu(menuList, Num_Item);



	for (int i = 0; i < Num_Item;)
	{
		cout << "Please enter the number of the item you would like to purchase: ";
		cin >> item_num;
		itemsNums[i] = item_num - 1;
		totalPrice = menuList[item_num - 1].menuPrice + totalPrice;
		ordersMade++;
		cout << "Would you like to purchase another item? y/n ";
		cin >> next_order;
		if (next_order == 'y' || (next_order == 'Y'))
		{

			i++;
		}
		else
		{

			printCheck(menuList, itemsNums, totalPrice, ordersMade);
			i = Num_Item;
		}
	}




	return 0;
}

void showMenu(menuItemType mList[], int listSize)
{
	cout << "Welcome to Johnny's Resturant" << endl;
	cout << "---- Today's Menu----" << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << i + 1 << ": ";
		cout << mList[i].menuItem;
		cout << " $" << mList[i].menuPrice << endl;
	}



}

void printCheck(menuItemType fullList[], int itemsNums[], double orderMoney, int ordersMade)
{
	double tax;

	tax = orderMoney * 5 / 100;



	for (int i = 1; i <= ordersMade; i++)
	{

		cout << fullList[itemsNums[i - 1]].menuItem;
		cout << " $" << fullList[itemsNums[i - 1]].menuPrice << endl;

	}
	cout << "Tax" << " $" << tax << endl;
	cout << "Total" << " $" << orderMoney + tax;


}

