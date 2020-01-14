#pragma once
#include <iostream>
#include <fstream>
#include <string>

#include "SpecificFlight.h"
using namespace std;

class Flights {
public:
    string departure_city[300];
    string destination_city[300];
    string departure_time[300];
    string departure_date[300];
    string arival_time[300];
    string cost_travel[300];
    string company_name[300];

    string city_arr[100];
    string city_arr_prices[100];
    int no_ofhotelcharges = 0;
    int no_city = 0;
    int  Flight_ctr = 0;
    Flights() {

        string data;


        // read_hotel_charges(city_arr,city_arr_prices);  SSHUJAH IMPLEMENT THIS


        ifstream infile;
        infile.open("HotelCharges_perday.txt");
        //  cout << "Reading from the file" << endl;
        while (!infile.eof()) {
            infile >> data;
            if (no_ofhotelcharges % 2 == 0) {
                city_arr[no_city++] = data;
            }
            else {
                city_arr_prices[no_city - 1] = data;
            }
            no_ofhotelcharges++;
        }
        infile.close();

        // PASS THESE BY REFENCE
        // write the data at the screen.
        for (int i = 0; i < no_city; i++) {

            //     cout<<"city  = "<<city_arr[i]<<" price  ="<<city_arr_prices[i]<<'\n';


        }





        //!! PASS THESE BY REFERENCE
        // read_hotel_charges(departure_city,destination_city,departure_time,departure_date,arival_time,cost_travel,company_name,Flight_ctr);  SSHUJAH IMPLEMENT THIS





        string g;

        infile.open("Flights.txt");
        //    cout << "Reading from the file" << endl;
        while (!infile.eof()) {
            int i = Flight_ctr;
            infile >> departure_city[Flight_ctr] >> destination_city[Flight_ctr] >> departure_date[Flight_ctr] >> departure_time[Flight_ctr] >> arival_time[Flight_ctr] >> cost_travel[Flight_ctr] >> company_name[Flight_ctr];
            Flight_ctr++;
        }
        infile.close();


        for (int i = 0; i < Flight_ctr; i++) {
            //        cout<<"\n "<<company_name[i]<<" = "<<destination_city[i]<<"  = "<<departure_time[i];
            //        cout<<"  "<<departure_date[i]<<"   ="<<arival_time[i]<<"  = "<<cost_travel[i];
            //        cout<<"  "<<departure_city[i]<<'\n';
        }




    }
    bool  flightexistinit(string str2, string str1, OneFlight* onf, int& ctr) {

        ctr = 0;
        for (int i = 0; i < Flight_ctr; i++) {
            if (str1.compare(destination_city[i]) == 0 && str2.compare(departure_city[i]) == 0) {

                onf[ctr].departure_date = departure_date[i];
                onf[ctr].arival_time = arival_time[i];
                onf[ctr].departure_time = departure_time[i];
                onf[ctr].destination_city = destination_city[i];
                onf[ctr].company_name = company_name[i];
                onf[ctr].departure_city = departure_city[i];
                onf[ctr].cost_travel = cost_travel[i];
                ctr++;
            }

        }

        if (ctr > 0)return true;

        return false;
    }
    void  flightexist(string str1, string str2, OneFlight* onf, int& ret) {
        ret = 0;
        for (int i = 0; i < Flight_ctr; i++) {
            if (str2.compare(destination_city[i]) == 0 && str1.compare(departure_city[i]) == 0) {
                onf[ret].departure_date = departure_date[i];
                onf[ret].arival_time = arival_time[i];
                onf[ret].departure_time = departure_time[i];
                onf[ret].destination_city = destination_city[i];
                onf[ret].company_name = company_name[i];
                onf[ret].departure_city = departure_city[i];
                onf[ret].cost_travel = cost_travel[i];

                ret++;
                //     return true;
            }
        }
        // return false;
    }

    //CONVERT TIME IN SECONDS
    int* Time_In_Seconds() {
        int* seconds_T = new int [Flight_ctr];
        int* seconds_D = new int [Flight_ctr];
        int* Total_Seconds = new int [Flight_ctr];
        for (int i = 0; i < Flight_ctr; i++) {
            seconds_T[i] = time_separator(departure_time[i]);
            seconds_D[i] = date_separtor(departure_date[i]);
            Total_Seconds[i] = seconds_D[i] + seconds_T[i];
        }
        return Total_Seconds;
    }

    int getaArival(){
      cout<< "\n_________________"<<time_separator(departure_date)<<"\n";

    }
    int time_separator(string date)
    {
        for (int i = 0; i < date.size(); i++)
        {
            if (date[i] == ':' || date[i] == '/') { //HOW HAVE YOU HAVE DIVIDED TIME AS E.G "HOUR : MINUTE : SECOND" OR "08:42:10"
                date.erase(date.begin() + i);
            }
        }

        //GETS HOUR = STARTS FROM 0 AND GETS 2 CHARACTERS
        string str1 = date.substr(0, 2);

        //GETS MINUTE = STARTS FROM 2 AND GETS 2 CHARACTERS
        string str2 = date.substr(2, 2);

        //GETS SECOND = STARTS FROM 4 AND GETS 4 CHARACTERS
        string str3 = date.substr(4, 4);

        //Converting string to int
        int hour = stoi(str1);
        int minute = stoi(str2);
        int sec = stoi(str3);

        //CALCULATES SECONDS
        int seconds = (hour * 60 * 60) + (minute * 60) + sec;

        return seconds;
    }

    int date_separtor(string date)
    {
        for (int i = 0; i < date.size(); i++)
        {
            if (date[i] == '/' || date[i] == ':') { //HOW HAVE YOU HAVE DIVIDED DATE AS E.G "24/02/2019"
                date.erase(date.begin() + i);
            }
        }

        //GETS DATE = STARTS FROM 0 AND GETS 2 CHARACTERS
        string str1 = date.substr(0, 2);

        //GETS MONTH = STARTS FROM 2 AND GETS 2 CHARACTERS
        string str2 = date.substr(2, 2);

        //GETS YEAR = STARTS FROM 4 AND GETS 4 CHARACTERS
        string str3 = date.substr(4, 4);

        //Converting string to int
        int day = stoi(str1);
        int month = stoi(str2);
        int year = stoi(str3);

        //CALCULATES SECONDS
        int seconds = (day * 24 * 60 * 60) + (month * 30 * 24 * 60 * 60) + (year * 12 * 30 *24 * 60 * 60);

        return seconds;
    }
};
