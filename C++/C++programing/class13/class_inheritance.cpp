#include <iostream>

using namespace std;

class Fish {
    protected:
        bool FreshWaterFish;

    public:
        // Constructor
        Fish(bool isFreshwater) : FreshWaterFish(isFreshwater) {}

        void swim(bool FreshWaterFish) {
            if (FreshWaterFish)
                cout << "Swims in lake" << '\n';
            else
                cout << "Swims in sea" << '\n';
        }
};

class Tuna : public Fish {
    public:
        using Fish::swim;

        Tuna() : Fish(false) {}

        void swim(bool FreshWaterFish) {
            // Fish::swim();
            Fish::swim(FreshWaterFish);
            cout << "Tuna swims real fast" << '\n';
        }
};

class Carp : public Fish {
    public:
        Carp() : Fish(true) {}
    
        void swim() {
            // Fish::swim();
            cout << "Carp swims real slow" << '\n';
        }
};

int main() {

    Carp myLunch;
    Tuna myDinner;

    // myLunch.swim();
    // myDinner.swim();
    // myDinner.Fish::swim();
    // myDinner.swim(false);
    myDinner.swim(false);
    return 0;
}