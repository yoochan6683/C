#include <iostream>

using namespace std;

int main() {
    int i, j, k, a[3][3], sum;
sum = 0;
a[0][0] = a[0][1] = 0; a[0][2] = 1;
a[1][1] = a[1][2] = 0; a[1][0] = 1;
a[2][0] = a[2][2] = 0; a[2][1] = 1;
for (k = 0; k < 3; k++) {
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (a[i][k] && a[k][j])
                a[i][j] = 1;
        }
    }
}
for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++)
        sum += a[i][j];
}
cout << sum;

}