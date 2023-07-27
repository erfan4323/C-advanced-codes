#include<iostream>
using namespace std;
class Point{
	int x;
public:
	int y;
	Point() {
		cout << "Point : constructor #1" << endl;
		x = y = 0;
	}
	Point(int x, int y) {
		cout << "Point : constructor #1" << endl;
		this->x = x;
		this->y = y;
	}
	void print() {
		cout << "(" << x << "," << y << ")" << endl;
	}
};
class derived :  Point {
};

int main()
{
	derived obj;
	//obj.print();
}
