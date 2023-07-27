#include <bits/stdc++.h>
using namespace std;

class Stack{
private:
    //the arr, max, size
    int maxSize = 5, currSize,* stackArr;
    
public:
    //constructor ceates the array and the current size to 0
    Stack(){
        stackArr = new int[maxSize];
        currSize = 0;
    }
    //cheks that the stack is empty
    bool isEmpty(){
        return currSize == 0;
    }
    //cheks that the stack is full
    bool isFull(){
        return currSize == maxSize;
    }
    //add new data
    void push(int value){
        if(isFull()){
            stackArr++;
            currSize++;
            maxSize++;
            stackArr[currSize] = value;
        }else{
            stackArr[currSize] = value;
            currSize++;
        }
    }
    //delete last data
    void pop() {
        if (isEmpty()) {
            cout << "stack is empty" << endl;
        } else {
            currSize--;
        }
    }
    //returns the top of the stack
    auto top(){
        return stackArr[currSize-1];
    }
    //returns the size of the stack
    int size(){
        return currSize;
    }
    //print the stack in LIFO
    void print(){
        cout << "stack values: ";
        for(int i = currSize - 1; i >= 0; i--){
            cout << stackArr[i] << " ";
        }
        cout << endl;
    }
    //destructor deleting array
    ~Stack(){
        delete[] stackArr;
    }
};

int main() {
    //including stack
    Stack stack;
    //adding elements
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    //printing top and size
    cout << "top os stack: " << stack.top() << " and the size: " << stack.size() << endl;
    //print before removing
    stack.print();
    //removing
    stack.pop();
    stack.pop();
    stack.pop();
    //do functions to see if it is working
    stack.print();
    cout << "top os stack: " << stack.top() << " and the size: " << stack.size() << endl;
    //removing untill stack is gone
    stack.pop();
    stack.pop();
    stack.pop();//on this code we expect to see "stack is empty"
}