#include <iostream>
#include <string>

using namespace std;

class MyString {
    private:
        char* Buffer;
    
    public:
        MyString(const char* initialInput) {
            cout << "Constructor creating new MyString " << '\n';
            if (initialInput != NULL) {
                Buffer = new char[strlen(initialInput) + 1];
                strcpy(Buffer, initialInput);
                cout << "Buffer points to: " << hex;
                cout << (unsigned int*)Buffer << '\n';
            } else {
                Buffer = NULL;
            }
        }

        MyString(const MyString& CopySource) {
            cout << "Copy Constructor is called ..." << '\n';
            if (CopySource.Buffer != NULL) {
                Buffer = new char [strlen(CopySource.Buffer) + 1];
                strcpy(Buffer, CopySource.Buffer);
                cout << "Buffer points to: " << hex;
                cout << (unsigned int*)Buffer << '\n';
            }
        }

        ~MyString() {
            cout << "Invoking destructor. clearing up" << '\n';
            if (Buffer != NULL) {
                delete [] Buffer;
            }
        }
        int GetLength() {
            return strlen(Buffer);
        }
        const char* GetString() {
            return Buffer;
        }
};

void useMyString(MyString input) {
    cout << "String buffer in MyString: " << input.GetString() << '\n';
    return;
}

int main() {
    MyString SayHello("Hello from MyString class");
    cout << "Length: " << SayHello.GetLength() << '\n';
    cout << "Message: " << SayHello.GetString() << '\n';
    useMyString(SayHello);
    return 0;
}