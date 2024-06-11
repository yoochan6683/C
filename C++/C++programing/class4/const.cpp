#include <iostream>

using namespace std;

int main() {
    //에러
    int HoursInDay = 24;
    const int* pInteger = &HoursInDay;
    // const int* const pInteger = &HoursInDay; <- 이 경우 pInteger = &MonthInYear; 줄이 에러남(주소가 const)이기 때문

    int MonthInYear = 12;
    pInteger = &MonthInYear;
    // *pInteger = 13; -> 에러: const 선언
    return 0;
}

/*
    100     HoursInDay=24
    104     pInteger=100
    108     monthInYear=12

    //pInteger = &MonthInYear 실행

    100     HoursInDay=24
    104     pInteger=108
    108     monthInYear=12
*/  