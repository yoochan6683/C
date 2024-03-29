// https://www.acmicpc.net/problem/9506
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    while(1) {
        int num, sum = 1;
        cin >> num;
        if(num == -1) break;

        int *arr = new int[num];

        for(int i=2; i<=sqrt(num); i++) {
            if(num % i == 0) {
                sum += i; 
                sum += num / i; 
                arr[i] = i;
                arr[num /i] = num / i;
            }
        }

        if(sum == num) {
            cout << num << " = 1";
            for(int i=0; i<num; i++) {
                if(arr[i] != 0) {
                    cout << " + " << i;
                }
            }
            cout << '\n';
        }

        if(sum != num) cout << num << " is NOT perfect." << '\n';
    }
    return 0;
}