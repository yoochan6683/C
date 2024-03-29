#include <iostream>

using namespace std;

class SimpleCat {
    private:
        int itsAge;
    public:
        // int i = 10;
        SimpleCat();
        ~SimpleCat();
        SimpleCat(SimpleCat&);
        int GetAge() {
            return  itsAge;
        }

        void SetAge(int Age) {
            itsAge = Age;
        }
};

SimpleCat::SimpleCat() {
    cout << "Simple Cat Constructor ..." << endl;
}

SimpleCat::SimpleCat(SimpleCat&) {
    cout << "Simple Cat Copy Constructor ..." << endl;
    // i = 20;
}

SimpleCat::~SimpleCat() {
    cout << "Simple Cat Destructor ..." << endl;
}

SimpleCat FunctionOne(SimpleCat theCat);
// const SimpleCat* const FunctionTwo(SimpleCat *theCat);
const SimpleCat& FunctionTwo(const SimpleCat& theCat);

int main() {
    cout << "Walking a cat ..." << endl;
    SimpleCat Frisky;
    Frisky.SetAge(5);
    cout << Frisky.GetAge();
    cout << "years old" << '\n';

    cout << "Calling FunctionOne ..." << endl;
    FunctionOne(Frisky);
    FunctionTwo(Frisky);
    
    cout << Frisky.GetAge();
    cout << "years old" << '\n';
    return 0;
}

SimpleCat FunctionOne(SimpleCat theCat) {
    cout << "Function One Returning..." << endl;
    return theCat;
};
/*
const SimpleCat* const FunctionTwo(const SimpleCat const *theCat) {
    cout << "Function Two Returning..." << endl;
    // theCat->SetAge(10);
    return theCat;
};
*/

const SimpleCat& FunctionTwo(const SimpleCat& theCat) {
    cout << "Function Two Returning..." << endl;
    // theCat.SetAge(10);
    return theCat;
};