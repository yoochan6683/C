#include <iostream>

using namespace std;

class MonsterDB {
    public:
        static void DestroyInstance(MonsterDB* pInstance) {
            // static member can access private destructor
            delete pInstance;
        }
    private:
        ~MonsterDB() {cout << "Destructor is called" << '\n';};
};

int main() {
    // MonstreDB myDatabase; -> 에러:deconstructor에 접근 불가
    MonsterDB* myDatabase = new MonsterDB(); // no automatic delete myDatabase
    MonsterDB::DestroyInstance(myDatabase);
    return 0;
}