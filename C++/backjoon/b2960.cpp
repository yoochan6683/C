// https://www.acmicpc.net/problem/2960
#include <iostream>

using namespace std;

int main() {
    int N, K, count = 0;
    cin >> N >> K;

    int *eratostenes = new int[N+1];

    for(int i=2; i<=N; i++) {
        eratostenes[i] = 1;
    }

    //i는 수, i번째 배열이 1이면 안 지워진것, 0이면 지워진 것
    for(int i=2; i<=N; i++) {
        //안 지워진 수라면 루프를 돌면서 배수를 지운다
        if(eratostenes[i] == 1) {
            int temp = i;
            while(i <= N) {
                if(eratostenes[i] == 1) {
                    eratostenes[i] = 0;
                    count++;
                    if(count == K) cout << i << '\n';
                }
                i += temp;
            } 
            i = temp;
        }
        //지워진 수라면 다음 숫자로 이동
    }

    return 0;
}