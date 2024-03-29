// https://www.acmicpc.net/problem/2581
#include <iostream>
#include <cmath>

using namespace std;
bool is_prime(int num); 

int main() {
    int startNum, endNum, sum = 0, min = 0;
    cin >> startNum >> endNum;

    for(int i=startNum; i<=endNum; i++) {
        if(is_prime(i)) {
            if(sum == 0) min = i;
            sum += i;
        }
    }

    if(sum == 0 && min == 0) {
        cout << -1 << '\n';
    } else {
        cout << sum << '\n' << min << '\n';
    }

    return 0;
}

bool is_prime(int num) {
    if(num == 1) return 0;
    for(int i=2; i<=sqrt(num); i++) {
        if (num % i == 0) return 0;
    }

    return 1;
}

/*
    '1'을 처리 안해줬었음
*/