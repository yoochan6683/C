#include <iostream>

using namespace std;

class A {
    public:
        int i;
};

class subA: public A {
    public:
        int j;
};

int main() {

    subA mysubA;
    A myA = mysubA; //type conversion
    myA.i = 0;
    // myA.j = 1; // error
    /*
        A yourA;
        subA yourSubA = yourA; // error
    */
    return 0;
}

/*
    **Derived class can be converted into base class**
    derived -> base: yes!!
    base -> derived: No!!!
*/