#include <iostream>
#include <stdio.h>

using namespace std;

class HW3 {
    public:
        HW3() {}
        HW3 & operator=(const HW3& t) {
            cout << "Run" << count++ << endl;
            return *this;
        }
};

int main() {
    HW3 hw1, hw2;
    hw2 = hw1;
    HW3 hw3 = hw1;

    return 0;
}