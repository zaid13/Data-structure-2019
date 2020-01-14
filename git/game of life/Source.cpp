#include "iostream"
#include "cstdlib"
#include "Header.h"
#include "string"
#include <fstream>
#include "time.h"
#include <windows.h>
#include <stdio.h>
using namespace std;
void Display(int n ,Node* nd ,int size) {		//funtion that takes Node array its length and n the size of plot and display out put 

		
int **	Ptr = new int* [n];
	for (int i = 0; i < n; i++) {

		Ptr[i] = new int[n];

	}

	for (int i =0 ;i<size  ;i++)
		Ptr[nd[i].y][nd[i].x] = 1;


	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {
			if (Ptr[i][j]==1) {
				cout << "" << "#";


			}
			else {
				cout << "_" ;

			
			}
		}
		cout << "\n";
	}



}
void die(int Target, Node* nd, int size) { //funtion was created to delet entry but is not used

	for (int i = Target; i < size-1 ; i++) {
		nd[i] = nd[i+1];
	}

}	 //funtion was 
bool EntryExist(int x,int y ,Node* nd, int size  ) {	 //this funtion checks if parrticullar cell already exist or not

	for (int i = 0; i < size; i++) {
		if (x == nd[i].x && y == nd[i].y)
		{
			return true;
		}
	}
	return false;

}
int getsamecount(int x, int y, Node* ndptr, int size,int n) {		 // this funtio will return the no. of 1 in surrounding 
	int 	counter = 0;

	for (int i = 0; i < size; i++) {
	
			if (y > 0 )
				if (x == ndptr[i].x && y - 1 == ndptr[i].y)
				{
				//	cout << "upper \n";
					counter++;
				}
				
			if (y <= n -1)
				if (x == ndptr[i].x &&  y+1   == ndptr[i].y)
				{
			//		cout << "lower\n";
					counter++;
				}
				if (x > 0)
				if (x - 1 == ndptr[i].x &&  y == ndptr[i].y)
					counter++;

			if (x < n -1)
				if (x+1 == ndptr[i].x && y == ndptr[i].y)
					counter++;

			if (y < n -1 && x<n -1)
				if (x +1 == ndptr[i].x && 1 + y == ndptr[i].y)
					counter++;

			if (y > 0 && x>0 )
				if (x -1== ndptr[i].x &&  y-1 == ndptr[i].y)
					counter++;

			if (y > 0  && x<n-1)
				if (x + 1== ndptr[i].x &&  y-1 == ndptr[i].y)
					counter++;

			if (y < n -1 && x >0)
				if (x -1== ndptr[i].x &&  y+1 == ndptr[i].y)
					counter++;



	}

	return counter;

}
int main() {
	string input;					 //File handling not implemented 
//string input;					 //		 string line;
	ifstream myfile("example.txt");
	
	 if (myfile.is_open())
	{
	//	while (getline(myfile, line))
		{
//			cout << line << '\n';
		}
	//	myfile.close();
	}

//	else cout << "Unable to open file";


	//cout << "Hello world  ";

	srand(time(0));		  //random initializer giving it seed value
	
	int n, ndCount = 0;
	do {
		cout << "enter number ";
		cin >> n;					  //taking input from user to make a 2 D array
	} while (n < 0);
	int zerooco = 0;

	
	Node* ndptr;
	ndptr = new Node[n * n];		 //ndptr will store one value 
	int cnt = 0;

	int** Ptr;							// double pointer for 2d array 

	Ptr = new int* [n];
	for (int i = 0; i < n; i++) {

		Ptr[i] = new int[n]; //mem alloc

	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Ptr[i][j] =  rand()%2;
			if (Ptr[i][j]==1) {			  //for value 1 
				ndptr[ndCount].x = j;					// putting x in node 
				ndptr[ndCount].y = i;				 // putting y in node
				ndCount++;
			}
			else { zerooco++;
			
			}

		}
	}

	
	int ooa;

	Display(n, ndptr, ndCount);				  //display fro testing 

	do {
		//cout << zerooco;
		Node* nextFrame = new Node[n * n];			   //temp frame 
		int nextframecount = 0;

		Node* zeroArray = new Node[n * n];			 //array for zeros 
		int zerocount = 0;



		for (int i = 0; i < ndCount; i++)
		{
			int n0;

			n0 = getsamecount(ndptr[i].x, ndptr[i].y, ndptr, ndCount, n);  //geting no 1 surrounding 1 
		
			if (n0 == 2 || n0 == 3) {
				nextFrame[nextframecount].x = ndptr[i].x;
				nextFrame[nextframecount].y = ndptr[i].y;
				nextframecount++;												  //making entry 
		//		cout << "element added by one " << endl;
			}


		}


		for (int i = 0; i < ndCount; i++) {

			if (ndptr[i].y > 0) {
				int curx = ndptr[i].x;
				int cury = ndptr[i].y - 1;

				if (!EntryExist(curx, cury, ndptr, ndCount))
				{
					//zero found 

					if (!EntryExist(curx, cury, zeroArray, zerocount)) {	 //checking if it already or not exist in zero arr
						if (zeroArray[zerocount].push(curx, cury, n))	  //pushing it 
							zerocount++;
					}

				}

			}
			if (ndptr[i].y <= n - 1)
			{
				int curx = ndptr[i].x;
				int cury = ndptr[i].y + 1;

				if (!EntryExist(curx, cury, ndptr, ndCount))
				{
					//zero found 

					if (!EntryExist(curx, cury, zeroArray, zerocount)) {	 //checking if it exist in zero arr 
						if (zeroArray[zerocount].push(curx, cury, n))
							zerocount++;
					}

				}

			}



			if (ndptr[i].x > 0) {
				int curx = ndptr[i].x - 1;
				int cury = ndptr[i].y;


				if (!EntryExist(curx, cury, ndptr, ndCount))
				{
					//zero found 

					if (!EntryExist(curx, cury, zeroArray, zerocount)) {	 //checking if it exist in zero arr 
						if (zeroArray[zerocount].push(curx, cury, n))
							zerocount++;
					}

				}

			}

			if (ndptr[i].x < n - 1)
			{
				int curx = ndptr[i].x + 1;
				int cury = ndptr[i].y;

				if (!EntryExist(curx, cury, ndptr, ndCount))
				{
					//zero found 

					if (!EntryExist(curx, cury, zeroArray, zerocount)) {	 //checking if it exist in zero arr 
						if (zeroArray[zerocount].push(curx, cury, n))
							zerocount++;

					}

				}

			}

			if (ndptr[i].y < n - 1 && ndptr[i].x < n - 1) {

				int curx = ndptr[i].x + 1;
				int cury = ndptr[i].y + 1;

				if (!EntryExist(curx, cury, ndptr, ndCount))
				{
					//zero found 

					if (!EntryExist(curx, cury, zeroArray, zerocount)) {	 //checking if it exist in zero arr 
						if (zeroArray[zerocount].push(curx, cury, n))
							zerocount++;

					}

				}
			}


			if (ndptr[i].x > 0 && ndptr[i].y > 0) {

				int curx = ndptr[i].x - 1;
				int cury = ndptr[i].y - 1;

				if (!EntryExist(curx, cury, ndptr, ndCount))
				{
					//zero found 

					if (!EntryExist(curx, cury, zeroArray, zerocount)) {	 //checking if it exist in zero arr 
						if (zeroArray[zerocount].push(curx, cury, n))
							zerocount++;
					}

				}
			}


			if (ndptr[i].x > 0 && ndptr[i].y < n - 1)
			{

				int curx = ndptr[i].x - 1;
				int cury = ndptr[i].y + 1;

				if (!EntryExist(curx, cury, ndptr, ndCount))
				{
					//zero found 

					if (!EntryExist(curx, cury, zeroArray, zerocount)) {	 //checking if it exist in zero arr 
						if (zeroArray[zerocount].push(curx, cury, n))
							zerocount++;
					}

				}
			}
			if (ndptr[i].y < n - 1 && ndptr[i].x >0) {

				int curx = ndptr[i].x - 1;
				int cury = ndptr[i].y + 1;

				if (!EntryExist(curx, cury, ndptr, ndCount))
				{
					//zero found 

					if (!EntryExist(curx, cury, zeroArray, zerocount)) {	 //checking if it exist in zero arr 
						if (zeroArray[zerocount].push(curx, cury, n))
							zerocount++;
					}

				}
			}
		}


		for (int i = 0; i < zerocount; i++) { //this wwill print the zero array note there would be no over lap 
			//there will be only zeros in neighbourhood of 1s becuse only they can be changed to 1 in next gen 
		//	cout << i + 1 << "   x  = " << zeroArray[i].x << "       x = " << zeroArray[i].y << endl;
		}

		cout << "\n";
		for (int i = 0; i < zerocount; i++) {
			int n0;
			n0 = getsamecount(zeroArray[i].x, zeroArray[i].y, ndptr, ndCount, zerocount);	 //getiing no. of 1 surrounding zero

			if (n0 == 3) {
				//addding this eleement in alive 
				nextFrame[nextframecount].x = zeroArray[i].x;
				nextFrame[nextframecount].y = zeroArray[i].y;			//adding in temp fram
				nextframecount++;
			//	cout << "element added by zero "<<endl;
				

			}
		}

		cout << "\n";

		
		cout << "enter 1 to again";// << nextFrame;	   //keep pressing 1 to see next generation 
	

		ndCount = nextframecount;			   //getting ready for next generation 



		for (int i = 0; i < ndCount; i++) {
			ndptr[i] = nextFrame[i];		  //copying to main gen 

		//	cout << "   "<<nextFrame[i].x<<"       " << nextFrame[i].y<<i ;
		}
		delete []nextFrame;
		delete []zeroArray;


		cout << "\n";
		Display(n, ndptr, ndCount);
		cout << "\n";
		printf("starting to sleep...\n");
	Sleep(300); // Sleep three seconds
	
		cout << endl;
	//		cout << "Flushing the output stream." << flush;
		system("CLS");
	}while (true);
	return 0;
}