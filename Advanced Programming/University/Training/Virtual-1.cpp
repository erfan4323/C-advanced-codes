#include <iostream> 
using namespace std;

class Base {
public:
	        void m1() { cout << "Base: m1() \n"; }
	virtual void m2() { cout << "Base: m2() \n"; }
};

class Derived : public Base {
public:
			void m1() { cout << "Derived m1() \n"; }
			void m2() { cout << "Derived m1() \n"; }
};

void f1(Base obj) {
	obj.m1();
	obj.m2();
}

void f2(Base &obj) {
	obj.m1();
	obj.m2();
}

void f3(Base *obj) {
	obj->m1();
	obj->m2();
}

int main()
{
	cout << "[1]...................." << endl;
	Base b;
	b.m1();
	b.m2();

	cout << "[2]...................." << endl;
	Derived d;
	d.m1();
	d.m2();

	cout << "[3]...................." << endl;
	Base o1;
	// up casting
	o1 = d;
	o1.m1();
	o1.m2();

	cout << "[4]...................." << endl;
	Base *p;
	// up casting
	p = &d;
	p->m1();
	p->m2();

	cout << "[5]...................." << endl;
	f1(d);
	
	cout << "[6]...................." << endl;
	f2(d);
	
	cout << "[7]...................." << endl;
	f3(&d);

}