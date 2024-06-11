#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Date {
    private:
        int D, M, Y;
        string DateInString;

    public:
        // Constructor
        Date (int iD, int iM, int iY): D(iD), M(iM), Y(iY) {
            
        }
        // Unary increment operator
        // &가 없으면 복사, 있으면 레퍼런스 이용
        Date& operator ++() {
            ++D;
            return *this;
        }
        Date& operator --() {
            --D;
            return *this;
        }
        //H++는 반환하고 ++를 해줘야 하기 때문에 무조건 copy로 해야함
        //++: j = i, ++i, return j;
        Date operator ++(int) {
            Date Copy(D, M, Y);
            ++D;
            return Copy;
        }

        Date operator + (int DaysToAdd) {
            // Date newDate(D + DaysToAdd, M, Y);
            // return newDate;
            return Date(D + DaysToAdd, M, Y);
        }

        Date operator - (int DaysToReduce) {
            // Date newDate(D - DaysToAdd, M, Y);
            // return newDate;
            return Date(D - DaysToReduce, M, Y);
        }
        void operator += (int DaysToAdd) {
            D += DaysToAdd;
        }

        friend ostream& operator << (ostream& os, const Date& myH);
        // operator const char*() {
        //     ostringstream fD;
        //     fD << D << "/" << M << "/" << Y << '\n';
        //     DateInString = fD.str();
        //     return DateInString.c_str();
        // }
        void Display() {
            cout << D << "/" << M << "/" << Y << '\n';
        }
};

ostream& operator << (ostream& os, const Date& myH) {
    return os << myH.D << "/" << myH.M << "/" << myH.Y;
}

int main() {

    Date H(15, 5, 2024);
    H.Display();
    ++H;
    H.Display();
    --H;
    cout << H++ << '\n';

    unique_ptr<Date> pHoliday(new Date(25, 12, 2024));
    pHoliday->Display();

    Date PreviousHoliday(H+10);
    PreviousHoliday.Display();

    Date PreviousHoliday2(H - 10);
    PreviousHoliday2.Display();

    H += 5;
    H.Display();
    return 0;
}