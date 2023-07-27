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
	Point() { name = "point:C1"; x = y = 0; cout << "Point: Default Constructor #1 " << name << endl; }
	Point(int k) { name = "point:C2"; cout << "Point: Constructor #2 " << name << endl;  x = k; y = 2 + k; }
	~Point() { cout << "Point: Destructor " << name << endl; }
	void print() { cout << name << ",  (" << x << "," << y << ")\n"; }
	int getX() { return x; }
};

class Point3D : public Point {
public:
	string name;

	void print() { 
		//cout<<"["<<x<<"-"<<y<<"]\n";	Error: x private in Point, hidden in Point3D
		cout << "name=" << name << ", [" << getX() << "-" << y << "]\n";
		Point::print();
	}
	//Point3D() : Point(5){ name = "Point3D:C1"; cout << "Point3D: Default Constructor #1 " << name << endl; }
	Point3D() { name = "Point3D:C1"; cout << "Point3D: Default Constructor #1 " << name << endl; }
	//Point3D(int i) { name = "Point3D:C2"; cout << "Point3D: Constructor #2 " << name << endl; }
	Point3D(int i) : Point(i + 2) { name = "Point3D:C2"; cout << "Point3D: Constructor #2 " << name << endl; }
	~Point3D() { cout << "Point3D: Destructor " << name << endl; }
};

void main()
{
	cout << "1.............................\n";
	Point3D p1;
	cout << "2.............................\n";
	Point3D p2(10);
}