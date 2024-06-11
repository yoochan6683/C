#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    deque <int> deqIntegers;
    deqIntegers.push_back(3);
    deqIntegers.push_back(4);
    deqIntegers.push_back(5);

    for(size_t i=0; i<deqIntegers.size(); ++i) {
        cout << "E[" << i << "]";
        cout << deqIntegers[i] << '\n';
    }
    cout << '\n';

    deqIntegers.push_front(2);
    deqIntegers.push_front(1);
    deqIntegers.push_front(0);

    for(size_t i=0; i<deqIntegers.size(); ++i) {
        cout << "E[" << i << "]";
        cout << deqIntegers[i] << '\n';
    }
    cout << '\n';

    for(auto iE = vecInput.cbegin(); iE != vecInput.cend(); ++iE) {
        size_t offset = distance(deqIntegers.begin(), iE);
        cout << "E[" << offset << "]= ";
        cout << deqIntegers[offset] << '\n';
    }

    for(int& x : deqIntegers) {
        cout << x << '\n';
    }

    return 0;
}