#include <iostream>

using namespace std;

class FishDummyMenber {
    public:
        FishDummyMenber() {
            cout << "FishDummyMenber constructor" << '\n';
        }
        ~FishDummyMenber() {
            cout << "FishDummyMember destructor" << '\n';
        }
};

class Fish {
    protected:
        FishDummyMenber dummy;
    public:
        Fish() {
            cout << "Fish constructor" << '\n';
        }
        ~Fish() {
            cout << "Fish destructor" << '\n';
        }

};

int main() {

    Fish myFish;
    return 0;//remove the main()'s stack(Local variable) -> start destructing the myFish!!
}

/*
**Order of Construction and Destruction
Fish has a FishDummyMember 
    -> To construct a Fish, -> we first create FishDummyMember
    -> To destruct a Fish -> we first destruct FishDummyMember
*/