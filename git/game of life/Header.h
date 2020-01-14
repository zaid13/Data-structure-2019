#pragma once
class Node {
public:
	int x;
	int y;
	int count;
	Node() :count(0) {
		x = -3;
		y = -3;
	}

	bool push(int a,int  b, int max) {
		if (a >= 0 && b >= 0 && a < max && b < max)
		{
			x = a;
			y = b;
			//count++;
			return true;
		}
		return false;
	}

	int getX() {
		return x;
	}

	int getY() {
		return y;
	}
};