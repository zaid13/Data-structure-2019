#pragma once

#include "SpecificFlight.h"
#include "Flights.h"

template<class T>
class Node_Graph{

public:
    int data;
    OneFlight *flightDetails;
	OneFlight* flightDetails_for_time;

    OneFlight CurrentFlight;
    Node_Graph<T> * next;
    int NoofNeighbour;
    int TotalFlights;
    int *ko;
Node_Graph(){

    TotalFlights=-9;
    //flightDetails=NULL;
}

   void sort_flightCost(){

       for(int i=0 ; i< TotalFlights ; i++)
       {
           for(int j=0 ; j< TotalFlights ; j++)
           {
				if(flightDetails[i].cost_travel  >  flightDetails[j].cost_travel && i<j ){
					swap(flightDetails[i],flightDetails[j]);

				}
           }
       }
   }

   void sort_flight_time() {

	   flightDetails_for_time = new OneFlight[TotalFlights];

	   for (int i = 0; i < TotalFlights; i++) {
		   flightDetails_for_time[i] = flightDetails[i];
	   }
	   for (int i = 0; i < TotalFlights; i++)
	   {
		   for (int j = 0; j < TotalFlights; j++)
		   {
			   if (flightDetails_for_time[i].Departure_Time_In_Seconds() > flightDetails_for_time[j].Departure_Time_In_Seconds() && i < j) {
				   swap(flightDetails_for_time[i], flightDetails_for_time[j]);

			   }

		   }

	   }

   }

   void setFlightDetails(OneFlight *FD   , int N) {
		NoofNeighbour = N;
		flightDetails =  new OneFlight[N] ;

		for(int i=0 ; i< N ; i++){
			flightDetails[i] = FD[i];
		}
	}

   void print(){

       cout<<"\n"<<data<<"  "<<NoofNeighbour<<"  "<<TotalFlights;
        for(int i=0 ; i< TotalFlights ; i++)
        {
       cout<<"+";
       flightDetails[i].printer();
       cout<<"+";

        }
        cout<<"\n";
	}

	bool isAfter(int num, int* ptr, Node_Graph* fl, string str2, int son, int time_in_hours, bool& found_that, int& cost, OneFlight* flight, string str) {
		while (fl->flightDetails->destination_city.compare(str) != 0 && fl->flightDetails->departure_city.compare(str2) != 0) {

			cout << "\n" << fl->flightDetails->destination_city << "          " << str2;
			fl = fl->next;
		}

		if (!fl)
		{
			cout << "############################################      fl is blank returning \n\n";
			return false;
		}
		else {
			cout << "############################################      fl is FILLED  \n\n";
		}
		for (int i = 0; i < TotalFlights; i++) {
			cout << "__#__" << ptr[num] << "     " << fl->flightDetails[i].Departure_Time_In_Seconds() << "   " << fl->flightDetails[i].departure_date << "  " << fl->flightDetails[i].departure_time << "\n";

			if (ptr[num] < fl->flightDetails[i].Departure_Time_In_Seconds()) {
				cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ parent found  \n\n";

				ptr[son] = fl->flightDetails[i].Arival_Time_In_Seconds();
				cost = fl->flightDetails[i].getintcost();
				flight[son] = fl->flightDetails[i];
				cout << "\n" << ptr[num] << "  " << time_in_hours * 60 * 60 << "    " << fl->flightDetails[i].Departure_Time_In_Seconds() << "   \n";
				fl->print();
				if (ptr[num] * time_in_hours * 60 * 60 <= fl->flightDetails[i].Departure_Time_In_Seconds()) {
					cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&    found it \n\n";
					found_that = true;
				}
				return true;

			}

		}
		return false;

	}

	bool isAftersen2(int num, int* ptr, Node_Graph* fl, int son, int& cost, OneFlight* flight, string str) {

		while (fl->flightDetails_for_time->destination_city.compare(str) != 0) {
			cout << "\n" << fl->flightDetails_for_time->destination_city << "     " << str;
			fl = fl->next;
		}

		if (!fl)
		{
			cout << "############################################      fl is blank returning \n\n";
			return false;
		}
		else
			cout << "############################################      fl is FILLED  \n\n";

		for (int i = 0; i < TotalFlights; i++) {
			cout << "__#__" << ptr[num] << "     " << fl->flightDetails_for_time[i].Departure_Time_In_Seconds() << "   " << fl->flightDetails_for_time[i].departure_date << "  " << fl->flightDetails_for_time[i].departure_time << "\n";

			if (ptr[num] < fl->flightDetails_for_time[i].Departure_Time_In_Seconds()) {
				cout << num << "   " << son << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ parent found  \n\n";
				cost = fl->flightDetails_for_time[i].getintcost();
				fl->flightDetails_for_time[i].printer();
				flight[son] = fl->flightDetails_for_time[i];
				ptr[son] = fl->flightDetails_for_time[i].Arival_Time_In_Seconds();
				return true;
			}
		}
		return false;
	}

	bool isAfter(int num, int* ptr, Node_Graph* fl, int son, int& cost, OneFlight* flight, string str) {

		while (fl->flightDetails->destination_city.compare(str) != 0) {
			cout << "\n" << fl->flightDetails->destination_city << "     " << str;
			fl = fl->next;
		}

		if (!fl)
		{
			cout << "############################################      fl is blank returning \n\n";
			return false;
		}
		else
			cout << "############################################      fl is FILLED  \n\n";

		for (int i = 0; i < TotalFlights; i++) {
			cout << "__#__" << ptr[num] << "     " << fl->flightDetails[i].Departure_Time_In_Seconds() << "   " << fl->flightDetails[i].departure_date << "  " << fl->flightDetails[i].departure_time << "\n";

			if (ptr[num] < fl->flightDetails[i].Departure_Time_In_Seconds()) {
				cout << num << "   " << son << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ parent found  \n\n";
				cost = fl->flightDetails[i].getintcost();
				fl->flightDetails[i].printer();
				//ADD COST OF EACH DAY ON HOTEL
				
				Flight317(num, ptr, fl, cost, str,i);

				// if (fl->flightDetails[i].HotelStay_Day() == true) {
				// 	 cost += fl->flightDetails->getintcost();
				// }

				flight[son] = fl->flightDetails[i];
				ptr[son] = fl->flightDetails[i].Arival_Time_In_Seconds();

				return true;

			}

		}
		return false;

	}
 
	void Flight317(int num, int* ptr, Node_Graph* fl, int& cost, string str, int ind){
		Flights *fly = new Flights;
		string st;
		int price;
		if ((ptr[num] + 43200) < fl->flightDetails[ind].Departure_Time_In_Seconds()) {
			for (int j = 0; j < 400; j++) {
				st = fly->city_arr[j];
				if (str.compare(st) == 0) {
					price = stoi(fly->city_arr_prices[j]);
					cost += price;
				}
			}
		}
	}

    void setCurrentFlight(OneFlight of){

        this->CurrentFlight.departure_city  =  of.departure_city;
        this->CurrentFlight.destination_city =  of.destination_city ;
        this->CurrentFlight.departure_time   = of.departure_time;
        this->CurrentFlight.departure_date  = of.departure_date ;
        this->CurrentFlight.arival_time =  of.arival_time;
        this->CurrentFlight.cost_travel  =  of.cost_travel;
        this->CurrentFlight.company_name  =  of.company_name;

    }






};