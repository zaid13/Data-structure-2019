#pragma once
#include <iostream>
using namespace std;

bool exists(string*list,string str,int len ){
    for(int i=0 ; i<len ;i++)
    {
    //    std::cout<<"\n"<<list[i]<<str<<" "<<list[i].length()<<str.length()<<"\n";
        if(str.compare(list[i])==0){/*std::cout<<"\n"<<list[i]<<str<<"\n";*/
            return true;}

    }
    return false;
}
bool append(string *list,string str,int len ){

    list[len] = str;
    return true;
}

string* extractFlights(string *str2 ,string *str, int nu,int &noOfvert){
int ctr=0;
    string  * newstr = new string[100];
    for(int i=0 ; i< nu  ; i++){
    if(!exists(newstr,str[i],ctr)){
     if(append(newstr,str[i],ctr)){/*std::cout<<"entered"<<str[i]<<"\n";*/}
        ctr++;
    }

}
//    string  * newstr = new string[100];
    for(int i=0 ; i< nu  ; i++){
        if(!exists(newstr,str2[i],ctr)){
            if(append(newstr,str2[i],ctr)){/*std::cout<<"entered"<<str[i]<<"\n";*/}
            ctr++;
        }

    }

    noOfvert = ctr;
    return newstr;
}