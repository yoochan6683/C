#include <iostream>
#include <fstream>
#include <cstring>

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
    Human yoochan("Choi Yoo Chan", 24, "March 2001");

    ofstream writeFile("MyBinary.bin", ios_base::out | ios_base::binary);

    if (writeFile.is_open()) {
        writeFile.write(reinterpret_cast<const char*>(&yoochan), sizeof(yoochan));
        writeFile.close();
    }

    ifstream readFile("MyBinary.bin", ios_base::in | ios_base::binary);

    if (readFile.is_open()) {
        Human somePerson;
        readFile.read((char*)&somePerson, sizeof(somePerson));

        cout << somePerson.Name << '\n';
        cout << somePerson.Age << '\n';
        cout << somePerson.DOB << '\n';
    }
    return 0;
}