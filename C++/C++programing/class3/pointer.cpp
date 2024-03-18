#include <iostream>

using namespace std;

int main() {
    int Age = 30;
    const double Pi = 3.1416;
    cout << hex << &Age << endl;
    cout << hex << &Pi << endl;

    int *pInteger = &Age;
    cout << dec << *pInteger << endl;
    return 0;
}
/*
    Address | value
    variable: Store something in the memory
    pointer variable: stores address
    non - pointer variable: stores value
    pointer type: *

    Can the address have a type?
        -> No. address has no type. it's just a number.
        then why do we need to write type? ex) int *
        
        one address -> 1 byte
        type always needs operator
        포인터를 ++ 할때 타입의 크기에 맞게 증가시켜줘야 찾기 쉬워진다. 
            -> int * pa, pa++ 하면 4씩 주소를 증가시켜주고, char * pa, pa++ 하면 1씩 주소를 증가시켜줌.
        
    * 는 Unary operator(which has only one operands)
    normally operator has two operands ex) + - x /

    to store something
    4 different memeory spaces
    1. const -> Read-only data segment
    2. Global -> Data segment
    3. Local variable -> Stack(Static memory allocation): 컴파일러가 할당함
    4. Heap -> Dynamic memory allocation

    Every function has its own stack(Local variables, Parameters)
    global과 heap은 언제 어디서든 접근 가능하지만, 함수 안의 데이터는 stack이라 접근 불가능 -> 그 스택이 어딨는지 모르니까 안에 데이터도 어디있는지 모름. 찾을 수 없음.

    Address | Value
    100       Age       -> int(4바이트)니까 그 다음 주소가 104
    104       Pi        -> double(8바이트)
    112       pInteger  -> pInteger에 Age의 주소값 100이 저장되어 있음 (pInteger == 100)

    location = address = pointer = reference 다 같은 말임 c에선
    &: Reference operator -> 주소를 가져옴
    *: Dereference operator -> 값을 가져옴
*/