#include<iostream>
#include "libTemplateSort.h"
using namespace std;

template<class T>
void sort(T array[], int count) {
    T ar[count] = {0};
    int c = 0;
    /*for (int i = 0; i < count; i++) {
        ar[i] = 0;
    }*/

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            if (array[i] > array[j]) {
                c++;
            }
        }
        ar[c] = array[i];
        c = 0;
    }

    for (int i = 0; i < count; i++) {
        if (ar[i] == 0) {
            ar[i] = ar[i - 1];
        }
    }
    for (int i = 0; i < count; i++) {
        array[i] = ar[i];
    }
}

