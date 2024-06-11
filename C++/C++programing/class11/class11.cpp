#include <iostream>

using namespace std;

class Human {
    public:
        int age;

    public:
        explicit Human(int HumanAge) : age(HumanAge) {

        }
};

void DoSomething(Human person) {
    cout << "Human sent did something" << '\n';
}

int main() {
/*
    Human anotherKid = 11; -> explicit이 없으면 가능한 방식
    cout << anotherKid.age << '\n';
    DoSomething(10); -> explicit이 없으면 가능한 방식 (아니면 에러)
*/
    Human kid(10);
    return 0;
}