// https://www.acmicpc.net/problem/2747
#include <iostream>

using namespace std;

int pivo[100] = {0, };

int pivonachi(int n) {
    //입력값이 0이면 0 반환
    if (n <= 1) return n;
    //만약 이전에 계산해 둔 입력값이라면 해당값 재사용
    else if(pivo[n] > 0) return pivo[n];
    //이전에 계산해 둔 값이 없으면 새롭게 계산 후 배열에 추가
    else pivo[n] = pivonachi(n-2) + pivonachi(n-1);
   
    //추가한 후 저장한 해당값 반환
    return pivo[n];
}

int main() {
    int nth;
    cin >> nth;

    cout << pivonachi(nth);

    return 0;
}