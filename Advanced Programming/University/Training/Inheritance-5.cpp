#include<iostream>
using namespace std;

class A{
	int y;
protected:
	int x;
public:
	A(){ x = 1; cout<<"CA"<< endl;}
	~A(){ cout<<"DA"<< endl;}
	void print(){cout << "A: x = "<< x << endl; }
};
class B: protected A{ //private A{
public:
	int k;
	B(int i){  x = i; cout<<"CB: x = "<< x << endl;}
	~B(){ cout<<"DB"<< endl;}
	void print(){cout << "B: x = "<< x << endl; }
};

class C: public B{
public:
	B b;
	C():B(5), b(10){  cout<<"CC"<< endl;}
	~C(){ cout<<"DC"<< endl;}
	int x;
	//void print(){cout << "C: x = "<< x << endl; }
};
void main()
{
	C c;
	c.x = 8;
	c.print();

	//B b;
	//b.print();

}
