// https://www.acmicpc.net/problem/3062
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int len;
    cin >> len;

    int *arr = new int[len];

    for(int i=0; i<len; i++) {
        cin >> arr[i];
        string s_num = to_string(arr[i]);
        string reverse_num = s_num;
        reverse(reverse_num.begin(), reverse_num.end());

        string sum_num = to_string(stoi(s_num) + stoi(reverse_num));
        string reverse_sum_num = sum_num;
        reverse(reverse_sum_num.begin(), reverse_sum_num.end());

        if(stoi(sum_num) == stoi(reverse_sum_num)) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}