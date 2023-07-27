#include<iostream>
using namespace std;

class Base{
public:
	void m0() {cout<<"Base: m0()\n";}
	virtual void m1() {cout<<"Base: m1()\n";}
	void m2() {cout<<"Base: m2()\n";}
};

class Derived : public Base{
public:
	void m1() {cout<<"Derived: m1()\n";}
	void m2() {cout<<"Derived: m2()\n";}
	void m3() {cout<<"Derived: m3()\n";}
};
void main()
{
	cout<<"[1]..................\n";
	Base b;
	b.m1();
	cout<<"[2]..................\n";
	Derived d;
	d.m1();
	cout<<"[3]..................\n";
	Base *o1;
	o1 = &d;
	o1->m1();
	o1->m2();
	//o1.m3(); Error: 


}