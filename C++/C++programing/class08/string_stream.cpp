#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

struct Human {
    Human() {};
    Human(const char* inName, int inAge, const char* inDOB) : Age(inAge) {
        strcpy(Name, inName);
        strcpy(DOB, inDOB);
        // Age = inAge;
    } 
    // Human(const char* inName, int inAge, const char* inDOB) {
    //     strcpy(Name, inName);
    //     strcpy(DOB, inDOB);
    //     Age = inAge;
    // }
    char Name[30];
    int Age;
    char DOB[20];
};

int main() {
    Human input("Tom Cruise", 101, "May 1910");
    ofstream fsOut("MyBinary.bin", ios_base::out | ios_base::binary);

    if (fsOut.is_open()) {
        cout << "Writing ..." << '\n';
        // fsOut.write((char*)(&input), sizeof(input)); C-Style TypeCast
        fsOut.write(reinterpret_cast<const char*>(&input), sizeof(input)); // C++-Style TypeCast
        fsOut.close();
    }

    ifstream fsin("MyBinary.bin", ios_base::out | ios_base::binary);
    if(fsin.is_open()) {
        Human somePerson;
        fsin.read((char*)&somePerson, sizeof(somePerson));
        cout << "Name: " << somePerson.Name << '\n';
        cout << "Age: " << somePerson.Age << '\n';
        cout << "DOB: " << somePerson.DOB << '\n';
    }

    int i = 10;
    stringstream convertStream;
    convertStream << i;
    string strInput;
    convertStream >> strInput;

    cout << i << '\n';
    cout << strInput << '\n';

    return 0;
}