// https://www.acmicpc.net/problem/2798
#include <iostream>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int *arr = new int[N];

    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }

    int current_max = 0;
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(j == i) continue;
            for(int p=0; p<N; p++) {
                if(p == j || p == i) continue;
                int test_max = arr[i] + arr[j] + arr[p];
                if(test_max > current_max && test_max <= M) {
                    current_max = test_max;
                }
            }
        }
    }

    cout << current_max << '\n';
    return 0;
}