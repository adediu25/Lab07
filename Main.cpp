#include "LinkedList.h"
#include "Part.h"
#include "DLL.h"
#include <stdlib.h>     
#include <time.h>

using namespace std;

//Try to keep standard of "float" type for decimals to avoid type errors

int main()
{
	std::srand(time(0));

	LinkedList<Part> partList;

	int choice = 9;

	while (choice != 0) {
		cout << "Enter number for function for list:\n1 for addItem\n"
			<< "2 for removeItem\n3 for isInList\n4 for isEmpty\n"
			<< "5 for size\n6 for seeAt\n7 for print\n"
			<< "0 to quit\n";
		cin >> choice;

		int partNum, qoh;
		float partPrice;
		string desc, uom;
		bool result;
		Part* newPart;

		switch (choice) {
		case 1:
			cout << "Enter part number: ";
			cin >> partNum;
			cout << "Enter product description: ";
			cin >> desc;
			cout << "Enter product price: ";
			cin >> partPrice;
			cout << "Enter unit of measure: ";
			cin >> uom;
			cout << "Enter quantity on hand: ";
			cin >> qoh;

			newPart = new Part(partNum, desc, partPrice, uom, qoh);
			partList.addItem(newPart);
			break;
		case 2:
			cout << "Enter part number of part you want to remove: ";
			cin >> partNum;

			newPart = new Part(partNum);
			newPart = partList.removeItem(newPart);
			delete newPart;
			break;
		case 3:
			cout << "Enter part number of the part: ";
			cin >> partNum;

			newPart = new Part(partNum);
			result = partList.isInList(newPart);

			if (result == true)
				cout << "List contains part\n";
			else
				cout << "Part is not in list\n";
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

			try
			{
				cout << "Part:\n" << partList.seeAt(partNum)->GetPartInfo() << endl;
			}
			catch (doubleLL<int>::OutOfBounds())
			{
				cout << "ERROR: index out of bounds.";
			}
			
			break;
		case 7:
			partList.print();
			break;
		default:
			break;
		}
	}

	doubleLL<int> lst;

	int *num1, *num2;
	num1 = nullptr;
	num2 = nullptr;
	for (int i = 0; i < 5; i++) {
		int* x = new int(rand() % 10 + 1);
		if (i == 1)
			num1 = new int(*x);
		else if (i == 3)
			num2 = new int(*x);
		cout << "Adding " << *x << endl;
		lst.addItem(x);
		delete x;
	}

	lst.print();
	lst.reversePrint();
	cout << "Removing " << *num1 << endl;
	lst.removeItem(num1);
	cout << "Removing " << *num2 << endl;
	lst.removeItem(num2);
	lst.print();
	lst.reversePrint();

	delete num1;
	delete num2;
	return 0;
}
