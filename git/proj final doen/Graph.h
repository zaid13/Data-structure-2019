#pragma once
#include "Graph_node.h"
#include "Graph_list.h"
#include "queue.h"
#include "Stacks.h"
#include "Flights.h"
#include "Functions_for_graph.h"
#include "SpecificFlight.h"
using namespace std;
template<class T>
class Graph {
public:
	int NoOfVertex;
	graph_List<T>* arr;


	Graph() {
		int size;
		Flights flights;
		string* str = extractFlights(flights.departure_city, flights.destination_city, flights.Flight_ctr, size);

		NoOfVertex = size;
		Flights fl;

		arr = new graph_List<T>[size];
		//string str[]={"amserdam","dubai","larkana","muzafrabad","ahmedabad","sirinagar","china","chichawatni","bahadurpur"};
		//        string str[]  =


		for (int i = 0; i < size; i++) {
			arr[i].head = NULL;
			arr[i].data = str[i];
		}
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				string time;
				OneFlight omf[100];
				int TlFlights = 0;
				//    cout<<"\n"<<str[i]<<" "<<str[j];
				if (flights.flightexistinit(str[i], str[j], omf, TlFlights)) {
					//     cout<<"-  "<<str[i]<<" "<<str[j];
					addEdge(i, j, omf, TlFlights);

				}

			}
		}
	}

	void addEdge(int src, int dest, OneFlight* data, int TlFlights) {
		Node_Graph<T>* nptr = new Node_Graph<T>;
		nptr->data = dest;
		nptr->TotalFlights = TlFlights;
		nptr->flightDetails = data;
		nptr->setFlightDetails(data, TlFlights);
		// cout<<data->cost_travel<<"------";
		nptr->next = NULL;
		nptr->next = arr[src].head;
		arr[src].head = nptr;
		arr[src].head->sort_flightCost();
		arr[src].head->sort_flight_time();

		//        arr[src].head->print();


				//    nptr=newAdjListNode(src); commented for not makin git two way
				//     nptr->next=arr[dest].head;
				//    arr[dest].head=nptr;

	}

	void printer() {
		for (int i = 0; i < NoOfVertex; i++) {
			Node_Graph<T>* root = arr[i].head;
			std::cout << "Adjacency list of vertex " << i << arr[i].data;
			while (root != NULL) {
				cout << " -> " << arr[root->data].data;
				root = root->next;
			}
			cout << endl;
		}
	}

	void BFS(int s) {
		Queue<int> Q;
		bool* explored = new bool[NoOfVertex + 1];//  it Keeps track of explored vertices
		int ctr = 0;
		for (int i = 1; i <= NoOfVertex; ++i)// Initailization of  all vertices as unexplored
			explored[i] = false;

		Q.Enqueue(s);//enqueue(s);// Pushing of  initial vertex to the queue
		explored[s] = true; // marking it as explored
		cout << "Breadth first Search starting from vertex ";
		cout << s << " : " << endl;

		//Unless the queue is empty is to be performed
		while (!Q.IsEmpty()) {
			//        // Pop the vertex from the queue
			int v = Q.Dequeue();
			//
			//        //display the explored vertices
			cout << v << " -+" << arr[v].data;
			//
			//        //From the explored vertex v try to explore all the
			//        //connected vertices
			for (int w = 0; w < NoOfVertex; ++w)
				//
								/*Explores the vertex w if it is connected to v
					//            and and if it is unexplored*/
				if (isConnected(v, w) && !explored[w]) {
					//                //adds the vertex w to the queue
					ctr++;
					Q.Enqueue(w);
					cout << "\n" << w << "Enque\n";
					//                //marks the vertex w as visited
					explored[w] = true;
				}
		}
		cout << endl;
		delete[] explored;
		cout << "\n\n\n" << ctr << "\n\n\n";
	}

	void DFS(int s) {
		stacks<int> Q;
		stacks<int> rec;
		int costarr[100];
		int token = 0;
		costarr[token] = 0;
		token++;
		bool* explored = new bool[NoOfVertex];//  it Keeps track of explored vertices

		for (int i = 1; i <= NoOfVertex; ++i)// Initailization of  all vertices as unexplored
			explored[i] = false;

		rec.push(s);
		Q.push(s);//enqueue(s);// Pushing of  initial vertex to the queue
		explored[s] = true; // marking it as explored
//        cout << "Depth first Search starting from vertex ";
//        cout << s << " : " << endl;

		//Unless the queue is empty is to be performed
		while (!Q.isEmpty()) {
			//        // Pop the vertex from the queue
			int v = Q.pop();
			//
			//        //display the explored vertices

			//
			//        //From the explored vertex v try to explore all the
			//        //connected vertices
			for (int w = 0; w < NoOfVertex; ++w) {
				//
								/*Explores the vertex w if it is connected to v
					//            and and if it is unexplored*/
				if (isConnected(v, w) && !explored[w]) {
					//                //adds the vertex w to the queue
					//                    costarr[token++]=
					Q.push(w);
					rec.push(w);

					//                    cout<<"\n"<<w<<"Enque\n"<<arr[w];
					//                //marks the vertex w as visited
					explored[w] = true;
				}
			}
		}

		while (!rec.isEmpty()) { std::cout << arr[rec.pop()].data << "\n"; }
		delete[] explored;
	}

	bool isConnected(int a, int b) {
		if (a >= NoOfVertex || b >= NoOfVertex)
			return false;
		Node_Graph<T>* root = arr[b].head;
		//        std::cout<<"\nAdjacency list of vertex "<<arr[a].data;
		while (root) {
			// cout<<" TESTING -> "<<a<<"   "<<root->data;
			if (root->data == a) {
				return true;

			}

			root = root->next;
		}

		return false;
	}

	int getinde(string str) {
		for (int i = 0; i < NoOfVertex; i++) {
			if (arr[i].data.compare(str) == 0) { return i; }
		}
	}

	OneFlight dijkstraforsen3(int src, OneFlight of, int dest, bool& found) {
		int *Minarr = new int[NoOfVertex];
		Queue<int> Q;
		Q.Enqueue(src);
		int *parent = new int[NoOfVertex];
		int *parentdist = new int[NoOfVertex];
		OneFlight *currnt_spcFlight = new OneFlight[NoOfVertex];
		int *flightimeend = new int[NoOfVertex];
		found = false;
		for (int i = 0; i < NoOfVertex; i++) {
			Minarr[i] = 99999999;
			parent[i] = src;
			parentdist[i] = 0;
			flightimeend[i] = 0;
		}


		Q.Dequeue();
		int ver = getinde(of.destination_city);
		Q.Enqueue(ver);
		parent[ver] = src;
		currnt_spcFlight[ver] = of;

		Minarr[ver] = of.getintcost();
		parentdist[ver] = of.getintcost();
		flightimeend[ver] = of.Arival_Time_In_Seconds();
		//        arr[src].head->isAfter(src , flightimeend , arr[ver].head, ver );
		parent[ver] = src;

		//int TEMPVAR=0;

		while (!Q.IsEmpty()) {
			int v = Q.Dequeue();
			int k = v;
			Node_Graph<T>* temp = arr[v].head;
			//   temp->sort_flightCost();
			while (temp) {
				//       temp->print();
				//    cout<<"_"<<temp->flightDetails->getintcost()<<endl;
				int intCost = temp->flightDetails->getintcost();
				//            cout<<"\n "<<Minarr[temp->data]  <<"  "<<intCost<<"  "<<temp->data<<"\n";
//                cout<<"\n=="<<temp->data<<" "<<intCost<<"=="<<Minarr[temp->data] <<" - "<<  intCost + parentdist[parent[temp->data]]  <<"n";
				int tempd = parentdist[v];
				if (Minarr[temp->data] > intCost + parentdist[v]) {
					//                    cout<<"\nless found \n";
					if (Minarr[temp->data] >= Minarr[v]) {


						if (arr[v].head->isAfter(v, flightimeend, arr[k].head, temp->data, intCost, currnt_spcFlight, arr[temp->data].data)) {
							//k = temp->data;
							parent[temp->data] = v;
							Minarr[temp->data] = intCost + tempd;
							parentdist[temp->data] = intCost + tempd;

						}
						Q.Enqueue(temp->data);
					}


				}

				temp = temp->next;
			}
			//    Q.Display();
		}


		int i = dest;
		do {
			cout << "\n#";
			currnt_spcFlight[i].printer();
			i = parent[i];
		} while (i != src);
		/// cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%   --  "<<arr[dest].data;

		for (int y = 0; y < NoOfVertex; y++) {
			//  cout<<"\n"<<arr[y].data<<"         "<< Minarr[y];

		}

		if (Minarr[dest] == 99999999) {

			//       cout<< "\n          **************************    NO LINK TO THIS PLACE MATCHES YOR SPECIFICATIONS     *************";
		}
		else
		{
			found = true;
			//  cout<<"^^^^^^^^^^^^    "<<Minarr[dest];

		}
		return  currnt_spcFlight[dest];
	}


	OneFlight dijkstraforsen2(int src, OneFlight of, int dest) {
		int *Minarr = new int[NoOfVertex];
		Queue<int> Q;
		Q.Enqueue(src);
		int *parent = new int[NoOfVertex];
		int *parentdist = new int[NoOfVertex];
		OneFlight *currnt_spcFlight = new OneFlight[NoOfVertex];
		int *flightimeend = new int[NoOfVertex];

		for (int i = 0; i < NoOfVertex; i++) {
			Minarr[i] = 99999999;
			parent[i] = src;
			parentdist[i] = 0;
			flightimeend[i] = 0;
		}


		Q.Dequeue();
		int ver = getinde(of.destination_city);
		Q.Enqueue(ver);
		parent[ver] = src;
		currnt_spcFlight[ver] = of;

		Minarr[ver] = of.getintcost();
		parentdist[ver] = of.getintcost();
		flightimeend[ver] = of.Arival_Time_In_Seconds();
		//        arr[src].head->isAfter(src , flightimeend , arr[ver].head, ver );
		parent[ver] = src;

		//int TEMPVAR=0;

		while (!Q.IsEmpty()) {
			int v = Q.Dequeue();
			int k = v;
			Node_Graph<T>* temp = arr[v].head;
			//   temp->sort_flightCost();
			while (temp) {
				//       temp->print();
				//    cout<<"_"<<temp->flightDetails->getintcost()<<endl;
				int intCost = temp->flightDetails->getintcost();
				//            cout<<"\n "<<Minarr[temp->data]  <<"  "<<intCost<<"  "<<temp->data<<"\n";
//                cout<<"\n=="<<temp->data<<" "<<intCost<<"=="<<Minarr[temp->data] <<" - "<<  intCost + parentdist[parent[temp->data]]  <<"n";
				int tempd = parentdist[v];
				if (Minarr[temp->data] > intCost + parentdist[v]) {
					//                    cout<<"\nless found \n";
					if (Minarr[temp->data] >= Minarr[v]) {


						if (arr[v].head->isAftersen2(v, flightimeend, arr[k].head, temp->data, intCost, currnt_spcFlight, arr[temp->data].data)) {
							//k = temp->data;
							parent[temp->data] = v;
							Minarr[temp->data] = intCost + tempd;
							parentdist[temp->data] = intCost + tempd;

						}
						Q.Enqueue(temp->data);
					}


				}

				temp = temp->next;
			}
			//    Q.Display();
		}


		int i = dest;
		do {
			cout << "\n#";
			currnt_spcFlight[i].printer();
			i = parent[i];
		} while (i != src);
		cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%   --  " << arr[dest].data;

		for (int y = 0; y < NoOfVertex; y++) {
			cout << "\n" << arr[y].data << "         " << Minarr[y];

		}

		//        if (Minarr[dest] == 99999999) {
		//
		//            cout<< "\n          **************************    NO LINK TO THIS PLACE MATCHES YOR SPECIFICATIONS     *************";
		//        }else
		//            cout<<"^^^^^^^^^^^^    "<<Minarr[dest];
		return  currnt_spcFlight[dest];
	}


	void dijkstra(int src, OneFlight of, int dest) {
		int *Minarr =new int [NoOfVertex];
		Queue<int> Q;
		Q.Enqueue(src);
		int *parent = new int [NoOfVertex];
		int *parentdist = new int[NoOfVertex];
		OneFlight *currnt_spcFlight = new OneFlight[NoOfVertex];
		int *flightimeend = new int[NoOfVertex];

		for (int i = 0; i < NoOfVertex; i++) {
			Minarr[i] = 99999999;
			parent[i] = src;
			parentdist[i] = 0;
			flightimeend[i] = 0;
		}


		Q.Dequeue();
		int ver = getinde(of.destination_city);
		Q.Enqueue(ver);
		parent[ver] = src;
		currnt_spcFlight[ver] = of;

		Minarr[ver] = of.getintcost();
		parentdist[ver] = of.getintcost();
		flightimeend[ver] = of.Arival_Time_In_Seconds();
		//        arr[src].head->isAfter(src , flightimeend , arr[ver].head, ver );
		parent[ver] = src;

		//int TEMPVAR=0;

		while (!Q.IsEmpty()) {
			int v = Q.Dequeue();
			int k = v;
			Node_Graph<T>* temp = arr[v].head;
			//   temp->sort_flightCost();
			while (temp) {
				//       temp->print();
				//    cout<<"_"<<temp->flightDetails->getintcost()<<endl;
				int intCost = temp->flightDetails->getintcost();
				//            cout<<"\n "<<Minarr[temp->data]  <<"  "<<intCost<<"  "<<temp->data<<"\n";
//                cout<<"\n=="<<temp->data<<" "<<intCost<<"=="<<Minarr[temp->data] <<" - "<<  intCost + parentdist[parent[temp->data]]  <<"n";
				int tempd = parentdist[v];
				if (Minarr[temp->data] > intCost + parentdist[v]) {
					//                    cout<<"\nless found \n";
					if (Minarr[temp->data] >= Minarr[v]) {


						if (arr[v].head->isAfter(v, flightimeend, arr[k].head, temp->data, intCost, currnt_spcFlight, arr[temp->data].data)) {
							//k = temp->data;
							parent[temp->data] = v;
							Minarr[temp->data] = intCost + tempd;
							parentdist[temp->data] = intCost + tempd;

						}
						Q.Enqueue(temp->data);
					}


				}

				temp = temp->next;
			}
			//    Q.Display();
		}


		int i = dest;
		do {
			cout << "\n#";
			currnt_spcFlight[i].printer();
			i = parent[i];
		} while (i != src);
		cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%   --  " << arr[dest].data;

		for (int y = 0; y < NoOfVertex; y++) {
			cout << "\n" << arr[y].data << "         " << Minarr[y];

		}

		//        if (Minarr[dest] == 99999999) {
		//
		//            cout<< "\n          **************************    NO LINK TO THIS PLACE MATCHES YOR SPECIFICATIONS     *************";
		//        }else
		//            cout<<"^^^^^^^^^^^^    "<<Minarr[dest];
	}

	//for(int x = 0 ; x< NoOfVertex ; x++){
	//    cout << "\n " << arr[x].data << " cost = " << Minarr[x];}
	//
	//    }

	void dijkstra(int src, OneFlight of, int transit, int dest) {

		int *Minarr = new int[NoOfVertex];


		Queue<int> Q;
		Q.Enqueue(src);
		int *parent = new int[NoOfVertex];
		int *parentdist = new int[NoOfVertex];
		OneFlight *currnt_spcFlight = new OneFlight[NoOfVertex];
		//
		int *flightimeend = new int[NoOfVertex];

		for (int i = 0; i < NoOfVertex; i++) {
			Minarr[i] = 99999999;
			parent[i] = src;
			parentdist[i] = 0;
			flightimeend[i] = 0;
		}


		Q.Dequeue();
		int ver = getinde(of.destination_city);
		Q.Enqueue(ver);
		parent[ver] = src;
		currnt_spcFlight[ver] = of;

		Minarr[ver] = of.getintcost();
		parentdist[ver] = of.getintcost();
		flightimeend[ver] = of.Arival_Time_In_Seconds();
		//        arr[src].head->isAfter(src , flightimeend , arr[ver].head, ver );
		parent[ver] = src;

		//int TEMPVAR=0;
		bool got_that_stay = false;
		while (!Q.IsEmpty()) {
			int v = Q.Dequeue();
			Node_Graph<T>* temp = arr[v].head;
			//   temp->sort_flightCost();
			while (temp) {
				//       temp->print();
				//    cout<<"_"<<temp->flightDetails->getintcost()<<endl;
				int intCost = temp->flightDetails->getintcost();
				//            cout<<"\n "<<Minarr[temp->data]  <<"  "<<intCost<<"  "<<temp->data<<"\n";
				cout << "\n==" << temp->data << " " << intCost << "==" << Minarr[temp->data] << " - "
					<< intCost + parentdist[parent[temp->data]] << "n";
				int tempd = parentdist[v];
				if (Minarr[temp->data] > intCost + parentdist[v]) {
					cout << "\nless found \n";
					if (Minarr[temp->data] >= Minarr[v]) {
						//int selected_cost;bool isAfter(int num,int * ptr,Node_Graph* fl ,string str2, int son ,int time_in_hours , bool  &found_that ,int &cost , OneFlight* flight ,string str){
						if (arr[v].head->isAfter(v, flightimeend, arr[v].head, arr[v].data, temp->data, transit, got_that_stay, intCost, currnt_spcFlight, arr[temp->data].data)) {
							parent[temp->data] = v;
							Minarr[temp->data] = intCost + tempd;
							parentdist[temp->data] = intCost + tempd;
							Q.Enqueue(temp->data);
						}
					}


				}
				temp = temp->next;
			}
			//    Q.Display();
		}

		for (int i = 0; i < NoOfVertex; i++) {
			cout << "\n " << arr[i].data << " cost = " << Minarr[i];
		}
		//        Node_Graph<T> *temp = arr[0].head;
		//        while (temp) {
		////                                cout<<"______"<<temp->data;
		//            temp = temp->next;
		//        }
		if (got_that_stay)cout << "~~~~~~~~~~~~~~~~~~~~~~~got that stay ~~~~~~~~~~~~~~~";

		else
			cout << "~~~~~~~~~~~~~~~~~~~~~~~DIDNT FOUND ANY   ~~~~~~~~~~~~~~~";


		int i = dest;
		do {
			currnt_spcFlight[i].printer();
			i = parent[i];
			//         i++;
		} while (i != src);

		if (Minarr[dest] == 99999999) {

			cout << "\n          **************************    NO LINK TO THIS PLACE MATCHES YOR SPECIFICATIONS     *************";
		}
		int in = dest;
		do {
			cout << "\n#";
			currnt_spcFlight[in].printer();
			in = parent[in];
		} while (in != src);
		cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%   --  " << arr[dest].data;

		for (int y = 0; y < NoOfVertex; y++) {
			cout << "\n" << arr[y].data << "         " << Minarr[y];

		}

	}


	bool isclique(int* arr, int len) {

		for (int i = 0; i < len; i++) {


			for (int j = 0; j < len; j++) {


				if (!isConnected(arr[i], arr[j])) {
					return false;
				}

			}
		}
		return true;
	}

	int connected_elements() {
		int ctr = 0;


		return ctr;
	}

	void printer_CITY() {
		for (int i = 0; i < NoOfVertex; i++)
			std::cout << "Adjacency list of vertex " << i << arr[i].data << "\n";
	}

	void directlink() {
		Flights flight;
		printer_CITY();
		int index = -9;
		bool flg = false;
		do {
			if (flg) { cout << "++++++++++++++++++++++++SoRRY enter your number again ++++++++++++++++++++\n"; }
			cout << "WHERE ARE YOU ?? select by entering number from  0 to " << NoOfVertex - 1 << "\n\n";
			cin >> index;
			//        index=5;
			flg = true;
		} while (index < 0 || index >= NoOfVertex);


		int index_dest = -9;
		flg = false;
		do {
			if (flg) { cout << "++++++++++++++++++++++++SoRRY enter your number again ++++++++++++++++++++\n"; }
			cout << "WHERE DO YOU WANT TO GO ?? select by entering number from  0 to " << NoOfVertex - 1 << "\n\n";
			cin.ignore();
			cin >> index_dest;
			//        index_dest=5;

			flg = true;
		} while (index_dest < 0 || index_dest >= NoOfVertex);

		int TOtalflights_betwewenCity = 0;

		OneFlight oneflight[20];

		//        void  flightexist(string str1, string str2, OneFlight* onf, int& ret) {

		flight.flightexist(arr[index].data, arr[index_dest].data, oneflight, TOtalflights_betwewenCity);

		for (int i = 0; i < TOtalflights_betwewenCity; i++) {
			oneflight[i].printer();

		}
		{


		}
	}

	OneFlight printer_edges(int item) {
		Node_Graph<T>* root = arr[item].head;
		std::cout << "Adjacency list of vertex " << item << arr[item].data;
		//OneFlight flo[NoOfVertex*NoOfVertex];
		int ctr = 0;
		while (root != NULL) {


			for (int i = 0; i < root->TotalFlights; i++) {
				cout << " -> " << ctr << " ";
				root->flightDetails[i].printer();
				ctr++;
			}
			root = root->next;
		}
		int index = 1;

		root = arr[item].head;

		do {
			cout << "which flight time do you want to take" << ctr;
			cin >> index;
		} while (index < 0 || index > ctr);


		int newind = 0;

		while (root != NULL) {
			for (int i = 0; i < root->TotalFlights; i++) {
				cout << " -> " << index << " " << newind;
				if (index == newind) {
					root->CurrentFlight = root->flightDetails[i];
					return root->flightDetails[i];
				}

				root->flightDetails[i].printerdatetime();
				newind++;
			}
			root = root->next;
		}
	}

	OneFlight printer_edgesfor1(int item) {
		Node_Graph<T>* root = arr[item].head;
		std::cout << "Adjacency list of vertex " << item << arr[item].data;
		//OneFlight flo[NoOfVertex*NoOfVertex];
		int ctr = 0;
		while (root != NULL) {


			for (int i = 0; i < root->TotalFlights; i++) {
				cout << " -> " << ctr << " ";
				root->flightDetails[i].printer();
				ctr++;
			}
			root = root->next;
		}
		int index = 1;

		root = arr[item].head;

		do {
			cout << "which flight time do you want to take" << ctr;
			cin >> index;
		} while (index < 0 || index > ctr);


		int newind = 0;

		while (root != NULL) {
			for (int i = 0; i < root->TotalFlights; i++) {
				cout << " -> " << index << " " << newind;
				if (index == newind) {
					root->CurrentFlight = root->flightDetails[i];
					return root->flightDetails[i];
				}

				root->flightDetails[i].printerdatetime();
				newind++;
			}
			root = root->next;
		}
	}



	void Transitwaiting() {
		int hours_to_wait;
		cout << "\n# HOW MANY HOURS DO YOU WANT TO WAIT #\n";
		cin >> hours_to_wait;

		Flights flight;
		printer_CITY();
		int index = -9;
		bool flg = false;
		do {
			if (flg) { cout << "++++++++++++++++++++++++SoRRY enter your number again ++++++++++++++++++++\n"; }
			cout << "WHERE ARE YOU ?? select by entering number from  0 to " << NoOfVertex - 1 << "\n\n";
			cin >> index;
			flg = true;
		} while (index < 0 || index >= NoOfVertex);
		flg = false;
		int dest;
		do {
			if (flg) { cout << "++++++++++++++++++++++++SoRRY enter your number again ++++++++++++++++++++\n"; }
			cout << "WHERE do you want to go  ?? select by entering number from  0 to " << NoOfVertex - 1 << "\n\n";
			cin >> dest;
			//            dest= 3;

			flg = true;
		} while (dest < 0 || dest >= NoOfVertex);

		Node_Graph<T>* temp_direct = arr[index].head;

		while (temp_direct) {

			if (temp_direct->data == dest) {

				cout << "################   THERE EXIST A DIRECT FLIGHT $$$$$$$$$$$$$$$$";
				return;

			}
			temp_direct = temp_direct->next;
		}
		OneFlight of = printer_edges(index);




		//        DFS(index);


		//        dijkstra(index,of,dest);
		dijkstra(index, of, hours_to_wait, dest);

	}

	void allLinks() {

		Flights flight;
		printer_CITY();
		int index = -9;
		bool flg = false;
		do {
			if (flg) { cout << "++++++++++++++++++++++++SoRRY enter your number again ++++++++++++++++++++\n"; }
			cout << "WHERE ARE YOU ?? select by entering number from  0 to " << NoOfVertex - 1 << "\n\n";
			cin >> index;
			flg = true;
		} while (index < 0 || index >= NoOfVertex);
		flg = false;
		int dest;
		do {
			if (flg) { cout << "++++++++++++++++++++++++SoRRY enter your number again ++++++++++++++++++++\n"; }
			cout << "WHERE do you want to go  ?? select by entering number from  0 to " << NoOfVertex - 1 << "\n\n";
			cin >> dest;


			flg = true;
		} while (dest < 0 || dest >= NoOfVertex);

		Node_Graph<T>* temp_direct = arr[index].head;

		while (temp_direct) {

			if (temp_direct->data == dest) {

				cout << "################   THERE EXIST A DIRECT FLIGHT $$$$$$$$$$$$$$$$";
				return;

			}
			temp_direct = temp_direct->next;
		}
		OneFlight of = printer_edges(index);

		//        DFS(index);

		dijkstra(index, of, dest);
	}

	void Scenerio5() {
		Flights flight;
		printer_CITY();
		int index = -9;
		bool flg = false;
		do {
			if (flg) { cout << "++++++++++++++++++++++++SoRRY enter your number again ++++++++++++++++++++\n"; }
			cout << "WHERE ARE YOU ?? select by entering number from  0 to " << NoOfVertex - 1 << "\n\n";
			cin >> index;
			flg = true;
		} while (index < 0 || index >= NoOfVertex);
		flg = false;
		int dest;
		do {
			if (flg) { cout << "++++++++++++++++++++++++SoRRY enter your number again ++++++++++++++++++++\n"; }
			cout << "WHERE do you want to go  ?? select by entering number from  0 to " << NoOfVertex - 1 << "\n\n";
			cin >> dest;


			flg = true;
		} while (dest < 0 || dest >= NoOfVertex);


		Node_Graph<T>* temp_direct = arr[index].head;

		OneFlight of = printer_edgesfor1(index);


		while (temp_direct) {

			if (temp_direct->data == dest) {

				cout << "################   THERE EXIST A DIRECT FLIGHT $$$$$$$$$$$$$$$$";
				return;

			}
			cout << "################   THERE doesnt  EXIST A DIRECT FLIGHT $$$$$$$$$$$$$$$$";
			//        DFS(index);

			//        dijkstra(index,of,dest);
		}
	}
	void  Scenerio1() {
		allLinks();
	}
	/* void  Scenerio2(){
		}*/
		/*
		void  Scenerio2(){
		}
		void  Scenerio2(){
		}*/


	void  Scenerio3() {

		Flights flight;
		printer_CITY();
		int index = -9;
		bool flg = false;
		do {
			if (flg) { cout << "++++++++++++++++++++++++SoRRY enter your number again ++++++++++++++++++++\n"; }
			cout << "WHERE ARE YOU ?? select by entering number from  0 to " << NoOfVertex - 1 << "\n\n";
			cin >> index;
			flg = true;
		} while (index < 0 || index >= NoOfVertex);
		flg = false;
		int dest;
		do {
			if (flg) { cout << "++++++++++++++++++++++++SoRRY enter your number again ++++++++++++++++++++\n"; }
			cout << "WHERE do you want to go  ?? select by entering number from  0 to " << NoOfVertex - 1 << "\n\n";
			cin >> dest;


			flg = true;
		} while (dest < 0 || dest >= NoOfVertex);
		flg = false;
		int midd;
		do {
			if (flg) { cout << "++++++++++++++++++++++++SoRRY enter your number again ++++++++++++++++++++\n"; }
			cout << "WHERE do you want to   SET TRANSIT LOCATION    ?? select by entering number from  0 to " << NoOfVertex - 1 << "\n\n";
			cin >> midd;


			flg = true;
		} while (midd < 0 || midd >= NoOfVertex);

		Node_Graph<T>* temp_direct = arr[index].head;

		while (temp_direct) {

			if (temp_direct->data == dest) {

				cout << "################   THERE EXIST A DIRECT FLIGHT $$$$$$$$$$$$$$$$";
				return;

			}
			temp_direct = temp_direct->next;
		}
		OneFlight of = printer_edges(index);

		//        DFS(index);

		bool val;
		OneFlight thisOne = dijkstraforsen3(index, of, midd, val);

		if (val) {

			dijkstraforsen3(midd, thisOne, dest, val);
			if (val) {
				cout << "################   THERE  exist  FLIGHT $$$$$$$$$$$$$$$$";
			}
			else
				cout << "################   THERE exist  FLIGHT $$$$$$$$$$$$$$$$";

		}


		else
			cout << "################   THERE not  FLIGHT $$$$$$$$$$$$$$$$";


	}
	void  Scenerio4() {


		Flights flight;
		printer_CITY();
		int index = -9;
		bool flg = false;
		do {
			if (flg) { cout << "++++++++++++++++++++++++SoRRY enter your number again ++++++++++++++++++++\n"; }
			cout << "WHERE ARE YOU ?? select by entering number from  0 to " << NoOfVertex - 1 << "\n\n";
			cin >> index;
			flg = true;
		} while (index < 0 || index >= NoOfVertex);
		flg = false;
		int dest;
		do {
			if (flg) { cout << "++++++++++++++++++++++++SoRRY enter your number again ++++++++++++++++++++\n"; }
			cout << "WHERE do you want to go  ?? select by entering number from  0 to " << NoOfVertex - 1 << "\n\n";
			cin >> dest;


			flg = true;
		} while (dest < 0 || dest >= NoOfVertex);
		flg = false;
		int midd;
		do {
			if (flg) { cout << "++++++++++++++++++++++++SoRRY enter your number again ++++++++++++++++++++\n"; }
			cout << "WHERE do you want to   SET TRANSIT LOCATION    ?? select by entering number from  0 to " << NoOfVertex - 1 << "\n\n";
			cin >> midd;


			flg = true;
		} while (midd < 0 || midd >= NoOfVertex);
		flg = false;
		int time;
		do {
			if (flg) { cout << "++++++++++++++++++++++++SoRRY enter your number again ++++++++++++++++++++\n"; }
			cout << "how much time do you want to stay there   ?? select by entering number from  0 to " << NoOfVertex - 1 << "\n\n";
			cin >> time;


			flg = true;
		} while (time < 0);

		Node_Graph<T>* temp_direct = arr[index].head;

		while (temp_direct) {

			if (temp_direct->data == dest) {

				cout << "################   THERE EXIST A DIRECT FLIGHT $$$$$$$$$$$$$$$$";
				return;

			}
			temp_direct = temp_direct->next;
		}
		OneFlight of = printer_edges(index);

		//        DFS(index);

		bool val;
		OneFlight thisOne = dijkstraforsen3(index, of, midd, val);

		if (val) {

			OneFlight thatone = dijkstraforsen3(midd, thisOne, dest, val);
			if (val) {
				cout << "################   THERE  exist  FLIGHT $$$$$$$$$$$$$$$$";
				thisOne.printer();
				thatone.printer();
				if (thisOne.Arival_Time_In_Seconds() + time * 60 * 60 < thatone.Departure_Time_In_Seconds())
				{

					cout << "################ &*&&* YOU CAN SPEND QUALITY TIME HERE   FLIGHT $$$$$$$$$$$$$$$$";


				}
			}
			else
				cout << "################   THERE exist  FLIGHT $$$$$$$$$$$$$$$$";


		}


		else
			cout << "################   THERE not  FLIGHT $$$$$$$$$$$$$$$$";

	}
	void  Scenerio2() {


		Flights flight;
		printer_CITY();
		int index = -9;
		bool flg = false;
		do {
			if (flg) { cout << "++++++++++++++++++++++++SoRRY enter your number again ++++++++++++++++++++\n"; }
			cout << "WHERE ARE YOU ?? select by entering number from  0 to " << NoOfVertex - 1 << "\n\n";
			cin >> index;
			flg = true;
		} while (index < 0 || index >= NoOfVertex);
		flg = false;
		int dest;
		do {
			if (flg) { cout << "++++++++++++++++++++++++SoRRY enter your number again ++++++++++++++++++++\n"; }
			cout << "WHERE do you want to go  ?? select by entering number from  0 to " << NoOfVertex - 1 << "\n\n";
			cin >> dest;


			flg = true;
		} while (dest < 0 || dest >= NoOfVertex);

		Node_Graph<T>* temp_direct = arr[index].head;

		while (temp_direct) {

			if (temp_direct->data == dest) {

				cout << "################   THERE EXIST A DIRECT FLIGHT $$$$$$$$$$$$$$$$";
				return;

			}
			temp_direct = temp_direct->next;
		}
		OneFlight of = printer_edges(index);

		//        DFS(index);

		dijkstraforsen2(index, of, dest);

	}
	//return true;
};