// https://www.acmicpc.net/problem/2480
#include <iostream>
#include <algorithm>

using namespace std;

int prize(int d1, int d2, int d3) {
    int prize;
    //같은 눈이 3개 나오는 경우
    if(d1 == d2 && d2 == d3) prize = 10000 + d1 * 1000;
    else if(d1 != d2 && d2 != d3 && d3 != d1) prize = max(d1, max(d2, d3)) * 100;
    else {
        int sameone;
        if(d1 == d2) sameone = d1;
        if(d2 == d3) sameone = d2;
        prize = sameone * 100 + 1000;
    }
    return prize;
}
int main() {
    int d1, d2, d3;
    cin >> d1 >> d2 >> d3;
    
    cout << prize(d1, d2, d3) << endl;
    return 0;
}