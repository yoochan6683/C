#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

template <typename e>
struct DisplayElement {
    int count;
    void operator() (const e& element) {
        ++count;
        cout << element << ' ';
    }
};

template <typename numberType>
struct isMultiple {
    numberType Divisor;
    isMultiple(const numberType& divisor) {
        Divisor = divisor;
    }
    bool operator() (const numberType& element) const {
        return (element % Divisor) == 0;
    }

};

int main() {
    vector<int> vecI;
    list<char> listC;

    for(int n=0; n<10; n++) {
        vecI.push_back(n);
    }

    for(char c='a'; c<'k'; c++) {
        listC.push_back(c);
    }

    DisplayElement<int> result;

    result = for_each(vecI.begin(), vecI.end(), DisplayElement<int>());
    cout << result.count << "elements were displayed" << '\n';
    for_each(listC.begin(), listC.end(), DisplayElement<char>());

    cout << '\n';
    vector<int> vecIntegers;
    for(int n=25; n<32; n++) {
        vecIntegers.push_back(n);
        cout << n << ' ';
    }

    int Divisor = 4;
    auto iElement = find_if(vecIntegers.begin(), vecIntegers.end(), isMultiple<int>(Divisor));
    if(iElement != vecIntegers.end()) {
        cout << "Find the first element in vector. ";
        cout << *iElement << '\n';
    }
    return 0;
}