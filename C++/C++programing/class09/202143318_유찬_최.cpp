#include <iostream>
#include <stdio.h>

using namespace std;

class HW3 {
    private:
        int count;

    public:
        HW3() {
            count = 1000;
        }
        HW3 & operator=(const HW3& t) {
            cout << "Run " << count++ << endl;
            return *this;
        }
        HW3(const HW3& t) {
            count = t.count;
            cout << "Run " << ++count << endl;
        }
};

int main() {
    HW3 hw1, hw2;
    hw2 = hw1;
    HW3 hw3 = hw1;

    return 0;
}

/*
    Complete the following codes which generate outcomes as follows:
    You need to add a special member variable and its initialization.
    Additionally, You need to add a special constructor.

    아래의 코드에 Output이 다음과 같이 나오도록 특별한 Constructor 및 멤버 변수와 초기화를 추가하시오.

    Run 1000
    Run 1001
*/