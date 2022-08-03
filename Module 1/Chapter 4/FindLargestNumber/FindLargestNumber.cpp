#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //Challenge to find the largest number in an array
    vector<float> arr;

    float inputNum;

    //Technically any input that is not an float will break the loop
    cout << "Enter numbers, separated by space/new line, to add to the array (enter 'q' to quit): ";

    while (true)
    {
        cin >> inputNum;

        //Check if input was a valid int, if not then break loop
        if (cin.fail())
            break;

        arr.push_back(inputNum);
    }
    float max = arr.front();
    // You can write this easier in C++ 11 with range for
    // https://www.math.ucla.edu/~akrieger/teaching/19w/pic10c/vector.html
    // for (auto& a : arr)
    for (int i = 1; i < (int)arr.size(); i++)
    {
        if (max < arr.at(i))
            max = arr.at(i);
    }

    cout << "The largest number is: " << max << endl;

    return 0;
}
