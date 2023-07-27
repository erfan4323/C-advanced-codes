#include<iostream>
using namespace std;

class c1{
	public:
		virtual void f( )=0;
};
class c2 : public c1{
	public: 
		void f( ) {cout<<'H'; }
};
main( ){ 
	c1 ob1;
	c2 ob2;
	ob2.f( );
}
