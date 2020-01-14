#pragma once
#include "Node.h"


template <typename T>



class  stacks {
		 
	Node<T>* front;
public:
	stacks() {
		front = NULL;
	}
	void push(T entry) {
		Node<T>* newnode = new Node<T>;
		newnode->data = entry;
		
			newnode->next = front;

		front = newnode;
		std::cout << " pushed";
	}

	T pop() {

		if (!isEmpty() ) {
			Node<T>* newnode = front;
			front = front->next;
			std::cout << " " << newnode->data << "is being deleteed \n";
			T  tt = newnode->data;
			 newnode = NULL;
			 std::cout << " poppped";

			return tt;

		}
	}

	
	T face() {
		if (front != NULL) {
			T  tt = front->data;
			return tt;

		}
	}


	void display() {
		Node<T>* temp= front;


		while (temp != NULL) {
			std::cout << " " << temp->data;
			temp = temp->next;
		}
		std::cout << "\n";
	}
	bool isEmpty() {
		if (front == NULL) {
			std::cout << " is empty" ;

			return true;
		}

		std::cout << " is NOT empty" ;

		return false;
	}
	void clear() {
	
		if (!isEmpty()) {
			Node<T>* temp = front;

			Node<T>* temp1 = temp->next;
			while (temp != NULL) {

				std::cout << " " << temp->data << "  is being deleted ";

				temp1 = temp->next;
				temp = NULL;

				temp = temp1;

			}
			front = NULL;

			std::cout << "  is SUCCESSFULY cleared";
			std::cout << "\n";

		}
	}

};