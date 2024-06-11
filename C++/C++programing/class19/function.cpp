#include <iostream>

using namespace std;

void S(int&, int&);
void C(int&, int&);
void W(int&, int&);
void G(int&, int&);
void P(int&, int&);

int main() {
    void(*pFunc) (int&, int&);
    const int MAXArray = 5;
    void (*pFuncArray[MAXArray]) (int&, int&);

    pFunc = C;
    int i =1; int j = 2;
    pFunc(i, j);
    pFuncArray[0] = S;
    pFuncArray[1] = C;
    pFuncArray[2] = W;

    pFuncArray[2] = (i, j);
    return 0;
}

void S(int& x, int& y) {
    cout << "S" << '\n';
}
void C(int& x, int& y) {
    cout << "C" << '\n';
}
void W(int& x, int& y) {
    cout << "W" << '\n';
}
void G(int& x, int& y) {
    cout << "G" << '\n';
}
void P(int& x, int& y) {
    cout << "P" << '\n';
}