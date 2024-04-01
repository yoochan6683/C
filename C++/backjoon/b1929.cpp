// https://www.acmicpc.net/problem/1929
#include <iostream>
#include <cmath>

using namespace std;

int isPrime(int num) {
    if(num == 1) return 0;
    
    for(int i=2; i<=sqrt(num); i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}
int main() {
    int M, N;
    cin >> M >> N;

    for(int i=M; i<=N; i++) {
        if(isPrime(i)) cout << i << '\n';
    }

    return 0;
}