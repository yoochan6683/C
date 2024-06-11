#include <iostream>

using namespace std;

template <typename T>
void DisplayData(const T& data) {
    if constexpr(is_integral<T>::value)
        cout << "Integral data: " << data << '\n';
    else if constexpr(is_floating_point<T>::value)
        cout << "Floating point data: " << data << '\n';
    else
        cout << "Unidentified data: " << data << '\n';

}

int main() {
    DisplayData(12);
    DisplayData("Hello");
    return 0;
}
/*
class Human {
    int age;

    public:
        constexpr Human(int humanAge) : age(humanAge) {}
        constexpr int GetAge() const {return age;}
};

int main() {

    constexpr Human somePerson(15);
    const int hisAge = somePerson.GetAge();
    Human anotherPerson(45);
    return 0;
}
*/