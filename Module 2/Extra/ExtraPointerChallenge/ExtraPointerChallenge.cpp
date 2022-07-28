#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void printArrElement(int* arr, int index)
{
    cout << "[" << index <<"|" << (arr + index) << "]: " << *(arr + index) << endl;
}

void bubbleSort(int* arr, int size)
{
    bool isSorted = false;

    int tempSize = size - 1;

    while (!isSorted)
    {
        isSorted = true;

        for (int i = 0; i < tempSize; ++i)
        {
            if(*(arr + i) > *(arr + i + 1))
            {
                //Swap
                int temp = *(arr + i);
                *(arr + i) = *(arr + i + 1);
                *(arr + i + 1) = temp;

                //Set isSorted to false to reloop
                isSorted = false;
            }
        }
    }
}

int main()
{
    srand(time(0));

    cout << "Enter the size of the array: ";

    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 20 + 1;
        printArrElement(arr, i);
    }

    bubbleSort(arr, size);
    
    cout << "\n\nSorted Array: " << endl;

    for (int i = 0; i < size; ++i)
    {
        printArrElement(arr, i);
    }

    delete[] arr;
    arr = nullptr;

    return 0;
}
