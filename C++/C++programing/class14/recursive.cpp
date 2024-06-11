#include <iostream>

using namespace std;

int nSum(int& n) {
    int i;

    if(n == 0) {
        n = 1;
        return 0;
    }

    n = n - 1;
    // int res = nSum(n) + n;
    //nSum(n)부터 접근하기 때문에 컴파일러가 뒤에 +n에 접근할 수가 없음 -> 결국 마지막에 뒤에 n이 전부 1로 됨 -> 출력: 5
    //nSum(n) + n + n + n + n...
    int res = n + nSum(n);
    // n + nSum(n) = n + (n - 1) + nSum(n - 1) = n + (n - 1) + (n - 2) + nSum(n -2).... -> 반복

    return res;
}

int main() {
    int n = 5;
    int sum = nSum(n);

    cout << "sum = " << sum << '\n';
    return 0;
}