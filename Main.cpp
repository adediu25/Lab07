#include "LinkedList.h"
#include "Part.h"
#include <stdlib.h>     
#include <time.h>

using namespace std;

//Try to keep standard of "float" type for decimals to avoid type errors

int main()
{
	srand(time(0));


	///* 
	//FOR TESTING PART CLASS
	//*/
	//LinkedList<int> lst;
	//Part pogPart(2, "pog", 69.69, "poggers", 2);
	//cout << pogPart.GetPartInfo() << endl;
	//cout << "Price: " << pogPart.GetPrice() << endl;
	//cout << "Quantity: " << pogPart.GetQuantity() << endl;
	//

	int num1, num2;
	for (int i = 0; i < 5; i++) {
		int x = rand() % 10 + 1;
		if (i == 1)
			num1 = x;
		else if (i == 3)
			num2 = x;
		cout << "Adding " << x << endl;
		lst.addItem(x);
	}

	lst.print();

	cout << "Removing " << lst.removeItem(num1) << endl;
	cout << "Removing " << lst.removeItem(num2) << endl;

	lst.print();

	cout << "Item at index 1: " << lst.seeAt(1) << endl;

	cout << "Trying seeAt(5):\n";
	try
	{
		lst.seeAt(5);
	}
	catch (LinkedList<int>::OutOfBounds)
	{
		cout << "ERROR: index out of bounds.";
	}

	/*LinkedList<int> obj;
	int key;
	int data;
	int index;
	int ch;

	ch = 1;
	while (1)
	{
		cout << "1. creating 2. display 3. size 4.insert 5. delete1 6.inList 7. isEmpty 8. SeeAt 9.exit" << endl;
		cin >> ch;
		switch (ch)
		{
		case 1:
			obj.create();
			break;
		case 2:
			obj.print();
			break;
		case 3:
			obj.size();
			break;
		case 4:
			obj.addItem();
			break;
		case 5:
			obj.removeItem();
			break;
		case 6:
			cout << "Enter the key that needs to be found in the linked list: ";
			cin >> key;
			if (obj.isInList(key) == 1)
			{
				cout << "Key is present" << endl;
			}
			else
			{
				cout << "Key does not exist in the list" << endl;
			}
			break;
		case 7:
			if (obj.isEmpty() == 1)
			{
				cout << "The list is empty " << endl;
			}
			else
			{
				cout << "The list is not empty" << endl;
			}
			break;
		case 8:
			cout << "Enter the data to show its location in the linked list: " << endl;
			cin >> data;
			index = obj.seeAt(data);
			cout << "The data you entered is present at: " << index << endl;
			break;
		case 9:
			exit(0);

		}
	}*/


	return 0;
}
