#include <bits/stdc++.h>
using namespace std;

template<typename T>
T add(T x, T y){
    T sum = x + y;
    return sum;
}

template<typename T>
void print(T value){
    cout << value << endl;
}

int main(){
    print(add(1, 4));
    print(add(1.3, 11.4));
    string hi = "hi ", erfan = "erfan";
    print(add(hi, erfan));
    print("Hello");
}