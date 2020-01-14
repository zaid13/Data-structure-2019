//
// Created by zaid on 10/2/2019.
//

#ifndef SINGLY_LINKED_LIST_EMPLOYEEID_H
#define SINGLY_LINKED_LIST_EMPLOYEEID_H
class EmployeeID{

char city;
int year;
int rollno;

public :
    EmployeeID(){

}
    EmployeeID(char c,int y,int r){
    city = c;
     year = y;
    rollno = r;


}
void display(){
    cout<<year<<" - "<<city<<" - "<<rollno;
}
int getrollno(){
    return rollno;

}
};
#endif //SINGLY_LINKED_LIST_EMPLOYEEID_H
