// https://www.acmicpc.net/problem/2863
#include <iostream>

using namespace std;

double cal_score(int arr[][2]) {
    double temp1, temp2;
    temp1 = (double)arr[0][0] / arr[1][0];
    temp2 = (double)arr[0][1] / arr[1][1];
    return temp1 + temp2;
}

void turnArr(int arr[][2]) {
    int temp = arr[0][0];
    arr[0][0] = arr[1][0];
    arr[1][0] = arr[1][1];
    arr[1][1] = arr[0][1];
    arr[0][1] = temp;
}

int main() {
    int arr[2][2] = {
        {0, 0}, 
        {0, 0}
    };
    double max = 0;
    int max_turn = 0;

    cin >> arr[0][0] >> arr[0][1] >> arr[1][0] >> arr[1][1];

    max = cal_score(arr);

    for(int i = 0; i < 3; i++) {
        turnArr(arr);
        double current = cal_score(arr);
        if(current > max) {
            max = current;
            max_turn = i + 1;
        }
    }

    cout << max_turn << '\n';

    return 0;
}