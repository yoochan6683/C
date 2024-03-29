// https://www.acmicpc.net/problem/1934
#include <iostream>

using namespace std;

int get_least_common_multiple(int a, int b);

int main() {
    int A, B, N;

    cin >> N;

    for(int i=0; i<N; i++) {
        cin >> A >> B;
        int common_multiple = get_least_common_multiple(A, B);
        cout << common_multiple << '\n';
    }
    return 0;
}

int get_least_common_multiple(int a, int b) {
    int larger, smaller, multiple;
    if(a >= b) {
        larger = a; smaller = b;
    } else {
        larger = b; smaller = a;
    }

    multiple = larger;
 
    while(1) {
        if(multiple % smaller == 0) return multiple;
        multiple += larger;
    }
}

