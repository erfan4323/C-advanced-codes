#include <bits/stdc++.h>

using namespace std;

class convert{
private:
    
    int dec = 0, answer[32] = {0}, base;
    string hex;
    long long input;
    
public:
    
    void get_num(){
        cout << "enter the base: ";
        cin >> base;
        if(base != 16){
            cout << "enter the number: ";
            cin >> input;
        }else{
            cout << "enter the HEX: ";
            cin >> hex;
        }
    }
    
    void base_to_decimal(){
        int i = 0;
        if(base != 16){
            while(input != 0){
                int digit = input % 10;
                dec += digit * pow(base, i);
                i++;
                input = input / 10;
            }
            cout << dec;
        }else if(base == 10){
            dec = input;
            cout << dec;
        }else{
            for (int i = 0; i < hex.size(); i++) {
                int digit;
                if (hex[i] >= '0' && hex[i] <= '9') {
                    digit = hex[i] - '0';
                } else if (hex[i] >= 'a' && hex[i] <= 'f') {
                    digit = hex[i] - 'a' + 10;
                } else if (hex[i] >= 'A' && hex[i] <= 'F') {
                    digit = hex[i] - 'A' + 10;
                }
                dec += digit * pow(16, hex.size() - i - 1);
            }
            cout << dec;
        }
        
    }
    
    void dec_to_base(){
        cout << "\nenter the base you wanna see: ";
        cin >> base;
        int i = 0; 
        if(base != 16){
            while (dec != 0) {
                answer[i] = dec % base;
                dec = dec / base;
                i++;
            }
        }else{
            while (dec != 0) {
                int remainder = dec % 16;
                if (remainder < 10) {
                    hex[i] = remainder + 48;
                }else {
                    hex[i] = remainder + 55;
                }
                i++;
                dec = dec / 16;
            }
        }
    }
    
    void show(){
        for(const auto& a : answer){
            if(a != 0){
                cout << a;
            }
        }
    }
    
};

int main(){
    convert con;
    con.get_num();
    con.base_to_decimal();
    con.dec_to_base();
    con.show();
    
}