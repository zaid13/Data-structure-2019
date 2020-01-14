// linked list practise.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "iostream"
#include "cstdlib"
#include "string"
#include <fstream>
#include "time.h"
#include <windows.h>
#include <stdio.h>
using namespace std;


	  template <class T>
class Node {
public:
	T data;
	Node* next;

};
template <class T>

class Linked_list {
public:
	Node<T>* head;

	Linked_list() {
		head = NULL;
	}

	void insert_at_end(T a) {
		Node<T>* newnode = new Node<T>;
		newnode->data = a;
		newnode->next = NULL;

		if (head == NULL) {
			head = newnode;
		///	std::cout << "\n head is null\n";
		}

		else {
			Node<T>* temp = head;
			while (temp->next)
			{

				temp = temp->next;

			}

			temp->next = newnode;

		}

	}
	void display() {
		Node<T>* temp = head;

		while (temp)
		{
			std::cout << temp->data<<'-';
			temp = temp->next;
		}


	}

	void reverse_list() {
	
		Node<T>* temp = head;

		Node<T>* ptrofnext =NULL;// = temp->next;
		Node<T>* currpttr = NULL;


		while (temp)
		{

			ptrofnext = temp->next;


				temp->next = currpttr;

			

			currpttr = temp;
			

		//	std::cout << "\n" << temp->data << "\n";


			temp = ptrofnext;

		}
		head = currpttr;


	}						
int getindex(T t,Node<T>* head,T yoyo=0) {
	
	if (t == head->data) {
		return yoyo;
	}
	if (head->next)
		getindex(t, head->next,yoyo+1);
	else
	{
		return -1;
	}
	}
void function(int x,int y ) {

	Node<T>* temp = head;

	int keeper = 1;
	while (temp)
	{
		Node* tot = temp->next;
		if (keeper >= x) {
			int inner = 0;
			while (inner < y) {
				if (tot != NULL)
					tot = tot->next;

				inner++;
			}

			keeper = 0;
			temp->next = tot;
		}
		keeper++;							  

	//	std::cout << temp->data;
		temp = tot;
		
	}

}
BOOL Exists(T samp) {

	Node<T>* temp = head;

	while (temp)
	{
		if (temp->data == samp) {
			return true;
		}
		temp = temp->next;
	}
	return false;

}
void explode_head() {

	Node<T>* temp = head;
	head = head->next;
	delete (temp);
}

void reinit() {
	Node<T>* temp = head;

	while (temp)
	{
		temp->data = '*';
		temp = temp->next;
	}

	std::cout << endl;
	std::cout << endl;
	std::cout << endl;
	std::cout << endl;
	std::cout << endl;
	std::cout << endl;

	std::cout << endl;
	std::cout << endl;
	std::cout << endl;
	std::cout << endl;
	std::cout << endl;
	std::cout << endl;

	std::cout << "										REINITIALIZING									";


	Sleep(200); // Sleep three seconds

}

};


int getsum(int x) {

	if (x % 10 > 0) {
		
	return x%10   +	getsum(x / 10);
		
	}

}
void pix(char t ) {

	std::cout << t;
}

void space() {

	std::cout << "\n";

	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
}
void wait() {
	
	space();
	Sleep(200); // Sleep three seconds
	system("CLS");
	space();


}
void disp(char t ,char miss) {
	cout << " ";
	pix(t);
	std::cout << endl;
	pix(t);
	cout << "  ";
	pix(t);

	std::cout << endl << "  ";
	pix(t);


	wait();
	cout << "   ";
	pix(miss);
	std::cout << endl;
	cout << " ";
	pix(miss);
	cout << "   ";
	pix(miss);

	std::cout << endl;
	pix(miss);
	cout << "     ";
	pix(miss);
	std::cout << endl;
	cout << " ";
	pix(miss);
	cout << "   ";
	pix(miss);

	std::cout << endl << "   ";
	pix(miss);



	while (true) {


		wait();
		cout << "   ";
		pix(t);
		std::cout << endl;
		cout << " ";
		pix(miss);
		cout << "   ";
		pix(miss);

		std::cout << endl;
		pix(miss);
		cout << "     ";
		pix(miss);
		std::cout << endl;
		cout << " ";
		pix(miss);
		cout << "   ";
		pix(miss);

		std::cout << endl << "   ";
		pix(miss);



		wait();



		wait();
		cout << "   ";
		pix(t);
		std::cout << endl;
		cout << " ";
		pix(miss);
		cout << "   ";
		pix(miss);

		std::cout << endl;
		pix(miss);
		cout << "     ";
		pix(miss);
		std::cout << endl;
		cout << " ";
		pix(miss);
		cout << "   ";
		pix(miss);

		std::cout << endl << "   ";
		pix(miss);



		wait();




		wait();
		cout << "   ";
		pix(t);
		std::cout << endl;
		cout << " ";
		pix(miss);
		cout << "   ";
		pix(miss);

		std::cout << endl;
		pix(miss);
		cout << "     ";
		pix(miss);
		std::cout << endl;
		cout << " ";
		pix(miss);
		cout << "   ";
		pix(miss);

		std::cout << endl << "   ";
		pix(miss);





		wait();




		wait();
		cout << "   ";
		pix(t);
		std::cout << endl;
		cout << " ";
		pix(miss);
		cout << "   ";
		pix(miss);

		std::cout << endl;
		pix(miss);
		cout << "     ";
		pix(miss);
		std::cout << endl;
		cout << " ";
		pix(miss);
		cout << "   ";
		pix(miss);

		std::cout << endl << "   ";
		pix(miss);



		wait();




	}

}
int main()
{
//	std::cout << "\n"<<getsum(6)<<"\n";
	//std::cout << "Hello World!\n";

//	Linked_list <char>list;
//	list.insert_at_end('A');
//	list.display();

	//list.display();
	std::cout << "\n";

	//std::cout << "\n" << list.getindex(8,list.head) << "\n";
	
	while (false) {

//		list.display();
	//	list.reverse_list();
		cout << "\n";
		cout << "\n";
		printf("starting to sleep...\n");
		Sleep(200); // Sleep three seconds
		srand(time(0));
		char y = rand() % 26+65;
	

		int count = 0;
	//	while (list.Exists(y)) {
			 y = rand() % 26 + 65;
			cout << y<<"searching...";
			system("CLS");
			count++;
			if (count > 20)
			{
				count = 0;
			//	list.reinit();
			}

		//}

//		list.insert_at_end(y);
//		list.explode_head();
		cout << endl;

	//	system("CLS");
//		Sleep(200); // Sleep three seconds





	}


	disp('*',' ');


	cout << "   ";
	pix('*');
	std::cout << endl;
	cout << " ";
	pix('*');
	cout << "   ";
	pix('*');

	std::cout << endl;
	pix('*');
	cout << "     ";
	pix('*');
	std::cout << endl;
	cout << " ";
	pix('*');
	cout << "   ";
	pix('*');

	std::cout << endl << "   ";
	pix('*');





}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Shttps://www.onlinegdb.com/online_c++_compiler#tab-stdintart Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Outputhttps://www.onlinegdb.com/online_c++_compiler#tab-stdin window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
