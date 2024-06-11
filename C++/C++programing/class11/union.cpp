#include <iostream>

using namespace std;

union SimpleUnion {
    int num;
    char alphabet;
};

union SimpleUnion2 {
    int num;
    double preciseNum;
};

struct ComplexType {
    enum DataType {Int, Char} Type;
    union Value {
        int num;
        char alphabet;

        Value() {}
        ~Value() {}
    } value;
};

void DisplayComplexType(const ComplexType obj) {
    switch (obj.Type)
    {
    case ComplexType::Int:
        cout << "Union number: " << obj.value.num << '\n';
        break;
    case ComplexType::Char:
        cout << "Union char: " << obj.value.alphabet << '\n';
        break;
    
    default:
        break;
    }
}
int main() {

    SimpleUnion u1, u2;
    u1.num = 2100;
    u2.alphabet = 'C';
    cout << sizeof(u1) << '\n';
    cout << sizeof(u2) << '\n';

    ComplexType myData1, myData2;
    myData1.Type = ComplexType::Int;
    myData1.value.num = 2017;


    myData2.Type = ComplexType::Char;
    myData2.value.alphabet = 'X';

    DisplayComplexType(myData1);
    DisplayComplexType(myData2);

    SimpleUnion2 myU1;
    myU1.preciseNum = 3.14;
    int num2 = myU1.num;

    variant <int, double> varSafe;
    varSafe = 3.14;

    double pi = get<double>(varSafe);
    double pi2 = get<1>(varSafe);

    //에러
    // get<char>(varSafe);

    //에러
    // get<2>(varSafe);

    try {
        get<double>(varSafe);
    } catch (bad_variant_access) {}
    return 0;
}

/*
    union의 크기는 가장 큰 타입 기준으로 정해짐
*/