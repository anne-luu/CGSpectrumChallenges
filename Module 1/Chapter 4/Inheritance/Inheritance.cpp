#include <iostream>
#include "Vehicle.h"
#include "Car.h"
#include "Boat.h"
#include "Airplane.h"

using namespace std;

int main()
{
    unique_ptr<Vehicle> v1( new Vehicle());
    v1->Drive(10);
    cout << v1->getDistance() << endl;
    //Objects of Unique pointer will be deleted once it goes out of scope
    //Cannot have another pointer pointing to the object of the unique pointer
    //Ref: https://www.internalpointers.com/post/beginner-s-look-smart-pointers-modern-c
    //delete v1;

    cout << endl << endl;

    Car* c1 = new Car();
    c1->Drive(20);
    cout << c1->getDistance() << endl;

    cout << endl << endl;

    Vehicle* v2 = c1;
    //Would call Vehicle drive if drive was not a virtual function
    v2->Drive(20);
    cout << v2->getDistance() << endl;
    delete v2;

    cout << "Attempted to access c1 after deleting 2nd pointer to address" << endl;
    cout << c1->getDistance() << endl;

    cout << endl << endl;

    //Cannot instantiate boat as Vehicle if Vehicle was inherited with private or protected
    Vehicle* b1 = new Boat();
    b1->Drive(30);
    cout << b1->getDistance() << endl;
    delete b1;

    cout << endl << endl;

    Airplane* a1 = new Airplane();
    a1->Drive(10);
    cout << a1->getDistance() << endl;
    delete a1;

    cout << endl << endl;

    return 0;
}