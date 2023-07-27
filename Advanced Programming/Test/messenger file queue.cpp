#include <bits/stdc++.h>

using namespace std;

typedef struct FileId{
    string profId;
    string type;
    string conId;
    string volByte;
    string getTime;
    string status;
}FileId;

template<class T, int size>
class Queue{
private:
    int front, rear;
    T* arr;

protected:
    bool isFull(){
        return (front == 0 && rear == size - 1);
    }
    
    bool isEmpty(){
        return (front == -1);
    }

public:
    Queue(){
        front = rear = -1;
        arr = new T[size];
    }
    
    T& operator[](int each){
        return arr[each];
    }
    
    void enQueue(T element){
        if (isFull()){
            cout << "Queue is full";
        }else{
            if (front == -1) front = 0;
            rear++;
            arr[rear] = element;
        }
    }
    
    int length(){
        return (rear - front) + 1;
    }
      
    T deQueue(){
        T element;
        if (isEmpty()){
            cout << "Queue is empty";
        }else{
            element = arr[front];
            if (front == rear) front = rear = -1;
            else front++;
        }
        return element;
    }
    
    ~Queue(){
        delete[] arr;
    }
};

template<class U, int size>
class MaxPriorityQueue : public Queue<U, size>{
private:
    using myQueue = Queue<U, size>;
    myQueue queue;
    
public:
    void push(U element){
        queue.enQueue(element);
    }
    
    void pop(){
        queue.deQeueu();
    }
    
    void sort(){
        for (int i = 0; i < queue.length; i++){
            for (int j = 0; j < queue.lenth - i - 1; j++){
                if(queue[j] < queue[j + 1]){
                    U temp;
                    temp = queue[j];
                    queue[j] = queue[j + 1];
                    queue[j + 1] = temp;
                }
            }
        }
    }
};

class File{
private:
    fstream file;
    string data;
    vector<string> result;
    string txtPath = "file handling/ messageData.txt";
    FileId id;
public:
    File(){}
    
    void readFile(string path){
        file.open(path, ios::in);
        string token = "", store = "";
        if (file.is_open()){
            while (getline(file, token)){
                store += token;
                store += "\n"; 
            }
            data = store;
        }
        file.close();
    }
    
    void append(string text, string path){
        file.open(path, ios::app);
        if (file.is_open()){
            file << text << endl;
        }
        file.close();
    }
private:
    vector<string> stringSplit(const string& input, char split){
        vector<string> tokens;
        string token;
        size_t sPos = 0;
        size_t ePos = input.find(split);
        
        while (ePos != string::npos){
            token = input.substr(sPos, ePos);
            tokens.push_back(token);
            sPos = ePos + 1;
            ePos = input.find(split, sPos);
        }
        
        token = input.substr(sPos, ePos);
        tokens.push_back(token);
        
        return tokens;
    }
    
public:
    vector<string> getTextFilesInFolder(const string& path) {
        vector<string> files;
    
        ifstream dirStream(path);
        if (dirStream) {
            string filename;
            while (dirStream >> filename) {
                files.push_back(path + "/" + filename);
            }
    
            dirStream.close();
        }
    
        return files;
    }
    
    void saveString(){
        vector<string> token = stringSplit(data, ',');
        vector<string> result;
        
        for (const string& a : token){
            result.push_back(a);
        }
    }
};

int main(){
    
}


