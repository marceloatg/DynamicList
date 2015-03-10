#include <iostream>
#include "DynamicList.h"

using namespace std;

void main(void)
{
	DynamicList<float> list;

	cout << "TESTING LIST___________________________________________________________________" << endl;

	cout << "Add 100, add 200, add 250, add 50." << endl << endl;
	list.add(100.0f);
	list.add(200.0f);
	list.add(250.0f);
	list.add(50.0f);

	cout << "size of list: " << list.getSize() << endl;
	list.print();

	cout << endl << "Remove top." << endl;
	list.remove();

	cout << endl << "size of list: " << list.getSize() << endl;
	list.print();

	cout << endl << "Remove 4 times." << endl;
	list.remove();
	list.remove();
	list.remove();
	list.remove();

	cout << endl << "size of list: " << list.getSize() << endl;
	list.print();

	cout << endl << "Add 750, add 960." << endl << endl;
	list.add(750.0f);
	list.add(960.0f);
	cout << "Remove top." << endl;
	list.remove();
	cout << "Add 1250." << endl;
	list.add(1250.0f);
	
	cout << endl << "size of list: " << list.getSize() << endl;
	list.print();

	cout << "________________________________________________________________________________" << endl;
	system("pause");
	return;
}