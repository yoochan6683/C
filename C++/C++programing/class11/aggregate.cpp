#include <iostream>

using namespace std;

struct Aggregate1 {
    int num;
    double pi;
};

struct Aggregate2 {
    int num;
    char hello[6];
    int impYears[5];
};

int main() {
    Aggregate1 a1 {2017, 3.14};
    Aggregate2 a2 {42, {'h', 'e'}, {1958, 2003}};
    
    return 0;
}