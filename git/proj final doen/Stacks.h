#pragma once

#include "Stacknode.h"
template<class T>

class  stacks {

    StackNode<T>* front;
public:
    stacks() {
        front = NULL;
    }
    void push(T entry) {
        StackNode<T>* newnode = new StackNode<T>;
        newnode->data = entry;

        newnode->next = front;

        front = newnode;
      //  std::cout << " pushed";
    }

    T pop() {
        StackNode<T>* newnode = NULL;
        if (!isEmpty() ) {
          newnode = front;
            front = front->next;
      //      std::cout << " " << newnode->data << "is being deleteed \n";
            T  tt = newnode->data;
            newnode = NULL;
     //       std::cout << " poppped";

            return tt;

        }
        return -3;
    }


    T face() {
        if (front != NULL) {
            T  tt = front->data;
            return tt;

        }
    }


    void display() {
        StackNode<T>* temp= front;


        while (temp != NULL) {
            std::cout << " " << temp->data;
            temp = temp->next;
        }
        std::cout << "\n";
    }
    bool isEmpty() {
        if (front == NULL) {
      //      std::cout << " is empty" ;

            return true;
        }

     //   std::cout << " is NOT empty" ;

        return false;
    }
    void clear() {

        if (!isEmpty()) {
            StackNode<T>* temp = front;

            StackNode<T>* temp1 = temp->next;
            while (temp != NULL) {

                std::cout << " " << temp->data << "  is being deleted ";

                temp1 = temp->next;
                temp = NULL;

                temp = temp1;

            }
            front = NULL;

     //       std::cout << "  is SUCCESSFULY cleared";
            std::cout << "\n";

        }
    }

};
