#include <iostream>
#include <string>

using namespace std;

class C {
    public:
        void operator () (string input) const {
            cout << input << '\n';
        }

};

int main() {
    
    C myC;
    myC("Test");
    return 0;
}