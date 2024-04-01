#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

double Area(double R);
double Area(double R, double H);
// double Area(double R, int H);
// double Area(int R, double H);
// double Area(int R, int H);

// define an inline function that doubles

void DisplayElementFunc(int element) {
    cout << element << ' ';
}

// struct that behave as a unary function
template <typename elementType>
struct DisplayElement {
    void operator () (const elementType element) const {
        cout << element << ' ';
    }
};

// int main() {
//     vector<int> vecintegers;

//     for (int i=0; i<10; i++) {
//         vecintegers.push_back(i);
//     }
//     for_each(vecintegers.begin(), vecintegers.end(), DisplayElementFunc);
//     cout << endl << endl;
//     for_each(vecintegers.begin(), vecintegers.end(), DisplayElement<int>());
//     cout << endl << endl;
//     //Use lamda Function
//     for_each(vecintegers.begin(), vecintegers.end(), [](int element) {cout << element << ' ';});
//     cout << endl << endl;
// }

inline long DoubleNum(int inputNum) {
    return inputNum * 2;
}

double Area(double R) {
    return R*R*3.14;
}

double Area(double R, double H) {
    return R*R*H*3.14;
}

int main() {

    cout << Area(2.0) << endl;    
    cout << Area(2, 1) << endl;    
    cout << DoubleNum(4) << endl;    

    // int n = [](int x, int y) {return x + y;} (5, 4);
    // cout << n << endl;

    // auto f1 = {[] (int x, int y) {return x + y;}};

    // // Assign the same lamda expression to a function object
    // function<int (int, int)> f2 = [] (int x, int y) {return x + y;};

    int i = 3;
    int j = 5;

    function<int (void)> f = [i, &j] {return i + j;};
    auto f1 = [] (int x, int y) {return x + y;};

    cout << f() << '\n';
    i = 22;
    j = 44;

    cout << f() << '\n';
    cout << f1(21, 12) << '\n';

    int m = [](int x) {return [](int y) {return y * 2;} (x) + 3;} (5);
    cout << m << endl;
    return 0;
}