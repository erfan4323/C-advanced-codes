#include <bits/stdc++.h>

using namespace std;

class txtFile{
private:
    ofstream write;
    ifstream read;
    const char* textPath = "file handling/classFiles.txt";
public:
    txtFile(){
        write.open(textPath);
        write.open(textPath, ios::app);
        if(!write.is_open()){
            cout << "file dod not opened for writing" << endl;
        }
        read.open(textPath);
        if(!read.is_open()){
            cout << "file dod not opened for reading" << endl;
        }
    }
    
    void writeFile(const string& text){
        if(write.is_open()){
            write << text << endl;
            cout << "we overwrited the text file with the text \"" << text << "\"" << endl;
        }else{
            cout << "error writing from file" << endl;
        }
    }
    
    void readFile(const int& turn){
        if(read.is_open()){
            string store = "", temp = "";
            for(int i = 0; i < turn; i++){
                read >> temp;
                store += temp + " ";
            }
            cout << "from the " << turn << "th time you want to see from your file is : " << store << endl;
        }else{
            cout << "error reading from file" << endl;
        }
    }

    void appendFile(const string& text){
        //write.open(textPath, ios::app);
        if(write.is_open()){
            write << text << endl;
            cout << "the text appended with the text : " << text << endl;
        }else{
            cout << "error writing from file" << endl;
        }
    }
    
    void readAllFile(){
        if(read.is_open()){
            string store = "", temp = "";
            while(getline(read, temp)){
                store += temp;
                store += "\n";
            }
            cout << "your file data is : " << store << endl;
        }else{
            cout << "error reading from file" << endl;
        }
    }
    
    ~txtFile(){
        if(write.is_open()){
            write.close();
        }
        if(read.is_open()){
            read.close();
        }
    }
};

int main(){
    txtFile file;
    file.writeFile("Hi, my name is carlos");
    file.appendFile("and i welcome you");
    //file.readFile(2);
    file.readAllFile();
}