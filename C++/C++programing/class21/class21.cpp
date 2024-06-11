#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string S("Hello String! Wake up to a beautiful day!");
    transform(S.begin(), S.end(), S.begin(), (int*)(int)toupper);
    cout << S << '\n';
    reverse(S.begin(), S.end());
    cout << S << '\n';

    string::iterator iChars = find(S.begin(), S.end(), "S");
    S.erase(13,28);
    cout << S << '\n';
    S.erase(S.begin(), S.end());
    cout << S << '\n';
    return 0;
}