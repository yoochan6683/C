#include <iostream>
#include <string>

using namespace std;

class MyString {
    public:
        string Buffer;
    
    public:
        MyString(const char* initialInput) {
            cout << "Constructor creating new MyString " << '\n';
            Buffer = initialInput;

            cout << "Buffer points to: " << (void*)&Buffer[0] << '\n';
        }

        ~MyString() {
            cout << "Invoking destructor. clearing up" << '\n';
        }
};

void useMyString(MyString input) {

    cout << "String buffer in MyString: " << (void*)&input.Buffer[0] << '\n';
    cout << "Buffer contains " << input.Buffer.c_str() << '\n';

    return;
}

int main() {
    MyString SayHello("Hello from MyString class");
    useMyString(SayHello);
    return 0;
}

// Do not Just do it
// string 많이 쓸것
