#include <iostream>

using namespace std;

class Simple {
    public:
        int i = 10;

        void Seti(int i) {
            // i = i; 에러
            this->i = i;
        }
};

int main() {
    Simple S;

    S.Seti(11);
    cout << S.i << '\n';
    return 0;
}