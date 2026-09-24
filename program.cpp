#include <iostream>
using namespace std;

int TinhHieu(int a, int b) {
    return a - b;
}

int main() {
    cout << "Chuong trinh tinh toan nhom" << endl;
    cout << "Hieu 10 - 4 = " << TinhHieu(10, 4) << endl;
    return 0;
}