#include <iostream>

using namespace std;

class BaseA {
    public:
        bool b;
        //(1) sol 1: 기본 생성자 선언
        // BaseA() {}
        //when its constructor is overloaded...(1)
        BaseA(bool isb): b(isb) {}
};

//default BaseA() is gone -> how can we do to avoid this problem?...(1)
class DeriveA : public BaseA {
    public:
        //(1) sol 2: 자식에서 default constructor 설정
        //*그냥 Derive A() {}로 할려면 그냥 BaseA() {} 생성자가 있어야 함
        DeriveA(): BaseA(true) {}
};

int main() {

    DeriveA myDeriveA;
    return 0;
}