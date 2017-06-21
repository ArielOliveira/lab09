#include <iostream>
using std::cout;
using std::endl;

#include "arielslib_list.h"
#include "arielslib_stack.h"

using namespace edb1;

int main() {
	edb1::List<int> list;
	list.insertAtHead(5);
	int number = list.getData(1);
	cout << number << endl;
}