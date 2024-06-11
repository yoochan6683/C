#include <iostream>

using namespace std;

class ABC {
    public:
        virtual void DoSomething() = 0;
};

class Derived: public ABC {
    public:
        void DoSomething() {
            cout << "[Derived] Pure Virtual Function ..." << '\n';
        }
};

class Derived2: public ABC {
    public:
        void DoSomething() {
            cout << "[Derived2] Pure Virtual Function ..." << '\n';
        }
};

void MakeDoSomething(ABC& inputABC) {
    inputABC.DoSomething();
}

int main() {
    // ABC myABC; //에러: abstract class에서 instance를 만들 수 없음
    Derived D;
    Derived2 D2;
    D.DoSomething();
    D2.DoSomething();

    MakeDoSomething(D);
    MakeDoSomething(D2);

    return 0;
}

/*
    Create D: we need to create an ABC
    ABC VFT -> D VFT -> DoSomthing()

    "Example of polymorphism"
*/