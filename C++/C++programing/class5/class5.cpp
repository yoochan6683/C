#include <iostream>

using namespace std;

void ReturnSquare(int& Number) {
    Number *= Number;
}

int main() {
    // int MyNumbers[5];

    // int *pNumbers = MyNumbers;

    // //MyNumbers++;  <- 에러: const를 변경하려 했기 때문
    // pNumbers++;

    // //----------------------------------
    // int N[5] = {24, -1, 335, -999, 201};
    // int *pNum = N;

    // cout << pNum[1] << '\n';
    // //----------------------------------
    // int* pT = NULL;
    // cout << pT << '\n';

    // cout << "Is it sunny (y/n)?" << '\n';
    // char i = 'y';
    // cin >> i;

    // if (i == 'y') {
    //     pT = new int;
    //     *pT = 30;
    // }

    // cout << *pT << '\n';

    // if (pT) delete pT;
    // try {
    //     int* pAge = new int [59938281];
    //     delete[] pAge;
    // } catch(bad_alloc) {
    //     cout << "Memory allocation failed" << '\n';
    // }

    // int* pAge = new(nothrow) int [0xffffffff];
    // int* pAge = new int [0xffffffff];

    // if (pAge) {
    //     delete[] pAge;
    // } else {
    //     cout << "Memory allocation failed" << '\n';
    // }
    // int intOne;
    // int &SomeRef = intOne;
    // intOne = 5;
    // cout << intOne << '\n';
    // cout << SomeRef << '\n';
    // cout << &intOne << '\n';
    // cout << &SomeRef << '\n';

    // int Original = 30;
    // int &Ref = Original;

    // cout << Original << '\n';
    // cout << Ref << '\n';
    // int& Ref2 = Ref;
    
    // cout << Ref2 << '\n';
    // cout << &Original << '\n';
    // cout << &Ref << '\n';
    // cout << &Ref2 << '\n';

    int Number = 20;
    ReturnSquare(Number);
    cout << Number << '\n';

    return 0;
}
/*
    Call by Value
    Call by Reference

    1. use return value
    2. user pointer vaiable

    함수 사이에서 어떤 값을 주고 받는 방식은 무조건 copy!!!
        => swap을 포인터로 구현해야 하는 이유. 그렇지 않으면 다른 메모리 주소에 파라미터를 복사해가서 거기서 바꿔버림 -> 본래 메모리 주소의 값들을 바뀌지 않음(그대로)
        => 포인터로 구현하면 주소를 복사해가서 전혀 다른 메모리 주소에 저장하지만, 포인터로 접근하기 떄문에 원래 메모리 주소의 값들을 바꿀 수 있게 됨.

    swap 함수 실행이 끝나고 나면 스택에서 지워지는데, 어떻게 동작하냐?
        => 원래 main 스택은 살아 있고, main 스택의 메모리 주소에서 값들을 조작했기 때문에 괜찮음.

    
*/