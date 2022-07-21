#include <iostream>

using namespace std;

bool isLeapYear(int year);
void printLeapYearMessage(bool isLeapYear);

int main()
{
    //Leap Year Challenge
    cout << "2016";
    printLeapYearMessage(isLeapYear(2016));

    cout << "2200";
    printLeapYearMessage(isLeapYear(2200));

    cout << "2400";
    printLeapYearMessage(isLeapYear(2400));

    cout << "2130";
    printLeapYearMessage(isLeapYear(2130));

    cout << endl << endl;

    cout << "Enter a year to check if it is a leap year: ";

    int year;

    cin >> year;

    cout << year;
    printLeapYearMessage(isLeapYear(year));

    return 0;
}

bool isLeapYear(int year)
{
    if (year % 4 == 0 && year % 400 == 0)
        return true;
    else if (year % 4 == 0 && year % 100 == 0)
        return false;
    else if (year % 4 == 0)
        return true;

    return false;
}

void printLeapYearMessage(bool isLeapYear)
{
    if (isLeapYear)
        cout << " is leap year" << endl;
    else
        cout << " is not leap year" << endl;
}