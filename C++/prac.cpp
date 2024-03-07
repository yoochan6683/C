#include <iostream>
#include <string>

using namespace std;

class Human {
    private:
        string name;
        int age;
    public:
        void setName(string enteredName) {
            name = enteredName;
        }

        void setAge(int enteredAge) {
            age = enteredAge;
        }

        int getAge() {
            return age;
        }

        string getName() {
            return name;
        }
};

int main() {
    Human Tom;
    Tom.setAge(24);
    Tom.setName("Tom");

    cout << "Name: " << Tom.getName() << "\n Age: " << Tom.getAge() << endl;
    return 0;
}