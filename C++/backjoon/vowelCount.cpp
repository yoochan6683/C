// https://www.acmicpc.net/problem/1264
#include <iostream>
#include <string>

using namespace std;

int countVowel(string input) {
    int i = 0;
    int result = 0;
    for(int i=0; i<input.size(); i++){
        char temp = input[i];
        if (temp == 'a' || temp == 'o' || temp == 'i' || temp == 'u' || temp == 'e' || temp == 'A' || temp == 'I' || temp == 'O' || temp == 'U' || temp == 'E') result++;
    }
    return result;
}

int main() {
    while(1) {
        string input;
        getline(cin, input);
        if(input == "#") break;

        cout << countVowel(input) << endl;
    }
    return 0;
}