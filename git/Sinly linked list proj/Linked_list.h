//
// Created by zaid on 9/25/2019.
//
#include "Node.h"
#ifndef UNTITLED3_LINKED_LIST_H
#define UNTITLED3_LINKED_LIST_H

template<typename T>
class Linked_list {
//Node<T>* node ;
    Node<T> *Head;
    int Size;
public:
    Node<T> *getHead() const {
        return Head;
    }

    void setHead(Node<T> *head) {
        Head = head;
    }

    int getSize() const {
        return Size;
    }

    void setSize(int size) {
        Size = size;
    }

public :

    Linked_list(){
        this->Size  = 0;
        this->Head= NULL;
T O;
        Insert_At_End(O);

    }

    void Insert_At_End(T element){


        Node<T>*NewNode = new Node<T>;
        NewNode->setNext(NULL);// =NULL;
        NewNode->setData( element);
        if(Head==NULL){
            this->Head = NewNode;

        }
        else{
            Node<T>* temp   = Head;


            while(temp->next)
            {

            //    std::cout<<temp->data;
                temp=temp->next;

            }
            temp->next = new Node<T>;
            temp->data = element;
            temp->next->next = NULL;





        }


        Size++;




    }

    bool Remove(int roll) {

        if (Head->data.getroll() == roll) {
            Node<T>* temp = Head;


            Head = Head->next;



            delete 	temp;




            return true;
        }

        else {
            Node<T>* temp = this->Head;
            std::cout << " \n remove calledcalled\n";


            while (temp->next != NULL) {

                if (temp->next->data.getroll() == roll) {

                    temp->next = temp->next->next;
                    return true;
                }

                temp = temp->getNext();
            }

        }




    }

    void Display(){
        Node<T>* temp = this->Head;
        std::cout<<" \nDisplay called\n";
        if (Head != NULL && Head->next != NULL) {
            while (temp->next != NULL) {

                std::cout << " \n" ;//<< "*";
                temp->getData().display();
                temp = temp->getNext();
            }


        }

    }

    bool insertInMiddle(int index, T tar) {
        if (this->CheckSize() > index) {

            if (index == 0) {

                Node<T>* OCCO = new Node<T>;
                OCCO->next = Head;

                Head = OCCO;
                Head->data = tar;


                return true;

            }
            else if (index == 1) {

                Node<T>* OCCO = new Node<T>;
                OCCO->next = Head->next;

                Head->next = OCCO;
                OCCO->data = tar;


                return true;

            }
            else {
                //	index -= 5;
                int counter = 1;



                Node<T>* temp = this->Head;
                std::cout << " \\INSER in middle called\n";

                while (temp->next != NULL) {
                    temp = temp->getNext();
                    counter++;
                    if (counter >= index)
                    {
                        break;
                    }

                }
                if (counter >= index) {
                    Node<T>* OCCO = new Node<T>;
                    OCCO->next = temp->next;

                    temp->next = OCCO;
                    OCCO->data = tar;

                    return true;

                }

            }

        }
        else {
            std::cout << "nERROR INVALID INDEX";
            return false;

        }
    }
    bool isEmpty() {
        if (this->Head->next == NULL) {
            return true;
        }



        return  false;

    }

    void clearLis() {


        Node<T>* temp = this->Head;

        Node<T>* toDelete= this->Head;


        while (temp->next != NULL) {
            temp = temp->getNext();

            delete toDelete;
            toDelete = temp;

        }


        this->Size = 0;
        this->Head = NULL;
        T o;
        Insert_At_End(o);

    }
    int CheckSize() {

        int count = 0;
        Node<T>* temp = this->Head;

        while (temp->next != NULL) {
            temp = temp->getNext();
            count++;

        }

        return count ;



    }
    bool ReplaceDataItem(int index, T tar) {
       // std::cout << "yaaaaaaaaaaaaaayayysyd**********************";
        if (this->CheckSize() > index) {


            if (index == 0) {
                Head->data = tar;


                return true;

            }
            else if (index == 1) {

                Head->next->data = tar;


                return true;

            }
            else {
                //	index -= 5;
                int counter = 1;



                Node<T>* temp = this->Head;
                std::cout << " \replace in middle called\n";

                while (temp->next != NULL) {
                    temp = temp->getNext();

                    if (counter >= index)
                    {
                        break;
                    }
                    counter++;
                }
                if (counter >= index) {

                    temp->data = tar;

                    return true;

                }

            }
        }


        else {
            std::cout << "nERROR INVALID INDEX";
            return false;

        }
    }

