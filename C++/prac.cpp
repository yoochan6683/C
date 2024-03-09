#include <iostream>
#include <ctime>

using namespace std;

int main() {
    srand(time(NULL));

    int num = rand() % 6;

    cout << num;
    return 0;
}