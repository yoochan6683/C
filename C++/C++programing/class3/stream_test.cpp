#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    // char Char1 = '\0', Char2 = '\0', Char3 = '\0';
    // cin >> Char1 >> Char2 >> Char3;
    // cout << Char1 << Char2 << Char3;

    //C-Language style string input
    // char CStyleStr[10] = {0};
    //string은 끝에 '\0'이 한자리 차지하기 때문에 9개만 받을 수 있음
    // cin.get(CStyleStr, 9);
    // cout << CStyleStr << endl;

    // string Name1;
    // //띄어쓰기 있으면 못 가져옴 -> 입력: choi yoo chan 출력: choi
    // // cin >> Name1;
    // getline -> 다 가져옴
    // getline(cin, Name1);
    // cout << "Hi " << Name1 << endl;

    ofstream myFile;

    myFile.open("HelloFile.txt", ios_base::out);

    if(myFile.is_open()) {
        cout << "File Open.successful" << endl;
        myFile << "My First test file" << endl;
        myFile << "Hello File";
        myFile.close();
    }

    return 0;
}
/*
    ios_base::in -> Opens file for read operations only
    ios_base::out -> Opens file for write operations only
    ofstream: 하드디스크의 파일 시스템(File System)에 파일 생성 ex) HelloFile.txt
*/