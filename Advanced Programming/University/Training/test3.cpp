#include<iostream>
#include<string>
using namespace std;
class c{
int a; static int b;
public:
void f (int x, int y) { a=x;b=y;}
void g( ) { cout<<a<<b;}
};
int c::b;
main( ){
c ob1,ob2;
ob1.f(1,2);
ob2.f(3,4);
ob1.g( );
ob2.g( );
}
