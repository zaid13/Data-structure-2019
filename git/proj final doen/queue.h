#pragma once

#include "Nodequeue.h"
template <class T>
class Queue{
    Nodequeue<T> *Front, *Rear;
int ctr;

public:
    Queue(){
ctr=0;
        Front =  NULL;
        Rear = NULL;
        Enqueue(0);
    }
    T Dequeue(){

        if(ctr <= 0)
            return 0;

       T temp =   Front->Data;

        Front = Front->next;
        if(Front==NULL){  //LIST IS EMPTY
            Rear = NULL;
        }
        ctr--;
        return temp;
    }
    void Enqueue(T target){

        if(Rear==NULL){
            Rear = new Nodequeue<T>;
            Rear->Data = target;
            Front = Rear;

        }
        else{
            Rear->next = new Nodequeue<T>;
            Rear->Data = target;
            Rear = Rear->next;
            ctr++;
        }

    }
    void Display(){
        Nodequeue<T>* temp = Front;

        while(temp!=Rear){

     //       std::cout<<"  "<<temp->Data;
            temp= temp->next;
        }
     //   std::cout<<"  \n";

    }
    void operator-(){
        Dequeue();
    }

    void operator+(T right){
        Enqueue(right);
    }
    bool IsEmpty(){
        if(ctr==0)
            return true;
    //    return false;
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

        Nodequeue<T>* temp = Front;
        int count=0;
        while(temp!=Rear){

            std::cout<<"  "<<(char)temp->Data;
            temp= temp->next;
            count++;

        }

        return count ;
    }
};