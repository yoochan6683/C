#include <iostream>

using namespace std;
#define ARRAY_LENGTH 25
#define SQUARE(x) {(x) * (x)}
#define FAV_WHISKY "jack Daniel"
int MyNumbers[ARRAY_LENGTH];

template <typename o>
const o& GetMax(const o& v1, const o& v2) {
    if(v1 > v2) return v1;
    else return v2;
}

template <typename T1=int, typename T2=double>
class H {
    private:
        T1 v1;
        T2 v2;
    public:
        H(const T1& value1, const T2& value2) {v1 = value1; v2 = value2;}
        const T1& GF() const {return v1;}
        const T2& GS() const {return v2;}

};

template <typename T>
class TS {
    public:
        static int S;
};

template <typename T> int TS<T>::S;

template <typename T>
class E {
    public:
        E() {
            static_assert(sizeof(T) != sizeof(int), "No int!!!");
        }
};
int main() {
    int i = SQUARE(5);
    cout << i << '\n';

    E<int> test; //error
    E<double> test; //OK

    TS<int> int_Year;
    int_Year.S = 2024;
    TS<int> int_2;

    TS<double> D1;
    TS<double> D2;
    D2.S = 1024;

    cout << int_2.S << '\n';
    cout << D1.S << '\n';

    H<> m1(300, 10.09);
    H<short, char*> m2(25, "Learn");
    cout << m1.GF() << '\n';
    cout << m1.GS() << '\n';
    double d1 = 1.1, d2 = 1.0001;
    double MaxValue = GetMax<double>(d1, d2);
    cout << MaxValue << '\n';
    return 0;
}
