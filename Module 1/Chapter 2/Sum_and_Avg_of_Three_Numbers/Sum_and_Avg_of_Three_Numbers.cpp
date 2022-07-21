#include <iostream>

using namespace std;

int main()
{
    cout << "Enter three numbers: ";

    float a, b, c;
    //Input three numbers
    cin >> a >> b >> c;

    //Calculate the sum
    float sum = a + b + c;

    //Calculate the average
    float avg = sum / 3;

    cout << "The sum is " << sum << ", the average is " << avg << endl;
}