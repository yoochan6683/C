#include <iostream>

using namespace std;

class Human {
    public:
        int Age;
        string Name;
        string DateOfBirth;
    public:
        Human(int myAge) {
            Age = myAge;
            cout << "Constructor is called!" << endl;
        }
        Human() {
            Age = 10;
            cout << "Constructor is called!" << endl;
        }
        ~Human() {
            cout << "Destructor is called!" << endl;
        }
        void Talk(string TextToTalk) {
            cout << TextToTalk << endl;
        }
        void introduce() {
            cout << "Age: " << Age << endl;
            cout << "Name: " << Name << endl;
        }
};

int main() {
    Human Tom(25);  

    Tom.Name = "Tom Cruise";
    Tom.introduce();

    Human *Jenny =  new Human();
    (*Jenny).Age = 24;
    (*Jenny).Name = "Jenny";
    (*Jenny).introduce();
    Jenny -> introduce();

    delete Jenny;
    return 0;
}

/*
    function overloading -> Human() vs Human(25) -> 함수 이름이 같아도 파라미터를 보고 알아서 맞는걸 호출해줌
             overriding
*/