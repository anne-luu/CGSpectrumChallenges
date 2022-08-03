#include <iostream>
#include <algorithm>
#include <chrono>
#include <stdlib.h>

#define ARRAY_SIZE 10

using std::cout;
using std::endl;
using std::copy;
using std::unique_ptr;

uint32_t GetNanos();

void PrintArray(int ArrayToPrint[], int SizeOfArray);

void FillArray(int ArrayToFill[], int SizeOfArray);

void LinearSearch(int ArrayToSearch[], int SizeOfArray, int SearchKey);

void BubbleSort(int ArrayToSort[], int SizeOfArray);

void BinarySearch(int ArrayToSearch[], int Low, int High, int SearchKey);

int main()
{
    int Dataset[ARRAY_SIZE];

    srand(time(nullptr));
    FillArray(Dataset, ARRAY_SIZE);

    PrintArray(Dataset, ARRAY_SIZE);

    //Copy Array to be used in a different Sorting Algorithm
    int CopyDataset[ARRAY_SIZE];
    copy(Dataset, Dataset + ARRAY_SIZE, CopyDataset);

    PrintArray(CopyDataset, ARRAY_SIZE);

    const int SearchKey = Dataset[rand() % ARRAY_SIZE];
    cout << "Search Key: " << SearchKey << endl;

    //Linear Search is O(n)
    uint32_t StartNanos = GetNanos();
    LinearSearch(Dataset, ARRAY_SIZE, SearchKey);
    uint32_t EndNanos = GetNanos();
    cout << "Linear Search took: " << (EndNanos - StartNanos) << "ns \n\n";

    //Bubble Sort is O(n^2)
    StartNanos = GetNanos();
    BubbleSort(Dataset, ARRAY_SIZE);
    EndNanos = GetNanos();
    cout << "Bubble Sort took: " << (EndNanos - StartNanos) << "ns \n\n";

    PrintArray(Dataset, ARRAY_SIZE);

    PrintArray(CopyDataset, ARRAY_SIZE);

    //Binary Search is O(log n)
    StartNanos = GetNanos();
    BinarySearch(Dataset, 0, ARRAY_SIZE, SearchKey);
    EndNanos = GetNanos();
    cout << "Binary Search took: " << (EndNanos - StartNanos) << "ns \n\n";
}

uint32_t GetNanos()
{
    using namespace std::chrono;
    return static_cast<uint32_t>(duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count());
}

void PrintArray(int ArrayToPrint[], int SizeOfArray)
{
    for (int i = 0; i < SizeOfArray; ++i)
        cout << ArrayToPrint[i] << ", ";

    //Move the cursor back twice and overwrite the comma with two blank spaces
    cout << "\b\b" << "  " << endl << endl;
}

void FillArray(int ArrayToFill[], int SizeOfArray)
{
    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        //Fill the array with a random number between 1 and 100
        ArrayToFill[i] = rand() % ARRAY_SIZE + 1; 
    }
}

void LinearSearch(int ArrayToSearch[], int SizeOfArray, int SearchKey)
{
    int comparisons = 0;

    for (int i = 0; i < SizeOfArray; ++i)
    {
        ++comparisons;

        if (ArrayToSearch[i] == SearchKey)
        {
            cout << "Linear Search comparisons: " << comparisons << endl;
            return;
        }
    }
}

void BubbleSort(int ArrayToSort[], int SizeOfArray)
{
    int comparisons = 0;

    for (int pass = 0; pass < SizeOfArray; ++pass)
    {
        for (int i = 0; i < SizeOfArray - 1; ++i)
        {
            ++comparisons;

            if (ArrayToSort[i] > ArrayToSort[i + 1])
            {
                int temp = ArrayToSort[i];
                ArrayToSort[i] = ArrayToSort[i + 1];
                ArrayToSort[i + 1] = temp;
            }
        }
    }

    cout << "Bubble Sort comparisons: " << comparisons << endl;
}

void BinarySearch(int ArrayToSearch[], int Low, int High, int SearchKey)
{
    int comparisons = 0;

    while (Low <= High)
    {
        int Middle = (Low + High) / 2;

        ++comparisons;

        if (SearchKey == ArrayToSearch[Middle])
        {
            cout << "Search key " << SearchKey << " found at index: " << Middle << endl;
            cout << "Binary Search comparisons: " << comparisons << endl;
            return;
        }
        else if (SearchKey < ArrayToSearch[Middle])
        {
            //Search the lower half of the remaining array
            High = Middle - 1;
        }
        else
        {
            //Search the higher half of the remaining array
            Low = Middle + 1;
        }
    }
}