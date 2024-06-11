#include <iostream>

using namespace std;

class Foo {
    public:
        int _i;
        constexpr explicit Foo(int i): _i{i} {}
        constexpr int GetValue() const {
            return _i;
        }
};

constexpr double GetPI() {return 22.0/7;}

constexpr int myaddition(int i, int j) {
    return i + j;
}

const int myconstaddition(int i, int j) {
    return i + j;
}

// Compile-time computation of array length
template <typename T, int N>
constexpr int length(const T(&)[N]) {
    return N;
}

int main() {

    // foo is const
    constexpr Foo foo(5);

    const int nums[] {1, 2, 3, 4};
    const int nums2[length(nums) + 2] {1, 2, 3, 4, 5, 6};

    cout << GetPI() << '\n';

    // int age;
    // cin >> age;
    // const int userAge(age);
    // // constexpr int userAge = age; -> 에러: 컴파일 타임에 정의되야 함. (런타임 금지)
    // cout << userAge;

    constexpr float y(108);
    // const int j; -> 에러
    // constexpr int j; -> 에러
    int j = 0;
    // constexpr int k = j + 1; -> 에러: j가 const가 아니기 때문
    j = myaddition(10, 10);
    int k = 10;
    j = myaddition(k, k);
    j = myconstaddition(10, 10);
    j = myconstaddition(k, k);

    const int m = myconstaddition(10, 10);
    const int m2 = myconstaddition(k, k);

    constexpr int x = myaddition(10, 10);
    // constexpr int z = myconstaddition(10, 10);

    cout << foo.GetValue() << '\n';
    cout << length(nums) << '\n';
    return 0;
}