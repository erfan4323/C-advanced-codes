#include<iostream>
using namespace std;
class Class {
	private:
	int x;
	public:
	Class(int a) {x=a; } 
	void f( ) { cout<< x << this->x; }
}; 
int main( ){ 
	Class ob(2); 
	ob.f( );
}