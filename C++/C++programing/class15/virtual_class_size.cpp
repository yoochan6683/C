#include <iostream>

using namespace std;

class A {
    public:
        char n;
        int a;
        char c;
        virtual void m1() {}
};

class subA: public A {
    public:
        int k;

        // virtual void m2() {}//size를 늘리지 않음 -> 부모 copy
};

int main() {
    A myA;
    subA mySubA;
    cout << sizeof(myA) << '\n';    
    cout << sizeof(mySubA) << '\n';    
    return 0;
}

/*
    // 메모리
    ------------------------------
    virtual Function table address  -> 8
    ------------------------------
    n                               -> 4
    ------------------------------
    a                               -> 4
    ------------------------------
    c                               -> 4
    ------------------------------
*/