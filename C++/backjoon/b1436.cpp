// https://www.acmicpc.net/problem/1436
#include <iostream>

using namespace std;

bool is_endNum(int num) {
    int count = 0;
    while(num != 0) {
        int currentNum = num % 10;
        if(currentNum == 6) {
            count++;
            if(count == 3) return 1;
        } else if(currentNum != 6) {
            count = 0;
        }
        num /= 10;
    }
    return count >= 3;
}

int main() {
    int arr[10001];
    // int arr2[10001];
    int N;
    int nth = 0;
    // int nth2 = 0;
    cin >> N;

    for(int i=0; i<10000000; i++) {
        if(is_endNum(i)) {
            arr[nth] = i;
            nth++;
        }
        if(nth > 10000) break;
    }

    // for(int i=0; i<10000000; i++) {
    //     if(is_endNum(i)) {
    //         arr2[nth2] = i;
    //         nth2++;
    //     }
    //     if(arr2[N-1]) break;
    // }

    // for(int i=0; i<N; i++) {
    //     if(arr[i] != arr2[i]) {
    //         cout << i+1 << "번째" << '\n';
    //         cout << "arr: " << arr[i] << '\n';
    //         cout << "arr2: " << arr2[i] << '\n';
    //     }
    // }

    return 0;
}