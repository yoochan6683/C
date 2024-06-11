#include <iostream>

using namespace std;

class A {
    public:
        int Age;
        A() {cout << "A constructor" << '\n';}
};

class B: public virtual A {
    // public:
    //     B() {cout << "B constructor" << '\n';}
};

class C: public virtual A {
    // public:
    //     C() {cout << "C constructor" << '\n';}
};

class D: public virtual A {
    // public:
    //     D() {cout << "D constructor" << '\n';}
};

class BCD: public B, public C, public D {
    public:
        BCD() {cout << "BCD constructor" << '\n';}
};

int main() {
    BCD myBCD;
    myBCD.Age = 10;
    return 0;
}

/*
    Do not make Multiple Inheritance relationship in your o_o project
*/