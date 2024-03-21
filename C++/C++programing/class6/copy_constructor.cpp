#include <iostream>

using namespace std;

class SimpleCat {
    public:
        SimpleCat();
        ~SimpleCat();
        SimpleCat(SimpleCat&);
};

SimpleCat::SimpleCat() {
    cout << "Simple Cat Constructor ..." << endl;
}

SimpleCat::SimpleCat(SimpleCat&) {
    cout << "Simple Cat Copy Constructor ..." << endl;
}

SimpleCat::~SimpleCat() {
    cout << "Simple Cat Destructor ..." << endl;
}

SimpleCat FunctionOne(SimpleCat theCat);
SimpleCat* FunctionTwo(SimpleCat *theCat);

int main() {
    cout << "Walking a cat ..." << endl;
    SimpleCat Frisky;
    cout << "Calling FunctionOne ..." << endl;
    FunctionOne(Frisky);
    return 0;
}

SimpleCat FunctionOne(SimpleCat theCat) {
    cout << "Function One Returning..." << endl;
    return theCat;
};

SimpleCat* FunctionTwo(SimpleCat *theCat) {
    cout << "Function Two Returning..." << endl;
    return theCat;
};