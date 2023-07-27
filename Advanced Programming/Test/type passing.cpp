#include <bits/stdc++.h>

using namespace std;


template<typename T>
void printType(){
	if (is_same<T, string>::value)
	{
		cout << "type: string" << endl;	
		return;
	}
	cout << "type: " << typeid(T).name() << endl;
}


int main(int argc, char const *argv[])
{
	
	printType<string>();

	return 0;
}