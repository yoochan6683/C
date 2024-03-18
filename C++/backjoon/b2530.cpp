// https://www.acmicpc.net/problem/2530
#include <iostream>

using namespace std;

int main() {
    int h, m, s;
    int dur_sec;
   
    cin >> h >> m >> s >> dur_sec;

    m += dur_sec / 60;
    s += dur_sec % 60;

    while (h > 23 || m > 59 || s > 59) {
        if (h > 23) {
            h  = h % 24;
        }
        if (m > 59) {
            int tm = m / 60;
            m = m % 60; 
            h += tm;
        }
        if (s > 59) {
            int ts = s / 60;
            s = s % 60; 
            m += ts;
        }
    }

    cout << h << " "<< m << " " << s;
    return 0;
}