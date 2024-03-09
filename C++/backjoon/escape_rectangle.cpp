// https://www.acmicpc.net/problem/1085

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    short x,y,w,h;
    cin >> x >> y >> w >> h;
    /*
        w-x, h-y, x, y 중에서 가장 작은 값 반환
    */
   int min1 = min(w-x, h-y);
   int min2 = min(x, y);
   int minimal = min(min1, min2);
   cout << minimal;

    return 0;
}