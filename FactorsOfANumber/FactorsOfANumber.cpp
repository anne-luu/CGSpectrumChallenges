#include <iostream>
#include <set>

using namespace std;

void displayAllFactorsOfNum(unsigned int number);

int main()
{
    //Find all factors of a number challenge
    cout << "Enter a positive integer to find factors of: ";

    int number;
    cin >> number;

    displayAllFactorsOfNum(number);

    return 0;
}

void displayAllFactorsOfNum(unsigned int number)
{
    //Loop through half the numbers for the given number and add 1 if the number is odd
    int half = (number % 2 == 0) ? number / 2 : number / 2 + 1;

    //Used to prevent duplicate factors
    set<unsigned int> factors;

    for (int i = 1; i < half; i++)
    {
        if (number % i == 0)
        {
            //cout << i << ", " << number / i << ", ";
            factors.emplace(i);
            factors.emplace(number / i);
        }
    }

    //Iterate through factors set
    for(set<unsigned int>::iterator it=factors.begin(); it != factors.end(); it++)
        cout << *it<< ", ";

    //Move the cursor back twice and overwrite the comma with an empty string
    cout << "\b\b" << "";
}