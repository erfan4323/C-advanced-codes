#include <bits/stdc++.h>

using namespace std;

string textFile = "file handling/mytext.txt";

void simple_write(){
    ofstream file;
    file.open(textFile);
    if(file.is_open()){
        file << "there is my first text" << endl;
        file << "there is my second text" << endl;
    }else{
        cout << "file did not opened" << endl;
    }
    file.close();
}

void simple_read(){
    ifstream file;
    file.open(textFile);
    string extracted = "";
    if(file.is_open()){
        file >> extracted;
    }else{
        cout << "file did not opened" << endl;
    }
    file.close();
    cout << "i read thid from file : " <<   extracted << endl;
}

void simple_append(){
    ofstream file;
    file.open(textFile, ios::app);
    if(file.is_open()){
        file << "appending the text" << endl;
    }else{
        cout << "file did not opened" << endl;
    }
    file.close();
}

void simple_read_all(){
    ifstream file;
    file.open(textFile);
    
    string temp = "", store = "";
    
    if(file.is_open()){
        while(getline(file, temp)){
            store += temp;
            store += "\n";
        }
    }else{
        cout << "file did not opened" << endl;
    }
    file.close();
    cout << store << endl;
}

int main(){
    string menu[6] = {"0) please choose your file operation",
                      "1) write to file"                    ,
                      "2) read to file"                     ,
                      "3) append to file"                   ,
                      "4) read all to file"                 ,
                      "5) Exit"                             };
    
    while(true){
        int response = 0;
        system("cls");
        
        for(const string& a: menu){
            cout << a << endl;
        }
        
        cin >> response;
        
        switch(response){
        case 1:
            simple_write();
            _sleep(1000);
            break;
        case 2:
            simple_read();
            _sleep(1000);
            break;
        case 3:
            simple_append();
            _sleep(1000);
            break;
        case 4:
            simple_read_all();
            _sleep(3000);
            break;
        case 5:
            cout << "bye!";
            exit(1);
            break;
        default:
            cout << "undefined choice" << endl;
            _sleep(2000);
            break;
        }
    }
}