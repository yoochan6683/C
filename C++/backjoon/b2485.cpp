// https://www.acmicpc.net/problem/2485
#include <iostream>

using namespace std;

int Euclidean(int a, int b) {
    int r = a % b;
    if (r == 0)
        return b;
    else
        return Euclidean(b, r);
};

int main() {
    int N, min_space;
    cin >> N;

    int *tree_arr = new int[N];
    // 현재 심어져 있는 나무 배열
    for (int i=0; i<N; i++) {
        cin >> tree_arr[i];
    }

    int *space_arr = new int[N-1];
    // 간격 배열
    for (int i=0; i<N-1; i++) {
        space_arr[i] = tree_arr[i+1] - tree_arr[i];
    }

    int min_common_space = space_arr[0];

    // N-1개의 간격의 최대공약수를 구한다.
    for(int i=0; i<N-1; i++) {
        min_common_space = Euclidean(min_common_space, space_arr[i]);
    }

    // (마지막 가로수의 위치 - 첫번째 가로수의 위치)를 최대공약수로 나누고 N-1을 뺀다.
    int needed_tree = (tree_arr[N-1] - tree_arr[0]) / min_common_space - (N-1);
    cout << needed_tree << '\n';
    return 0;
}