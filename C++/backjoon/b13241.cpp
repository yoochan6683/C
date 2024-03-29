// https://www.acmicpc.net/problem/13241
#include <iostream>

using namespace std;

int main() {
    long long int a, b, larger, smaller, multiple;
    cin >> a >> b;

    if (a >= b) {
        larger = a;
        smaller = b;
    } else {
        larger = b;
        smaller = a;
    }

    multiple = larger;

    while (1)
    {
        if (multiple % smaller == 0) break;
        multiple += larger;
    }

    cout << multiple << '\n';
    
    return 0;
}