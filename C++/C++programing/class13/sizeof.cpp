#include <iostream>

using namespace std;

class MyString {
    private: 
        char *Buffer;
        int length;
};

class Human {
    private:
        int Age;
        bool Gender;
        MyString MyString;
    
    public:
        Human() {
            cout << "Constructor is called" << '\n';
        }
};
int main() {
    Human Tom;
    cout << sizeof(Human) << '\n';    
    cout << sizeof(MyString) << '\n';    
    cout << sizeof(Tom) << '\n';    
    return 0;
}