#include <bits/stdc++.h>
using namespace std;

class Queue{
private:
    //the arr, front and rear, size
    const int size = 5;
    int front, rear,* qArr;
    
public:
    //constructor that creats the array and reset the queue by line 22
    Queue(){
        qArr = new int[size];
        front = rear = -1;
    }
    //cheks that the queue is full
    bool isFull(){
        return ((rear + 1) % size) == front;
    }
    //cheks that the queue is empty
    bool isEmpty(){
        return (front == -1);
    }
    //Add an element to the end of the queue
    void enQueue(int value){
        if(isFull()){
            cout << "Queue is full! the element " << value << " can't fit in queue." << endl;
        }else{
            if(front == -1) front = 0;
            rear++;
            qArr[rear] = value;
        }
    }
    //Remove an element from the front of the queue
    int deQueue(){
        int element;
        if(isEmpty()){
            cout << "queue is empty!" << endl;
            return -1;
        }else{
            element = qArr[front];
            if(front == rear){
                front = rear = -1;
            }else{
                front++;
            }
        }
        return element;
    }
    //Get the value of the front of the queue without removing it
    int peak(){
        if(isEmpty()){
            cout << "queue is empty!" << endl;
            return -1;
        }
        return qArr[front];
    }
    //printing the queue in FIFO
    void display(){
        cout << "queue elements : ";
        for(int i = front; i <= rear; i++){
            cout << qArr[i] << " ";
        }
        cout << endl;
    }
    //destructor deleting array
    ~Queue(){
        delete[] qArr;
    }
};

int main(){
    //including queue
    Queue que;
    //adding values in the queue
    que.enQueue(1);
    que.enQueue(2);
    que.enQueue(3);
    que.enQueue(4);
    que.enQueue(5);
    que.enQueue(6); // expect an error , should say it's empty
    //printing queue
    que.display(); 
    //cheking the peak
    cout << "the peak : " << que.peak() << endl;
    //deleting elements
    que.deQueue();
    que.deQueue();
    que.deQueue();
    //chek if removing worked
    que.display();
    cout << "the peak : " << que.peak() << endl;
    //making the queue empty
    que.deQueue();
    que.deQueue();
    que.deQueue();//expecting to print "queue i empty"
    //chek if removing worked
    que.display();
    cout << "the peak : " << que.peak() << endl;
}