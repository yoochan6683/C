// https://www.acmicpc.net/problem/9610
#include <iostream>

using namespace std;

int main() {
    int arr_len = 0;
    int q1 = 0, q2 = 0, q3 = 0, q4 = 0, axis = 0;

    cin >> arr_len;
    int array[arr_len][2];

    for(int i = 0; i < arr_len; i++) {
        cin >> array[i][0] >> array[i][1];
    }

    for(int i = 0; i < arr_len; i++) {
        if(array[i][0] == 0 || array[i][1] == 0) axis++;
        if(array[i][0] > 0 && array[i][1] > 0) q1++;
        if(array[i][0] < 0 && array[i][1] > 0) q2++;
        if(array[i][0] < 0 && array[i][1] < 0) q3++;
        if(array[i][0] > 0 && array[i][1] < 0) q4++;
    }
    
    cout << "Q1: " << q1 << '\n';
    cout << "Q2: " << q2 << '\n';
    cout << "Q3: " << q3 << '\n';
    cout << "Q4: " << q4 << '\n';
    cout << "AXIS: " << axis << '\n';
    return 0;
}