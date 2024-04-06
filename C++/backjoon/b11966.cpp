// https://www.acmicpc.net/problem/11966
#include <iostream>

using namespace std;

int main() {
    int input, test_value = 1;
    cin >> input;

    while(input > test_value) {
        test_value *= 2;
        if (input == test_value) cout << 1 << '\n';
    }

    if (input == 1) cout << 1 << '\n';
    if (input != test_value) cout << 0 << 'a\n';

    return 0;
}
/*
    2, 4, 8, 16, 32, 64, 128, 256, 512, 1024
    
*/