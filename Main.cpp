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
	/*LinkedList<int> lst;
	Part pogPart(2, "pog", 69.69f, "poggers");
	cout << pogPart.GetPartInfo() << endl;
	cout << "Price: " << pogPart.GetPrice() << endl;
	cout << "Quantity: " << pogPart.GetQuantity() << endl;
	

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
	}*/

	LinkedList<Part> partList;

	int choice;
	cout << "Enter number for function for list:\n1 to add item\n"
		<< "2 to remove item\n3 to see if item is in list\n4 to see if list is empty\n"
		<< "5 to get size of list\n6 to see item at an index\n7 to print contents of list\n";
	cin >> choice;

	int partNum, qoh;
	float partPrice;
	string desc, uom;
	bool result;

	switch (choice) {
	case 1:
		cout << "Enter part number: ";
		cin >> partNum;
		cout << "Enter product description: ";
		getline(cin, desc);
		cout << "Enter product price: ";
		cin >> partPrice;
		cout << "Enter unit of measure: ";
		getline(cin, uom);
		cout << "Enter quantity on hand: ";
		cin >> qoh;

		Part* newPart = new Part(partNum, desc, partPrice, uom, qoh);
		partList.addItem(*newPart);
		delete newPart;
		break;
	case 2:
		cout << "Enter part number of part you want to remove: ";
		cin >> partNum;
		
		Part* newPart = new Part(partNum);
		partList.removeItem(*newPart);
		delete newPart;
		break;
	case 3:
		cout << "Enter part number of the part: ";
		cin >> partNum;

		Part* newPart = new Part(partNum);
		result = partList.isInList(*newPart);

		if (result == true)
			cout << "List contains part\n";
		else
			cout << "Part is not in list\n";

		delete newPart;
		break;
	case 4:
		result = partList.isEmpty();

		if (result == true)
			cout << "List is empty\n";
		else
			cout << "Part is not empty\n";
		break;
	case 5:
		partNum = partList.size();
		cout << "List contains " << partNum << " parts\n";
		break;
	case 6:
		cout << "Enter index for list: ";
		cin >> partNum;

		cout << "Part:\n" << partList.seeAt(partNum).GetPartInfo() << endl;
		break;
	case 7:
		partList.print();
		break;
	default:
		break;
	}

	return 0;
}
