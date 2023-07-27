#include <iostream>
#include "hanoiFuncs.h"
using namespace std;

int main() {
    TowerHanoi hanoi(3, 'A', 'B', 'C');
    hanoi.solve();

    return 0;
}
