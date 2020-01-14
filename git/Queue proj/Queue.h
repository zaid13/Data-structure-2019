//
// Created by zaid on 10/9/2019.
//
#include "Node.h"
#ifndef UNTITLED6_QUEUE_H
#define UNTITLED6_QUEUE_H


template <class T>
class Queue{
    Node<T> *Front, *Rear;


public:
Queue(){

    Front =  NULL;
    Rear = NULL;
}
Node<T>*  Dequeue(){
if(Front == NULL)
    return 0;

    Node<T>*temp =   Front;

Front = Front->next;
if(Front==NULL){  //LIST IS EMPTY
     Rear = NULL;
}
return temp;
}
void Enqueue(T target){

        if(Rear==NULL){
            Rear = new Node<T>;
            Rear->Data = target;
            Front = Rear;

        }
        else{
         Rear->next = new Node<T>;
            Rear->Data = target;
         Rear = Rear->next;

        }

    }
    void Display(){
Node<T>* temp = Front;

while(temp!=Rear){

    std::cout<<"  "<<(char)temp->Data;
    temp= temp->next;
}

}
void operator-(){
  Dequeue();
}

    void operator+(T right){
        Enqueue(right);
    }
    bool IsEmpty(){
        if(Rear ==NULL && Front==NULL){
            return true;
        }
        return false;

    }
void concatQueue(Queue que){

    this->Rear->next = que.Front;
    this->Rear  =que.Rear;


}
int length(){

    Node<T>* temp = Front;
int count=0;
    while(temp!=Rear){

        std::cout<<"  "<<(char)temp->Data;
        temp= temp->next;
        count++;

    }

    return count ;
}
};
#endif //UNTITLED6_QUEUE_H
