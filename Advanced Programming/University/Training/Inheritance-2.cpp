#include<iostream>
#include<string>
using namespace std;

class Point {
private:
	int x;
protected:
	string name;
public:
	int y;
	Point() { name = "Point:C1"; x = y = 0; cout << "Point: Default Constructor #1 " << name << endl; }
	Point(int k) { name = "Point:C2"; cout << "Point: Constructor #2 " << name << endl;  x = k; y = 2 + k; }
	~Point() { cout << "Point: Destructor " << name << endl; }
	void print() { cout << name << ",  (" << x << "," << y << ")\n"; }
	int getX() { return x; }
};

class Point3D : public Point {
public:
	void print() { //cout<<"["<<x<<"-"<<y<<"]\n";	Error: x private in Point, hidden in Point3D
		cout << "name=" << name << ", [" << getX() << "-" << y << "]\n";
		Point::print();
		// The :: (scope resolution) operator is used so that you can still use them
	}
};

int main()
{
	Point p;
	//p.x = 1; Error Private
	p.y = 2;
	p.print();
	cout<<"...................\n";
	Point3D obj;
	// obj.x = 1; Error Private, hidden in Point3D
	obj.y = 3;
	obj.print();
	//obj.name = "XYZ"; Error, name is protected in Point
}