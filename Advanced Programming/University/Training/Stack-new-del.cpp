#include<iostream>
using namespace std;

class stack{
	private:
		int size,top,*a;
	public:
		stack(int size=10):top(-1) {a=new int[size]; }
		~stack( ){delete[ ] a;}
		void push(const int& item) {a[++top]=item;}
		void pop(int& item) {item=a[top--]; }
};
int main( )
{
	
	int *a;
	a= new int(2);
	cout<<*a;
	delete a;
	
}
