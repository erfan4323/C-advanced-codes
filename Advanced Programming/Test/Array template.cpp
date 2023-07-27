#include "include/cArray.h"

using namespace std;

int main(){
    cArray<int, 5> arr1;
    arr1.push(1);
    arr1.push(2);
    arr1.push(3);
    arr1.changeIndex(2, 4);
    arr1[1] = 7;
    arr1.print();
}