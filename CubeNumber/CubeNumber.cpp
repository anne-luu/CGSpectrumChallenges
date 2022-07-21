#include <iostream>

using namespace std;

float Cubed(float number);

int main()
{
    cout << "Enter a number: ";

    float z;

    cin >> z;

    cout << "The number " << z << " cubed is " << Cubed(z) << endl;
}

float Cubed(float number)
{
    return number * number * number;
}