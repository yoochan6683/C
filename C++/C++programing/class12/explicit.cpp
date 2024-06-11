#include <iostream>

using namespace std;

class A {
    public:
        int age;
        int height;

        A() {cout << "Default A is Created" << '\n';}
        explicit A(int myAge) {
            age = myAge;
            cout << "A is Created" << '\n';
        }
};

int main() {

    // A myA = 11; -> 에러: explicit은 전부 다 설정해줘야 함
    A myA2;

    // cout << myA.age << '\n';

    // myA2 = 12; -> 에러
    cout << myA2.age << '\n';

    return 0;
}