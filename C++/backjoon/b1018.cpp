// https://www.acmicpc.net/problem/1018
#include <iostream>

using namespace std;

int main() {
    int row, col;
    cin >> row >> col;

    char** table = new char*[row];
    char sample[8][8] = {
        {'W','B','W','B','W','B','W','B'},
        {'B','W','B','W','B','W','B','W'},
        {'W','B','W','B','W','B','W','B'},
        {'B','W','B','W','B','W','B','W'},
        {'W','B','W','B','W','B','W','B'},
        {'B','W','B','W','B','W','B','W'},
        {'W','B','W','B','W','B','W','B'},
        {'B','W','B','W','B','W','B','W'},
    };

    for(int i=0; i<row; i++) {
        table[i] = new char[col];
        for(int j=0; j<col; j++) {
            cin >> table[i][j];
        }
    }

    int min_change = 64;

    for(int i=0; i<=row-8; i++) {
        for(int j=0; j<=col-8; j++) {
            int count = 0;
            for(int r=i; r<i+8; r++) {
                for(int c=j; c<j+8; c++) {
                    if(table[r][c] != sample[r-i][c-j]) {
                        count++;
                    }
                }
            }
            if(count > 32) {
                count = 64 - count;
            }
            if(count < min_change) {
                min_change = count;
            }
        }
    }

    cout << min_change << '\n';
    return 0;
}