    Node <T> * getprev(Node <T> * front){

        Node <T> *temp = Head;

        while(temp->next!=NULL){

            if(front==temp->next){

                return temp;
            }

            temp =temp->next;
        }

    }
  void   swap(Node <T> *one,Node <T>* two){
      std::cout<<"\n"<<one->data.getroll()<<"--"<<two->data.getroll()<<"";



if(one!=Head && two!=Head){

    Node <T>* prevtwo = getprev(two);

    Node <T>* prevone = getprev(one);

    prevone->next =two;
    prevtwo->next = one;

    Node <T>* temp = one->next;
    one->next = two->next;
    two->next = temp;

std::cout<<"NOT HEAD\n";


}

else{
    std::cout<<"HEAD\n";
    Node <T>* prevtwo = getprev(two);

    prevtwo->next = one;

    Node <T>* temp = one->next;
    one->next = two->next;
    two->next = temp;
    Head = two;



}
//std::cout<<""<<one->data.getroll()<<"--"<<two->data.getroll()<<"\n";
    }

    int SortList() {

        if(this->Head==NULL)
            return 0;

        Node<T>* temp = Head;
        bool flaggy;
        do {
            flaggy= false;
            while (temp->next!=NULL) {

                if (temp->data.getroll() < temp->next->data.getroll()) {

                    T  toto;

//                    toto = temp->data;  temp;
//                    temp->data = temp->next->data;
//                    temp->next->data = toto;

swap(temp,temp->next);

                    flaggy = true;


                }

                temp = temp->next;

            }
            temp=Head;

        } while (flaggy);

    }


bool duplicate(){



    Node<T>* temp = this->Head;
    Node<T>* temp1 = this->Head;

while (temp1->next) {
    temp = temp1;
    while (temp->next) {

        if (temp->data == temp1->data  && temp!=temp1) {
            std::cout<<temp->data;
            return true;
        }
        temp = temp->getNext();
    }
    temp1 = temp1->next;
}
return false;

    }

Linked_list Split(int tar){

Linked_list Secondlist ;
    Node<T>* temp = Head;
int conta = 0;
        while (temp->next){
            if(conta>tar){
                std::cout<<"\nStarted mkaing new\n";
                Secondlist.Insert_At_End(temp->data);

            } else{


            }

            conta++;
            temp = temp->next;
        }
conta=0;
  temp = Head;
    while (temp->next){

        if(conta>tar){
            std::cout<<"\n MAKING IT NULL \n";
temp->next  = NULL;
            break;
    //  break;
        } else{
        }
        conta++;
        temp = temp->next;
    }
    return Secondlist;
    }

    Node<T>* searchnode(int Tar){
        Node<T> *temp   = Head;

        if (Head != NULL && Head->next != NULL) {
            while (temp->next != NULL) {
        std::cout<<temp->data.getroll()<<":\n";

                if(temp->data.getroll()==Tar)        {
                    return temp;
                }
temp = temp->next;
            }
        }



    }
    bool  removeEmp(EmployeeID id){

       Node<T>* temp =   searchnode(id.getrollno());
        std::cout<<"#######################################";


               temp->getData().display();
               Remove(temp->data.getroll());

        std::cout<<"#######################################";
return 0;
    }

void  updatesallary(int sal, EmployeeID id){
    Node<T> *temp =  searchnode(id.getrollno());

    temp->data.updateSal(sal);

    }

};


#endif //UNTITLED3_LINKED_LIST_H
