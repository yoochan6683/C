//2024-03-06
//chap 3. 7p ~
#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    int i = 10;

    cout << "i: " << i << endl;
    cout << "i in octal: " << oct << i << endl;
    cout << "i in hex: " << hex << i << endl;
    //flag__mask는 bit로 표현됨 0 또는 1(깃발을 들었다 놓는 것처럼 비트를 직접 다루겠다는 뜻)
    cout << setiosflags(ios_base::hex | ios_base::showbase | ios_base::uppercase);
    cout << i << endl;
    cout << resetiosflags(ios_base::hex | ios_base::showbase | ios_base::uppercase);
    cout << i << endl;

    const double Pi = 4321.123456789;
    cout << "Pi = " << Pi << endl;
    cout << setprecision(7);
    cout << "precision Pi = " << Pi << endl;
    cout << fixed << "Fixed Pi = " << Pi << endl;
    cout << scientific << "Scientific Pi = " << Pi << endl;
    cout << setiosflags(ios_base::copyfmt_event);

    return 0;
}

//필기
/*
    C++: Object Oriented Language
    Motto: Everything in the world is and object

    Object -> State(상태) + Behavior(행동)
    문제들은 여러 오브젝트로 이루어져 있다.

    언어들은 오브젝트를 클래스로 나타낸다.
    클래스는 그냥 템플릿임(template)
    클래스 안에 state에 해당하는 변수(variables), behavior에 해당하는 메소드(methods)로 오브젝트를 구현함.

    instance를 포함한 클래스 구현을 위해선 할당된 메모리가 필요함(alive in memeory)
    -> 무언가에 접근하기 위해선 일단 메모리에 그게 살아있어야 한다.(존재해야 한다.): malloc
    -> 그걸 new를 통해서 메모리로 호출함

    instance: class가 구현된 하나의 개체 ex) Human(class) <--> 철수(instance)
*/