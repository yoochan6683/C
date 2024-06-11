#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    cout << "Hey - default!" << endl;

    cout << setw(35) << setfill('*');
    cout << "Hey - right aligned!" << '\n';

    cout << "Hey - back to default!" << endl;
    return 0;
}