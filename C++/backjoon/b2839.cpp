// https://www.acmicpc.net/problem/2839
#include <iostream>

using namespace std;

int main() {
    int N, x/*3*/, y/*5*/;
    int min = -1;
    cin >> N;

    for(y=0; 5*y<=N; y++) {
        if((N-5*y) % 3 != 0) continue;
        x = (N-5*y) / 3;
        if(x+y < min || min == -1) min = x + y;
    }

    cout << min << '\n';
    return 0;
}