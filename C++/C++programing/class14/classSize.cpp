#include <iostream>

using namespace std;

class A {
    public:
        char n;
        int i;//padding -> char pad pad pad | int int int int | char pad pad pad -> size = 12
        char a;

        A() {
            printf("address: %p\n", &n);
            printf("address: %p\n", &i);
            printf("address: %p\n", &a);
        }
        void f() {}//size에 포함 x
};

class DerivedA: public A {
    public:
        int j;
        DerivedA() {
            printf("address: %p\n", &j);
        }
        void m2() {}
};

int main() {

    DerivedA myA;
    cout << sizeof(myA) << '\n';

    // DerivedA *pMyA = new DerivedA();//16(12 + 4)
    // cout << sizeof(pMyA) << '\n';//8
    return 0;
}

/*
you guys want to know the location of methods -> function pointers

void m1() {

}

int main() {

}
//Compiler knows m1 and binding m1() at compile time: static binding
//Dynamic Binding -> Run time -> function pointer -> virtual(c++ 식)
*/