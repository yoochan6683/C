#include <iostream>

using namespace std;

class Human {
    private:
        int Age;
        string Name;
    
        friend void DisplayAge(const Human& Person);
        friend class Utility;
    public:
        Human(string inputName, int inputAge) {
            Name = inputName;
            Age = inputAge;
        }
};

class Utility {
    public:
        static void DisplayAge(const Human& Person) {
            cout << Person.Age << '\n';
        }
};

void DisplayAge(const Human& Person) {
    cout << Person.Age << '\n';
}

int main() {
    Human Tom("Tom", 25);
    DisplayAge(Tom);
    Utility::DisplayAge(Tom);
    return 0;
}