#include <iostream>
#include <string>

using namespace std;

class Human {
    private:
        int Age;
        string Name;

    public:
        Human() {
        }

        Human(int HumanAge) {
            Age = HumanAge;
        }
        
        Human(string HumanName, int HumanAge = 24) {
            Name = HumanName;
            Age = HumanAge;
        }

        int getAge() {
            return Age;
        }

        string getName() {
            return Name;
        }
        
        ~Human() {
            cout << "Destructor is called ..." << '\n';
        }
};

int main() {
    Human Eve(21);
    Human Tom;
    Human Ive("Ive", 21);
    Human Twix("Twix");
    // Human Twix("Twix", 20) => 24가 아닌 20으로 됨

    cout << Twix.getName() << '\n';
    cout << Twix.getAge() << '\n';

    return 0;
}