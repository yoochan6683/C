// https://www.acmicpc.net/problem/1009
#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int a, b, temp = 1;
        cin >> a >> b;

        for(int j = 0; j < b; j++) {
            temp *= a;
            temp = temp % 10;
        }

        if(temp == 0) temp = 10;

        cout << temp << '\n';
    }
    return 0;
}