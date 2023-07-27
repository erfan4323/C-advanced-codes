#include<iostream>

using namespace std;

class TowerHanoi{
    private:
        char mabda;
        char maghsad;
        char komaki;
        int tedad;
    public:
        TowerHanoi(int n, char a, char b, char c) {
            mabda = a;
            maghsad = c;
            komaki = b;
            tedad = n;
        }

        void result(int num, char mab, char magh, char kom) {
            if (num == 1) {
                cout << mab << num << " -> " << magh << num << endl;
                return;
            }

            result(num - 1, mab, kom, magh);
            cout << mab << num << " -> " << magh << num << endl;
            result(num - 1, kom, magh, mab);
        }
        void solve() {
            result(tedad, mabda, maghsad, komaki);
        }
};