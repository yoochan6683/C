#include <iostream>

using namespace std;

int main() {
    int Age = 30;
    int DogAge = 9;

    int* pInteger = &Age;
    char* pChar;
    *pChar = 'A';

    // int* pNumbers = new int;
    int* pNumbers = new int[10];

    cout << *pInteger << endl;
    //변수 주소가 아니라 'A'를 넣어도 작동함 -> 컴파일러가 const로 메모리에 저장하기 때문
    cout << *pChar << endl;

    cout << sizeof(pInteger) << endl;
    cout << sizeof(pChar) << endl;

    delete [] pNumbers;//사용이 끝난 Heap을 제거(배열)
    int* myP = new int;
    *myP = 4;
    cout << *myP << endl;

    delete myP;//Heap 제거(일반)

    for (int i = 0; i < 10; i++) {
        *(pNumbers + i) = i;
        cout << *(pNumbers + i) << endl;
        cout << pNumbers[i] << endl;
    }
    return 0;
}

/*
    c/c++ -> type-sensitive Language.
    pointer type variable must access to some variable alive in the memory

    32-bit cpu: address => 32bits = 4byte
    64-bit cpu: address => 64bits = 8byte

    *주소의 크기는 자료형에 상관없이 항상 8바이트*

    new -> Heap(Dynamic allocation) -> decided while the program is running

    stack space(segment) -> automatically managed by the "OS", "Compiler"
    Every function has its own stack
    stacks can not be shared by other functions
    if functions returns, stack is deleted

    Heap can be shared by other functions -> must manage the Heap for yourself

    int main() {
        int *p;
        p = foo()
    }

    int* foo() {
        int p = 4;
        int* myp = &p
        return myp;
    }
    !!! foo가 return 후 메모리에서 삭제되고 나면 p는 허공을 가르키게 됨.

    =>
    int* foo() {
        int* myp = new int(4) <- 얘는 heap. return 후에도 남아있음
        return myp;
    }

    ==> functions 사이끼리 어떤 공간을 공유하고 싶으면 Heap을 사용하자.

    배열을 지정할 때 변수명은 시작 주소값을 가르킴.(int numbers[]에서 numbers는 배열의 시작 주소)
    numbers++, numbers + 1, numbers + 2를 해서 주소값이 4씩 자동으로 넘어감(+4, +4, +8) -> int이기 때문.

    j++ 연산과정(j = 0)
        1. copy j -> tempj = 0
        2. j = j + 1
        3. return tempj
        => 결과값은 0, j는 1로 변함

    const -> read only
    address를 const로 할건지, value를 const로 할건지, 둘다 const로 할건지에 따라 3가지 경우가 있음.
*/