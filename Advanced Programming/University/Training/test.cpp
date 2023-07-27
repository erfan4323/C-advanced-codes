#include<iostream>
#include<string>
using namespace std;
class c{
public:
c( ) { cout<<'a'; }
~c( ) {cout<<'b'; }
};
int main( ){
c a,b;
{ c d; }
cout<<'c';
}