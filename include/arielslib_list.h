#ifndef ARIELSLIB_LIST_H
#define ARIELSLIB_LIST_H

#include <iostream>
using std::cout;
using std::endl;

namespace edb1 {
	template<typename T>
	class List {
		private:
			struct Node {
				T data;
				Node *next;
				Node *previous;
			};
			int size;
			typename List<T>::Node *head;
			typename List<T>::Node *tail;
			void connect(typename List<T>::Node *inserted, typename List<T>::Node *sentry) {
				inserted->previous = sentry->previous;
				sentry->previous->next = inserted;
				inserted->next = sentry;
				sentry->previous = inserted;
			}
			void findNode(int index, typename List<T>::Node *&sentry) {
				if (index > size/2) {
					sentry = tail->previous;
					for (int count = size; count > index; count--) {
					sentry = sentry->previous;
					}
				} else {
					sentry = head->next;
					for (int count = 0; count < index; count++) {
						sentry = sentry->next;
					}
				}

			}
		public:
			List() {
				size = 0;
				head = new typename List<T>::Node;
				tail = new typename List<T>::Node;

				head->next = tail;
				tail->previous = head;
			}
		
			~List() {
				deleteList();
			}

			void insertAtHead(T data) {
				typename List<T>::Node *inserted = new typename List<T>::Node();
				inserted->data = data;
				inserted->next = NULL;
				inserted->previous = NULL;
				typename List<T>::Node *h = this->head;

				h->next->previous = inserted;
				inserted->next = h->next;

				h->next = inserted;
				inserted->previous = h;

				this->size++;
			}
		
			void insertAtTail(T data) {
				typename List<T>::Node *inserted = new typename List<T>::Node();
				inserted->data = data;
				inserted->next = NULL;
				inserted->previous = NULL;
				typename List<T>::Node *t = this->tail;

				t->previous->next = inserted;
				inserted->previous = t->previous;

				t->previous = inserted;
				inserted->next = t;

				this->size++;
			}

			void insertAt(int index, T data) {
				if (index > size || index < 0) {
					std::cout << "Impossível inserir. Posição fora da lista" << std::endl;
				return;
				}

				typename List<T>::Node *inserted = new typename List<T>::Node();
				inserted->data = data;
				inserted->next = NULL;
				inserted->previous = NULL;
				typename List<T>::Node *sentry;

				findNode(index, sentry);
				connect(inserted, sentry);
				size++;
			}

			void removeAtHead() {
				if (head->next == tail) {
					cout << "Lista vazia!" << endl;
					return;
				}
				typename List<T>::Node *tmp = head->next;
				head->next = tmp->next;
				tmp->next->previous = head;
				delete tmp;
			}

			void removeAtTail() {
				if (tail->previous == head) {
					cout << "Lista vazia!" << endl;
					return;
				}
				typename List<T>::Node *tmp = tail->previous;
				tail->previous = tmp->previous;
				tmp->previous->next = tail;
				delete tmp;
			}

			void removeAt(int index) {
				if (index > size || index < 0) {
					std::cout << "Impossível remover. Posição fora da lista" << std::endl;
				return;
				}

				typename List<T>::Node *sentry;

				findNode(index, sentry);
				typename List<T>::Node *tmp = sentry->next;
				tmp->previous = sentry->previous;
				tmp->previous->next = tmp;
				delete sentry;
			}

			T getData(int index) {
				typename List<T>::Node *sentry;
				if (index <= size && index > 0) {
					findNode(index, sentry);
				} else {
					std::cout << "Impossível encontrar elemento. Posição fora da lista" << std::endl;
				}
				return sentry->data;
			}

			void deleteList() {
				typename List<T>::Node *sentry = head->next;
				while ((sentry = sentry->next)) {
					delete sentry->previous;
				}
				delete head;
				delete tail;
			}

			void printList() {
				typename List<T>::Node *runner = head;
				while((runner = runner->next)) {
					std::cout << runner->data << std::endl;
				}
			}
	};

}


#endif