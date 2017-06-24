#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <cstdlib>

#include "arielslib_list.h"
#include "arielslib_stack.h"
#include "arielslib_queue.h"
#include "arielslib_merge_sort.h"
#include "arielslib_quick_sort.h"
#include "arielslib_binary_search.h"

using namespace edb1;

#define MAX 50

float randomizeFloat(float max) {
    float randomN;
        randomN = ((float)rand()/(float)(RAND_MAX) * max);
    return randomN;
}

int randomizeInt() {
    int randomN;
    do {
        randomN = rand() % MAX;
    } while (randomN == 0);
    return randomN;
}

float* vectorSorter(int k) {
	srand(time(NULL));
	float *v = new float[k];
	for (int i = 0; i < k; i++) {
		v[i] = randomizeFloat(MAX);
	}
	return v;
}

template <typename T>
void printVector(T *v, int n) {
	for (int i = 0; i < n; i++) {
		std::cout << (int)v[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	
	//testa merge_sort
	int k = randomizeInt();
	float *v = vectorSorter(k);
	std::cout << "Vetor desordenado" << std::endl;
	printVector<float>(v, k);
	std::cout << std::endl;
	mergeSort<float>(v, k);
	std::cout << "Vetor ordenado" << std::endl;
	printVector<float>(v, k);
	std::cout << std::endl;
	
	//testa binary_search
	std::cout << "Testando binary search" << std::endl;
	for (int i = 0; i < 5; i++) {
		if (binarySearch<float>(v, v[i], k)) {
			std::cout << "Elemento " << v[i] << " " << "encontrado." << std::endl;
		} else {
			std::cout << "Elemento " << v[i] << " " << "não encontrado." << std::endl;
		}	
	}
	
	List<int> l;
	Stack<int> s(20);
	s.push(5);
	std::cout << s.top() << std::endl;

	MyQueue<string> q(5);
	q.pushBack("brasileirinho");
	cout << q.front() << endl;

	return 0;
}