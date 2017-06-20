#ifndef ARIELSLIB_LIST_H
#define ARIELSLIB_LIST_H

template<typename T>
class List {
	struct Node {
	T data;
	Node *next;
	Node *previous;
	};
	private:
		int size;
		Node *head;
		Node *tail;
		void connect(Node<T> *inserted, Node<T> *sentry) {
			inserted->previous = sentry->previous;
			sentry->previous->next = inserted;
			inserted->next = sentry;
			sentry->previous = inserted;
		}
	public:
		void insertAt(int index, T data) {
			if (index > amount || index < 0) {
				std::cout << "Impossível inserir. Posição fora da lista" << std::endl;
			return;
			}

			Node<T> *inserted = new Node<T> {data, nullptr, nullptr};
			Node<T> *sentry;

			if (index > amount/2) {
				sentry = tail->previous;
				for (int count = amount; count > index; count--) {
				sentry = sentry->previous;
				}
			} else {
				sentry = head->next;
				for (int count = 0; count < index; count++) {
					sentry = sentry->next;
				}
			}
			connect(inserted, sentry);
			amount++;

		}
};

#endif