#include <iostream>
#include <list>
#include <string>
#include <forward_list>
#include <set>

using namespace std;

struct ContactItem {
    int k;
    string Name;
    string PhoneNumber;
    string Repressentation;

    ContactItem(const string& strName, const string& strNumber) {
        Name = strName;
        PhoneNumber = strNumber;
        Repressentation = (Name + ". " + PhoneNumber);
    }

    // used by list::remove() given contact list item
    bool operator == (const ContactItem& itemToCompare) const {
        // int i=0;
        // i = 10;
        // k = 10; -> body가 const라서 안됨
        return (itemToCompare.Name == this->Name);
    }

    // used by list::sort()
    bool operator < (const ContactItem& itemToCompare) const {
        return (this->Name < itemToCompare.Name);
    }

    operator const char*() const {
        return Repressentation.c_str();
    }
};

bool SortPredicate_Decending(const int& lsh, const int& rhs) {
    return (lsh > rhs);
}

template <typename T>
void DisplayContents (const T& input) {
    for(auto iElement = input.cbegin(); iElement != input.cend(); ++iElement) {
        cout << *iElement << '\n';
        cout << '\n';
    }
}
int main() {
    list <int> listIntegers;
    listIntegers.push_front(4);
    listIntegers.push_front(3);
    listIntegers.push_front(2);
    listIntegers.push_front(1);
    listIntegers.push_front(0);
    listIntegers.push_back(5);

    listIntegers.insert(listIntegers.begin(), 2);
    listIntegers.insert(listIntegers.end(), 100);
    for(int& x : listIntegers) cout << x << '\n';

    listIntegers.reverse();
    for(int& x : listIntegers) cout << x << '\n';

    list <int> myList;
    myList.push_front(444);
    myList.push_front(2024);
    myList.push_front(-1);
    myList.push_front(0);
    myList.push_front(-5);

    myList.sort();
    for(int& x : myList) cout << x << '\n';
    cout << '\n';
    myList.sort(SortPredicate_Decending);
    for(int& x : myList) cout << x << '\n';

    list <ContactItem> myContacts;
    myContacts.push_back(ContactItem("Trumph", "555"));
    myContacts.push_back(ContactItem("Biden", "444"));
    myContacts.push_back(ContactItem("Zico", "333"));
    myContacts.push_back(ContactItem("Lesseraphim", "222"));
    myContacts.push_back(ContactItem("Espa", "111"));
    
    myContacts.sort();

    DisplayContents(myContacts);
    cout << '\n';
    for (ContactItem& x : myContacts) {
        cout << x.Repressentation << '\n';
    }
    cout << '\n';

    myContacts.remove(ContactItem("Trumph", " "));
    DisplayContents(myContacts);

    forward_list <int> fListIntegers;
    fListIntegers.push_front(0);
    // fListIntegers.push_back(0); //forward_list는 push_back을 지원하지 않음
    set<int> setIntegers;
    multiset <int> msetIntegers;

    setIntegers.insert(60);
    setIntegers.insert(-1);
    setIntegers.insert(3000);
    setIntegers.insert(3000); // 같은 거는 한개만 들어감 (error는 아님)

    cout << '\n';
    for(const int& x : setIntegers) {
        cout << x << " ";
    }
    cout << '\n';

    msetIntegers.insert(setIntegers.begin(), setIntegers.end());
    msetIntegers.insert(3000);
    cout << '\n';
    for(const int& x : msetIntegers) {
        cout << x << " ";
    }
    cout << '\n';

    // I want to change element values in the set
    int x = 10;
    const int* y = &x;
    int *z;

    // *y = 11; // error
    // z = y; // 한쪽은 그냥 int*, 한쪽은 const int*라 대입 불가
    z = const_cast<int*>(y);
    *z = 12;
    cout << "z " << *z << " y " << *y <<  '\n';

    set<int> mySet;
    mySet.insert(3);
    mySet.insert(4);
    mySet.insert(2);

    /* // not recommended but can
    int j = 10;
    for (auto i = mySet.begin(); i != mySet.end(); i++) {
        int* element = const_cast<int*>(&*i);
        *element = j--;
    }

    for(const int& x : mySet) {
        cout << x << '\n';
    }
    */
    return 0;
}
/*
    Sort
    1. pick up an element
    2. compare two elements
    3. Test condition a < b -> true "do nothing"
                            -> false "swap"
    => assending order
*/