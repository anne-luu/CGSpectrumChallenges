#include <iostream>

using namespace std;

void ptrDisplayAandB(int* a, int* b);
void refDisplayAandB(int& a, int& b);

int main()
{
    cout << "Enter a value for a: ";

    int a;
    cin >> a;

    cout << "\nEnter a value for b: ";

    int b;
    cin >> b;

    int* ptrA = &a;
    int* ptrB = &b;

    ptrDisplayAandB(ptrA, ptrB);
    refDisplayAandB(a, b);

    a = 10;
    b = 15;

    ptrDisplayAandB(ptrA, ptrB);
    refDisplayAandB(a, b);

    //Seems I do not need to manually delete since this points to existing memory that is scoped and this causes an error
    //delete ptrA;
    //ptrA = nullptr;

    //delete ptrB;
    //ptrB = nullptr;
}

void ptrDisplayAandB(int* a, int* b)
{
    cout << "*a: " << *a << " *b: " << *b << endl;
}

void refDisplayAandB(int& a, int& b)
{
    cout << "a: " << a << " b: " << b << endl;
}