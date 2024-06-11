#include <iostream>

using namespace std;

class BaseA {
    public:
        void swim() {}
        //overloading -> same method's name but different parameters
        void swim(bool b) {}
};

class DeriveA: public BaseA {
    public:
        using BaseA::swim;//(2) sol 2 -> unhide swim methods in base class BaseA
        //overriding -> base class tries to hide methods -> (2) error
        //how avoid?...(2)
        void swim() {}
        void swim(bool b) {
            BaseA::swim(b);
        }//(2) sol 3 -> 직접 overriding -> but 두번씩이나 같은 함수를 정의해야 하므로 안에서 BaseA 사용.(안써도 에러는 안남)
};

int main() {

    DeriveA myDeriveA;

    //due to inheritance relationship between base class and derived class
    myDeriveA.swim();
    // myDeriveA.swim(true); //...(2)
    //(2) sol 1 -> 직접 접근
    myDeriveA.BaseA::swim(true);
    return 0;
}

/*
class A {
    int i;
    int j;
};

class SubA: public A {
    int k;
};

//메모리
A
int i
int j
--------
int k
*/