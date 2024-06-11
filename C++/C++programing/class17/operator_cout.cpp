#include <cstdio>

// using namespace std;

namespace std {
    class Date {
        public:
            int d, m, y;
    };
    class ostream {
        public:
            ostream& operator << (int n) {
                printf("%d\n", n);
                return *this;
            }
            ostream& operator << (double n) {
                printf("%f\n", n);
                return *this;
            }
            ostream& operator << (const Date& dt) {
                printf("%d/%d/%d\n", dt.d, dt.m, dt.y);
                return *this;
            }
    };

    ostream cout;
}

int main() {
    std::cout << 3;
    std::cout.operator << (3);
    std::cout << 3.14;
    std::Date myDate; myDate.d = 1; myDate.m = 2; myDate.y = 2024;
    std::cout << myDate;
    return 0;
}