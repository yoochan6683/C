// https://www.acmicpc.net/problem/1978
#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int num) {
    if(num <= 1) return 0;
    for(int i=2; i<=sqrt(num); i++) {
         if(num % i == 0) return 0;
    }

    return 1;
}

int main() {
    int N, count = 0;
    cin >> N;

    for(int i=0; i<N; i++) {
        int num;
        cin >> num;
        if(is_prime(num)) count++;
    }

    cout << count << '\n';
    return 0;
}