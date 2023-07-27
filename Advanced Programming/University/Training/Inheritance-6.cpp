class Base{
public:
	int x;
	Base() {cout<<"Base: CA\n";}
	~Base() {cout<<"Base: DA\n";}
	Base(int i) {x = i; cout<<"Base: CA\n"; cout<< x <<endl;}
	void m1() {cout<<"Base: m1()\n";}
	void m2() {cout<<"Base: m1()\n";}
};

class Derived : public Base{
public:
	int x;
	Base b1, b2;
	~Derived(){cout<<"Derived: DA \n";}
	Derived(): b2(5), Base(10){cout<<"Derived: CA \n";}
	Derived(int j): b2(j+2){cout<<"Derived: CA \n";}
	void m1() {cout<<"Derived: m1()\n";}
	void m2() {cout<<"Derived: m1()\n";}
};
void main()
{
	Derived d;

}