// https://www.acmicpc.net/problem/4134
#include <iostream>
#include <cmath>

using namespace std;

int isPrime(long long int num) {
    if(num == 0) return 0;
    if(num == 1) return 0;
    for(int i=2; i<=sqrt(num); i++) {
        if(num % i == 0) return 0;
    }
    return 1;
}

long long int get_next_min_prime(long long int num) {
    while(1) {
        if(isPrime(num)) return num;
        num++;
    }
}

int main() {
    int N;
    cin >> N;

    for(int i=0; i<N; i++) {
        long long int num;
        cin >> num;

        cout << get_next_min_prime(num) << '\n';
    }
    return 0;
}