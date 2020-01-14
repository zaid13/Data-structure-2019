#pragma once

#include <iostream>
#include <string>

using namespace std;
class OneFlight{
public:
    string departure_city;
    string destination_city;
    string departure_time;
    string departure_date;
    string arival_time;
    string cost_travel;
    string company_name;
    int int_cost_travel;
    void  printer(){
        cout<<"    "<<departure_city<<"  "<< destination_city<<"  "<< departure_date <<"   "<<departure_time<<"   "<<arival_time<<"    "<< cost_travel<<"  "<< company_name<<"\n";
    }
    void  printerdatetime(){
        cout<<"\n"<<departure_city<<"  "<<"  "<< departure_date <<"   "<<departure_time<<"    "<< cost_travel<<"  "<< company_name<<"\n";
    }
    int getintcost(){

        std::cout<<cost_travel;
        if(cost_travel.length()>1)
            return stoi(cost_travel);
        else
            return cost_travel.length();
    }
    int getaArival(){

        cout<< "\n_________________"<<time_separator(departure_date)<<"\n";

    }
    int time_separator(string date)
    {
        int h=2;
        for (int i = 0; i < date.size(); i++)
        {
            if (date[i] == ':') { //HOW HAVE YOU HAVE DIVIDED TIME AS E.G "HOUR : MINUTE : SECOND" OR "08:42:10"
                h = i; //GETS POSITION OF HOUR
                date.erase(date.begin() + i);
            }
        }

        //GETS HOUR = STARTS FROM 0 AND GETS "h" CHARACTERS
        string str1 = date.substr(0, h);

        //GETS MINUTE = STARTS FROM "h" AND GETS 2 CHARACTERS
        string str2 = date.substr(h, 2);

        //Converting string to int
        int hour = stoi(str1);
        int minute = stoi(str2);

        //CALCULATES SECONDS
        int seconds = (hour * 60 * 60) + (minute * 60);

        return seconds;
    }
    int date_separator(string date)
    {
        for (int i = 0; i < date.size(); i++)
        {
            if (date[i] == '/' || date[i] == ':') { //HOW HAVE YOU HAVE DIVIDED DATE AS E.G "4/02/2019"
                date.erase(date.begin() + i);
            }
        }

        //GETS DATE = STARTS FROM 0 AND GETS 1 CHARACTERS
        string str1 = date.substr(0, 1);

        //GETS MONTH = STARTS FROM 1 AND GETS 2 CHARACTERS
        string str2 = date.substr(1, 2);

        //GETS YEAR = STARTS FROM 3 AND GETS 4 CHARACTERS
        string str3 = date.substr(3, 4);

        //Converting string to int
        int day = stoi(str1);
        int month = stoi(str2);
        int year = stoi(str3);

        //CALCULATES SECONDS
        int seconds = (day * 24 * 60 * 60) + (month * 30 * 24 * 60 * 60) ;//(year * 12 * 30 *24 * 60 * 60);

        return seconds;
    }

    //CONVERT TIME IN SECONDS
    int Departure_Time_In_Seconds() {


        int seconds_T =  time_separator(departure_time);
        int seconds_D  = date_separator(departure_date);
        int Total_Seconds;
        Total_Seconds = seconds_D + seconds_T;

        return Total_Seconds;
    }

    int Arival_Time_In_Seconds() {


        int seconds_T =  time_separator(arival_time);
        int seconds_D  = date_separator(departure_date);
        int Total_Seconds ;
        Total_Seconds = seconds_D + seconds_T;

        return Total_Seconds;
    }

	//CHECKS HOTEL STAY PER DAY DURING TRANSACTION
	bool HotelStay_Day() {

		string arival_hour = arival_time;
		string departure_hour = arival_time;
		int ah = -1;
		int dh = -1;

		for (int i = 0; i < arival_hour.size(); i++)
		{
			if (arival_hour[i] == ':') { //HOW HAVE YOU HAVE DIVIDED TIME AS E.G "HOUR : MINUTE : SECOND" OR "08:42:10"
				ah = i; //GETS POSITION OF HOUR
				arival_hour.erase(arival_hour.begin() + i);
			}
		}

		for (int i = 0; i < departure_hour.size(); i++)
		{
			if (departure_hour[i] == ':') { //HOW HAVE YOU HAVE DIVIDED TIME AS E.G "HOUR : MINUTE : SECOND" OR "08:42:10"
				dh = i; //GETS POSITION OF HOUR
				departure_hour.erase(departure_hour.begin() + i);
			}
		}

		//GETS HOUR = STARTS FROM 0 AND GETS "ah" CHARACTERS
		string str1 = arival_hour.substr(0, ah);

		//GETS HOUR = STARTS FROM 0 AND GETS "dh" CHARACTERS
		string str2 = departure_hour.substr(0, dh);

		//Converting string to int
		int ar = stoi(str1);
		int de = stoi(str2);

		if (ar < de) {
			//cout << "Next day is being occupied" << endl;
			return true;
		}
		return false;
	}

};
