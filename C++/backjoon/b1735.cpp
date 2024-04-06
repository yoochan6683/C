// https://www.acmicpc.net/problem/1735
#include <iostream>

using namespace std;

int Euclidean(int numerator, int denominator) {
    int r = numerator % denominator;
    if(r == 0) return denominator;
    else return Euclidean(denominator, r);
}

int main() {
    //a:분자, A:a의 분모, b:분자, B:b의 분모
    int a, A, b, B;

    cin >> a >> A >> b >> B;

    int numerator, denominator;
    
    numerator = a * B + b * A;
    denominator = A * B;

    int largest_common = Euclidean(numerator, denominator);

    cout << numerator / largest_common << " " << denominator / largest_common << '\n';
    return 0;
}