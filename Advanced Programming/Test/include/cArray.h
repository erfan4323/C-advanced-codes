#ifndef CARRAY_H
#define CARRAY_H

#include <bits/stdc++.h>

template<class T, int Size>
class cArray{
private:
    T arr[Size];
    int index = 0;
    int printIndex = 0;
public:
    T& operator[](int each) {
        return arr[each];
    }
    
    void print(){
        if(printIndex == 0) std::cout << "Array is empty" << std::endl;
        for(int i = 0; i < printIndex; ++i){
            std::cout << arr[i] << ' ';  // Add a space as a separator
        }
    }
    
    void push(T value){
        if(index >= 0 && index < Size){
            arr[index] = value;
            index++;  // Increment the index
            printIndex++;
        }
    }
    
    void reverse(){
        for (int i = 0; i < Size / 2; ++i) {
            int j = Size - 1 - i;
            T temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    T at(int index){
        return arr[index];
    }

    void changeIndex(int Lindex, T value){
        arr[Lindex] = value;
    }

    void fill(T value){
        for(const T& a: arr){
            a = value;
        }
    }
    
    void find(T value){
        int flag = 0;
        for(const T& a: arr){
            if(a == value){
                std::cout << std::endl << "Your value is in the array" << std::endl;
                flag = 1;
            }
        }
        if(flag == 0){
            std::cout << "Undefined data" << std::endl;
        }
    }
    
    int findIndex(T value) {
        for (int i = 0; i < Size; i++) {
            if (arr[i] == value) {
                return i;
            }
        }
        std::cout << "Undefined data" << std::endl;
        return -1;  // Return -1 if value is not found
    }
    
    int length(){
        return index;
    }

    std::vector<T> slice(int start, int finish) {
        std::vector<T> slicedArr;
        for (int i = start; i <= finish; i++) {
            slicedArr.push_back(arr[i]);
        }
        return slicedArr;
    }
    
    void sort() {
        for (int i = 0; i < index - 1; i++) {  // Use index - 1 to avoid accessing out of bounds
            for (int j = 0; j < index - i - 1; j++) {  // Iterate up to index - i - 1
                if (arr[j] > arr[j + 1]) {
                    T temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    void remove(int indexToRemove) {
        if (indexToRemove < 0 || indexToRemove >= index) {
            return;
        }

        for (int i = indexToRemove; i < index - 1; i++) {
            arr[i] = arr[i + 1];
        }

        index--;
    }
    
    void clear(){
        for(T& a: arr){
            a = NULL;
        }
        index = 0;
        printIndex = 0;
    }
    
    bool isEmpty(){
        if(index == 0 && printIndex == 0 && arr = NULL){
            std::cout << "Array is empty" << std::endl;
        }
    }
    
};

#endif