#include <iostream>
#include <bitset>

using namespace std;

enum class Days :unsigned int
{
    None = 0,           //00000000
    Sunday = 1,         //00000001
    Monday = 1 << 1,    //00000010
    Tuesday = 1 << 2,   //00000100
    Wednesday = 1 << 3, //00001000
    Thursday = 1 << 4,  //00010000
    Friday = 1 << 5,    //00100000
    Saturday = 1 << 6,  //01000000

    Workdays = Monday | Tuesday | Wednesday | Thursday | Friday,
    Vacationdays = Saturday | Sunday,
    AllDays = Workdays | Vacationdays
};

int main()
{
    int num1 = 1;
    int num2 = 2;

    cout << num1 << " in bits " << bitset<8>(num1) << endl;
    cout << num2 << " in bits " << bitset<8>(num2) << endl;

    int result = num1 | num2;

    cout << num1 << "|" << num2 << " = " << bitset<8>(result) << endl;

    result = num1 & num2;

    cout << num1 << "&" << num2 << " = " << result << endl;

    Days day = Days::Monday;

    cout << "Monday " << unsigned int(day) << endl;
}
