//
// Created by zaid on 12/5/2019.
//

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

    string city_arr[900];
    string city_arr_prices[900];
    int no_ofhotelcharges;
	int no_city;
    int  Flight_ctr;

    Flights() {

        string data;

		no_ofhotelcharges = 0;
		no_city = 0;
		Flight_ctr = 0;

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
//                     return true;
            }
        }
//         return false;
    }



};