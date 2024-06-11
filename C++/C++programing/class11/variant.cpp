#include <iostream>

using namespace std;

int main() {
    variant<int, double> varSafe;
    varSafe = 2;

    try {
        int pi = get <int> (varSafe);
    } catch(const bad_variant_access& e) {
        cout << e.what() << '\n';
        cout << "Try to access int ..." << '\n';
    }

    try {
        double pi = get <double> (varSafe);
    } catch(const bad_variant_access& e) {
        cout << e.what() << '\n';
        cout << "Try to access double ..." << '\n';
    }
    return 0;
}