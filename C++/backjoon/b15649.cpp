// https://www.acmicpc.net/problem/15649
#include <iostream>

using namespace std;

int N, M;
int arr[9] = {0, };
bool visited[9] = {0, };

void dfs(int depth) {
    if(depth == M) {
        for(int i=0; i<M; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i=1; i<=N; i++) {
        if(!visited[i]) {
            arr[depth] = i;
            visited[i] = true;
            dfs(depth + 1);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> N >> M;

    dfs(0);
    return 0;
}