#include "node.h"
#include "linked_list.h"
#include <iostream>

using namespace std;

int main()
{
	//Example main using the LinkedList to sort
	LinkedList<int> list;
	list.insertSorted(5);
	list.insertSorted(7);
	list.insertSorted(9);
	list.print();
	cout << endl;
	list.insertSorted(8);
	list.print();
	cout << endl;
	list.insertSorted(4);
	list.print();
}