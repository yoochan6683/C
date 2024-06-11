#include <iostream>

using namespace std;

class Base {

};

class Derived : public Base {

};

class CUnRelated {

};

class F {
    public:
        virtual void Swim() {cout << "F swims in water" << '\n';}
};

class T: public F {
    public:
        void Swim() {cout << "T swims in water" << '\n';}
        void BecomeDinner() {cout << "Dinner in Sushi" << '\n';}
};

class C: public F {
    public:
        void Swim() {cout << "C swims in water" << '\n';}
        void Talk() {cout << "Talk" << '\n';}
};

void DetectFishType(F* inputFish) {
    T* pisT = dynamic_cast<T*>(inputFish);
    if(pisT) {
        cout << "Detected T" << '\n';
        pisT->BecomeDinner();
    }
    C* pisC = dynamic_cast<C*>(inputFish);
    if(pisC) {
        cout << "Detected C" << '\n';
        pisC->Talk();
    }
}

class SomeClass {
    public:
        int i;
        void DisplayMembers() {cout << i << '\n';}
};

void DisplayAiData(const SomeClass& mData) {
    // mData.DisplayMembers();
    SomeClass& refData = const_cast<SomeClass&>(mData);
    refData.DisplayMembers();
}

void DisplayAiData2(const SomeClass* mData) {
    // mData.DisplayMembers();
    SomeClass* refData = const_cast<SomeClass*>(mData);
    refData->DisplayMembers();
}

int main() {

    char *pS = "Hello World";
    int *pB = (int*)pS;

    Base *pBase = new Derived(); // Derived -> Base: OK
    // Derived* pDerived = pBase; // Base -> Derived: Not OK
    Derived* pDerived = static_cast<Derived*>(pBase); // Need type case at compile time why? we got an error at compile time!!
    // Try to C_Style TypeCast
    Derived* pDerived2 = (Derived*)pBase; //C_Style cast is still OK.
    // CUnRelated* pUnrelated = pBase;
    // CUnRelated* pUnrelated = static_cast<CUnRelated*>(pBase); //error: 다른 클래스라서 안됨
    CUnRelated* pUnrelated = reinterpret_cast<CUnRelated*>(pBase); // not recommended.

    double dPi = 3.14159265;
    int Num = dPi; // OK. implicitly by compilter(automatically)
    int Num2 = static_cast<int>(dPi);

    C myLunch;
    T myDinner;

    DetectFishType(&myDinner);
    DetectFishType(&myLunch);

    F* pF = new F();
    // char* pBytes = pF;
    char* pBytes = (char *)pF;
    char* pBytes2 = reinterpret_cast<char *>(pF);

    return 0;
}