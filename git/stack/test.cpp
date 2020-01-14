#include "pch.h"
#include <iostream>
#include "stacks.h"
#include <fstream>
#include <string>
using namespace std;
TEST(TestCaseName, TestName) {


	stacks  <int>stk;
	
	stk.push(1);
	stk.push(2);
	stk.push(3);
	stk.push(4);
	stk.push(5);
	stk.push(6);
	stk.push(7);
	stk.push(8);
	stk.display();
	stk.pop();
	stk.pop();
	stk.pop();
	stk.pop();
	stk.pop();
	stk.pop();
	stk.pop();
	stk.pop();
	stk.pop();
	stk.pop();
	stk.pop();
	stk.pop();
	stk.display();
	stk.clear();
	stk.isEmpty();
	
	bool error = false;
	stacks <char>charstk;
	ifstream myfile("example.txt");
	string line;

	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			cout << line << '\n';

			for (int i = 0; line[i] != '\0'; i++)
			{
				cout << i << '\n';
				if (line[i] == '{') {
					charstk.push(line[i]);
				}

				else if (line[i] == '}') {
					if (charstk.isEmpty()) {
						error = true;
						break;
					}

					charstk.pop();
				}
				else if (line[i] == '(') {
					charstk.push(line[i]);
				}

				else if (line[i] == ')') {
					if (charstk.isEmpty()) {
						error = true;
						break;
					}

					charstk.pop();
				}

				else if (line[i] == '[') {
					charstk.push(line[i]);
				}

				else if (line[i] == ']') {
					if (charstk.isEmpty()) {
						error = true;
						break;
					}

					charstk.pop();
				}


			}

			if (error) {
				break;
			}


		}
		myfile.close();
	}

				  //my codes checks [] ,() and {}
	else cout << "Unable to open file";

	if (!error && charstk.isEmpty())
		cout << "\n----------------------------------passed-------------------------\n ";
	else {
		cout << "\n----------------------------------ERROR-------------------------\n ";

	}
	std::cout << "Hello World!\n";

  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}