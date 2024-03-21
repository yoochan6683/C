#include <iostream>

using namespace std;
enum ERR_CODE {SUCCESS, ERROR};
void swap(int &x, int &y);
ERR_CODE Factor(int, int&, int&);

ERR_CODE Factor(int n, int& rSquared, int &rCubed) {
    rSquared = n * n;
    rCubed = n * n * n;
    return SUCCESS;
}
int main() {
    int number, squared, cubed;
    ERR_CODE result;

    number = 3;
    result = Factor(number, squared, cubed);
    cout << number << endl;
    cout << squared << endl;
    cout << cubed << endl;
    cout << result << endl;
    /*
        int Original = 30;
        const int& ConstRef = Original;
        // ConstRef = 40; -> 에러: readOnly
        // int& Ref2 = ConstRef; -> 에러: type mismatch
        // const int& Ref2 = ConstRef; -> 에러 안남
    */
   /*
        int intOne = 5;
        int &SomeRef = intOne;

        cout << intOne << endl;
        cout << SomeRef << endl;
        
        cout << &intOne << endl;
        cout << &SomeRef << endl;

        int intTwo = 8;
        &SomeRef = intTwo;

        cout << "After" << endl;

        cout << intOne << endl;
        cout << intTwo << endl;
        cout << SomeRef << endl;
        

        cout << &intOne << endl;
        cout << &intTwo << endl;
        cout << &SomeRef << endl;
    */

    int x = 10; int y = 20;
    swap(x,y);
    cout << x << " " << y << endl;
    /*
        enum ERR_CODE {SUCCESS, ERROR};
        cout << SUCCESS << endl;
        cout << ERROR << endl;
    */
    return 0;
}

void swap(int &rx, int &ry) {
    int temp;

    temp = rx;
    rx = ry;
    ry = temp;
}
/*
    pointer -> we can reassign a new address
    Reference -> we can reassign a new address into the exisitng reference -> 문법적으로 되지만 추천안함

    basically c++ program return only 1 value.
    multiple values -> python return i,j;
    how in c++?
        -> define structure
        -> pointer-type vairable
        -> class
        -> reference
*/