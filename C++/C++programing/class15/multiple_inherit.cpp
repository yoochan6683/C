#include <iostream>

using namespace std;

class M {
    public:
        void m1() {cout << "m1" << '\n';}
};

class R {
    public:
        void r1() {cout << "r1" << '\n';}
};

class B {
    public:
        void b1() {cout << "b1" << '\n';}
};

class P: public M, public R, public B {
    public:
        void p1() {cout << "p1" << '\n';}
};
int main() {

    P Plalypus;
    Plalypus.b1();
    Plalypus.r1();
    return 0;
}

/*
    Java -> Object-Oriented Language
        -> does not allow multiple inheritance
        -> Only allows Single inheritance
*/