// https://www.acmicpc.net/problem/2231
#include <iostream>

using namespace std;

int get_division_sum(int targetNum) {
    int sum = targetNum;
    while(targetNum != 0) {
        sum += targetNum % 10;
        targetNum /= 10;
    }
    return sum;
}

int main() {
    int num, ans = 0;
    cin >> num;

    for(int i=1; i<num; i++) {
        int currentSum = get_division_sum(i);
        if(currentSum == num) {
            ans = i;
            break;
        }
    }

    cout << ans << '\n';

    return 0;
}