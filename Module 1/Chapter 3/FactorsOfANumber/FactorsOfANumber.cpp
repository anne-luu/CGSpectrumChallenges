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
    // I usually adhere to best practice and stuck to using pre increment for iterator, so prefer ++it instead of it++
    // The argument is that it++ must return the value of the iterator before incrementing, so the previous value is copied, you incurred a copy cost.  See links
    // I am not entirely sure if this is true for all compilers and if compiler are smart enough to optimize it.  But when in doubt, I just use best practice then there's
    // second guessing what the compiler might or might not do
    // https://stackoverflow.com/questions/1303899/performance-difference-between-iterator-and-iterator
    // https://eklitzke.org/stl-iterators-and-performance-revisited#:~:text=In%20the%20pre%2Dincrement%20case,before%20the%20increment%20was%20applied.&text=The%20post%2Dincrement%20operator%20has,to%20the%20pre%2Dincrement%20operator.
    for(set<unsigned int>::iterator it=factors.begin(); it != factors.end(); it++)
        cout << *it<< ", ";

    //Move the cursor back twice and overwrite the comma with an empty string
    cout << "\b\b" << "";
}
