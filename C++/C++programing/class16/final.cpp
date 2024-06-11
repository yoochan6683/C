#include <iostream>

using namespace std;

class A /*final -> 에러*/{
    public:
        void Swim() {

        }
};

class B: public A {
    public:
        void Swim() override final {}
};

class C: public B {
    public:
        void Swim() override {}
};

int main() {

    return 0;
}