#include <iostream>

using namespace std;

class Fish {
    public:
        void Swim() {cout << "Fish Swim" << '\n';}
};

class Tuna: public Fish {
    public: 
        void Swim() {cout << "Tuna Swim" << '\n';}
};

void MakeFishSwim(Fish& inputFish) {
    inputFish.Swim();
}

int main() {
    Tuna myDinner;
    myDinner.Swim();
    MakeFishSwim(myDinner);
    return 0;
}