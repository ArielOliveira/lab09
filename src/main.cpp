#include <iostream>
using std::cout;
using std::endl;

#include <string>

#include "arielslib_list.h"

int main() {
	List<int> list;
	list.insertAtHead(5);
	int number = list.getData(1);
	cout << number << endl;
}