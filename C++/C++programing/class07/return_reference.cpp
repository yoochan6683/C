#include <iostream>

using namespace std;

int& Getint();

int main() {
    int& rint = Getint();
    cout << rint << '\n';
    return 0;
}

// int& Getint() {
//     int nLocalint = 25;
//     return nLocalint;
// }

int& Getint() {
    int *pInteger = new int(25);
    return *pInteger;
}