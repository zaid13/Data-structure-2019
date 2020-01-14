//
// Created by zaid on 10/2/2019.
//

#ifndef SINGLY_LINKED_LIST_EMPLOYEE_H
#define SINGLY_LINKED_LIST_EMPLOYEE_H

#include "iostream"
using namespace std;
#include "EmployeeID.h"
#include "Date.h"
#include "string"
class Employee{

    string Nic;
    int salary;
    int Bonus;
    Date date;
    EmployeeID Id;

public:
    Employee(){}
    Employee (string cnic,int sal ,int bonus ,Date dat,EmployeeID id){

        Nic = cnic;
        Bonus = bonus;
        date = dat;
        Id = id;
        salary = sal;



    }
   void display(){
        cout<<Nic<<" |  "<<Bonus<<" |";
        date.display();
        cout<<" | ";
        Id.display();
        cout<<" | "<<salary;


    }
int getroll(){

    return Id.getrollno();
    }
    bool updateSal(int sal){

        salary = sal;
        return true;
    }
};
#endif //SINGLY_LINKED_LIST_EMPLOYEE_H
e