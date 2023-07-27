#include<iostream>
using namespace std;

int f (int a) {
	return ++a;
}
char f (char b) {
	return ++b;
}
int main( ){
	cout<<f(1);
	cout<<f('A');
}
