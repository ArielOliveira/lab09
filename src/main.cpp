#include <iostream>
using std::cout;
using std::endl;

#include "arielslib_list.h"
#include "arielslib_stack.h"
#include "arielslib_merge_sort.h"


using namespace edb1;

int main() {
	List<int> list;
	list.insertAtHead(5);
	int number = list.getData(1);
	cout << number << endl;
	return 0;
}