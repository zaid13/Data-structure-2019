//
// Created by zaid on 10/2/2019.
//

#ifndef SINGLY_LINKED_LIST_DATE_H
#define SINGLY_LINKED_LIST_DATE_H


class Date {
    int day;
    int month;
    int year;
public :
    Date(){


}
    Date(int d,int m ,int y){
    day = d;
    year =y;
    month = m;

}
void display(){
    cout<<"|  "<<day<<"- "<<month<<"- "<<year;

}
};


#endif //SINGLY_LINKED_LIST_DATE_H
