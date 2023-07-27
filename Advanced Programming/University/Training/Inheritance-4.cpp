#include<iostream>
using namespace std;

class A {
private:
	int x;
public:
	A(int i=1) { x = i + 1; cout << "CA" << endl; print(); }
	~A() { cout << "DA" << endl;  print(); }
	void print(void) { cout << "A: x = " << x << endl; }
	void setX(int i) { x = i + 2; }
};

class B : public A {
private:
	int x;
	A a1, a2;
public:
	void setX(int i) { x = i + 5; }
	B(int i) : a2(i + 2), A(i * 2), a1(i) {
		x = i;
		cout << "CB" << endl;
		a2.print();
	}
	B() : A(1), a1(2) {
		x = 0;
		cout << "CB" << endl;
		a1.print();
	}
	~B() { cout << "DB" << endl; }
	void print(void) { cout << "B: x = " << x << endl; }
};

void main(void)
{
	A a;
	B o1(5), o2;
}