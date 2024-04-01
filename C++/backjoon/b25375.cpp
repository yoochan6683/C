// https://www.acmicpc.net/problem/25375
#include <iostream>
#include <numeric>

using namespace std;

int is_exist(int a, int b) {
    int x, y;
    for(int i=1; i<b; i++) {
        x = 1;
        y = b - x;
        if(gcd(x, y) == a) return 1;
    }
    return 0;
}

int main() {
    int Q;
    cin >> Q;

    for(int i=0; i<Q; i++) {
        int a, b;
        cout << is_exist(a, b) << '\n';
    }

    return 0;
}