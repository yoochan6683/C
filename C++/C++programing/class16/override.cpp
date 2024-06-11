#include <iostream>

using namespace std;

class F {
    public:
        virtual void Swim() {cout << "F Swims" << '\n';}
};

class T: public F {
    void Swim() /*const -> 에러*/ override {cout << "T Swims" << '\n';}
    //void Swim() {}
    //void Swim() const {}
    // -> 완전히 다른 함수
    void Swim() const {cout << "T Swims" << '\n';} // 가능 -> override x(그냥 다른 함수를 선언한 것)
};


int main() {

    return 0;
}