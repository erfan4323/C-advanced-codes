#include<iostream>
#include "templateSortFuncs.h"
using namespace std;

int main() {
    char a[10] = {'a', 'f', 's', 'b','d','a','b','d','e','r'};
    for (int i = 0; i < 10; i++) {
        cout << a[i] << " - ";
    }
    cout << endl;
    sort(a, 10);
    for (int i = 0; i < 10; i++) {
        cout << a[i] << " - ";
    }
    return 0;
}

