// https://www.acmicpc.net/problem/2869
#include <iostream>

using namespace std;

int main() {
    int up, down, total, day = 0;
    cin >> up >> down >> total;

    day = (total - up) / (up - down) + 1;
    if((total - up) % (up - down) > 0) day++;

    cout << day << '\n';

    return 0;
}