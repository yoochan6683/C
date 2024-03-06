#include <iostream>
#include <string>

using namespace std;

class Human {
    private:
        string Name = "Tom Cruise";
        int Age = 23;
    public:
        int GetAge() {
            return Age;
        }

        void SetAge(int HumanAge) {
            Age = HumanAge;
        }
};

int main() {
    Human Tom;
    Tom.SetAge(24);
    cout << Tom.GetAge() << endl;
    
    return 0;
}

/*
    Object엔 두가지 Relationship이 있음
    has A / Is A
    Object <- Human <- student <- 종민
    (class) <- (class) <- (class) <- (instance)

    Language  - Primitive type -> 컴파일러에 있는 거
              - Object type

    Class -> scope - private
                   - protected
                   - public

    local variable은 각 함수의 stack에 쌓임(main stack, foo stack...) 이때 stack의 크기는 compiler에 의해 계산됨 -> static memory allocation
    프로그램 실행중에 메모리를 가져와야 하는 경우에, malloc을 통해 stack과 유사한 Heap이라는 공간을 만듦. -> dynamic memory allocation

    global variable은 data segment라는 별도의 구역에 저장됨
    Human은 타입에 불과. 그저 declaration이기 때문에 따로 저장되지는 않음
*/