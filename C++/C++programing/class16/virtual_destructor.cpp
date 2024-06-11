#include <iostream>

using namespace std;

class F {
    public:
        F() {cout << "Constructed F" << '\n';}
        virtual ~F() {cout << "Destructed F" << '\n';} // sol 1
        // Destructor of Base class -> needs to be declared as 'virtual'
};

class T: public F {
    public:
        T() {cout << "Constructed T" << '\n';}
        ~T() {cout << "Destructed T" << '\n';}
};

void DeleteFMemory(F* pF) {
    delete pF;
}

int main() {
    T* pT = new T;//1. constructs F -> 2. constructs T(still alive) -> 3.Delete F => T는 살아있고 F가 죽음...문제 1
    cout << "Deleting T..." << '\n';
    DeleteFMemory(pT);

    // T myT;//create an Instance

    return 0;
}

/*
    constructor T -> Derived T
    constructor F -> Derived F
    => Behaves like stack
*/