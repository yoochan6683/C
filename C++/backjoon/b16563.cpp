// https://www.acmicpc.net/problem/16563
#include <iostream>
#include <cmath>

using namespace std;

int min_eratos[5000010];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    for(int i=0; i<5000001; i++) {
        min_eratos[i] = i;
    }

    for(long long int i=2; i<5000001; i++) {
        if(min_eratos[i] == i) {
            for(long long int j=i*i; j<=5000000; j+=i) {
                if(min_eratos[j] == j) {
                    min_eratos[j] = i;
                }
            }
        }
    }

    for(int i=0; i<N; i++) {
        int num;
        cin >> num;

        while(num != 1) {
            cout << min_eratos[num] << " ";
            num /= min_eratos[num];
        }

        cout << '\n';
    }
    return 0;
}