#include <iostream>
#include <vector>

using namespace std;

int main() {
    int MyNumbers[] = {2011, 2052, -525};
    int Solar[2][3] = {{0, 1, 2}, {3, 4, 5}};
    
    vector<int> DynArr(3);
    DynArr[0] = 365;
    DynArr[1] = -421;
    DynArr[2] = 789;

    cout << "Size: " << DynArr.size() << '\n';

    int AnotherNum = 400;
    DynArr.push_back(AnotherNum);

    cout << "Size: " << DynArr.size() << '\n';

    char SayHello[] = {'H', 'e', 'l', 'l', 'o', ' ', '\0'};
    cout << SayHello << '\n';
    cout << sizeof(SayHello) << '\n';
    
    SayHello[5] = '\0';
    cout << SayHello << '\n';
    cout << sizeof(SayHello) << '\n';

    // string MyString = "Hello\0W";
    string MyString ("Hello\0W");
    cout << MyString << '\n';

    string SecString = "Ha Ha";
    string ConCat = MyString + SecString;
    cout << ConCat << '\n';
    return 0;
}

/*
    vector는 클래스의 일종이다.
    string은 primitive 타입이 아니고, "는 operator overloading이다.
    MyString은 그저 instance의 이름
*/