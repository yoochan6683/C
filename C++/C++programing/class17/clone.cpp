#include <iostream>

using namespace std;

class F {
    public:
        virtual F* Clone() = 0;
        virtual void Swim() = 0;
        virtual ~F() {};
};

class T: public F {
    public:
        F* Clone() override {
            return new T(*this);
        }

        void Swim() override final {
            cout << "T swims" << '\n';
        }
};

class B final : public T {
    public:
        F* Clone() override {
            return new B(*this);
        }

        // void Swim() override final {
        //     cout << "B swims" << '\n';
        // } //에러
};

class C final : public F {
    public:
        F* Clone() override {
            return new C(*this);
        }

        void Swim() override final {
            cout << "C swims" << '\n';
        }
};
int main() {

    const int ARRAY_SIZE=4;

    F* myF[ARRAY_SIZE] = {NULL};
    myF[0] = new T();
    myF[1] = new C();
    myF[2] = new B();
    myF[3] = new C();

    F* myNewF[ARRAY_SIZE];
    // Clone
    for(int i=0; i<ARRAY_SIZE; i++) {
        myNewF[i] = myF[i]->Clone();
    }
    for(int i=0; i<ARRAY_SIZE; i++) {
        myNewF[i]->Swim();
    }
    for(int i=0; i<ARRAY_SIZE; i++) {
        delete myF[i];
        delete myNewF[i];
    }

    return 0;
};
