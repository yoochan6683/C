#include <iostream>

using namespace std;

class President {

    public:
        static President& GetInstance() {
            static President OnlyInstance;

            return OnlyInstance;
        }

        string GetName() {
            return Name;
        }

        void SetName(string inputName) {
            Name = inputName;
        }
    private:
        string Name;

        President() {};
        President(const President&);
        President& operator= (const President&);
};
int main() {

    // President Bye;
    President& OnlyPresident = President::GetInstance();
    OnlyPresident.SetName("Abraham Lincon");
    // President Second; -> 에러: Cannot access constructor
    // President* third = new President(); -> 에러
    // President Fourth = OnlyPresident; // Copy Constructor
    // OnlyPresident = President::GetInstance(); // Cannot access operator=

    cout << President::GetInstance().GetName() << '\n';
    return 0;
}