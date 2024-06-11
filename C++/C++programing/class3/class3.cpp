#include <iostream>

using namespace std;

class Remote {
    public:
        void foo() {

        }
};

//AIRemote is a Remote
//: <- 이 기호가 "is a"에 해당
class AIRemote : public Remote{

};

//TV has a Remote
class TV {
    private:
        Remote myRemote;
    public:
        void bar() {
            myRemote.foo();
        }
};

int main() {
    AIRemote myA;

    return 0;
}

/*
    private, protected, public -> Access Modifiers
    private은 해당 객체 내에서, protected는 inheritance 관계 내에서만 사용 가능, public은 모든 접근 허용
    
*/