#ifndef STACK_H
#define STACK_H

template<typename T>
class Stack {
	private:
		T *vector;
		int max;
		int size;
		void arrayInit();

	public:
		Stack(int size);
		~Stack();
		int getSize();
		void push(T c);
		bool pop();
		T top();

};
template<typename T>
int Stack<T>::getSize() {
	return this->size;
}

template<typename T>
void Stack<T>::arrayInit() {
	for (int i = 0; i < max; i++) {
		vector[i] = 0;
	}
}

template<typename T>
Stack<T>::Stack(int max) {
	vector = new T[max];
	this->max = max;
	arrayInit();
	size = 0;
}

template<typename T>
void Stack<T>::push(T element) {
	if (size < max) {
		vector[size] = element;
		size++;
	} else {
		std::cout << "StackOverflow!" << std::endl;
	}
}

template<typename T>
bool Stack<T>::pop() {
	if (size > 0) {
		vector[size--] = 0;
		return true;
	}
	return false;
}

template<typename T>
T Stack<T>::top() {
	return vector[size-1];
}

template<typename T>
Stack<T>::~Stack() {}

#endif