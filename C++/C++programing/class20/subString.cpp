#include <iostream>
#include <string>

using namespace std;

int main() {
    string S("Hello String");
    for(size_t n=0; n<S.length(); n++) {
        cout << S[n];
    }
    cout << '\n';

    int i;
    string::const_iterator j;
    for(j=S.begin(); j!=S.end(); j++) {
        cout << *j;
    }
    cout << '\n';

    cout << S.c_str() << '\n';
    string S2("Good day String! Today is beautiful!");
    size_t charPos = S2.find("day", 0);
    if(charPos != string::npos) cout << "First instance of \"day\" was found at position " << charPos;
    else cout << "Substring not found" << '\n';

    const char c = 'a';
    charPos = S.find(c, 0);
    while(charPos != string::npos) {
        cout << "Position: " << charPos;
        size_t charSearchPos;
    }
    return 0;
}