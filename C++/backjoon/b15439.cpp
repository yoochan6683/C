// https://www.acmicpc.net/problem/15439
#include <iostream>

using namespace std;

int main() {
    int N, combination;
    cin >> N;

    combination = (N-1) * N;
    cout << combination << '\n';
    return 0;
}