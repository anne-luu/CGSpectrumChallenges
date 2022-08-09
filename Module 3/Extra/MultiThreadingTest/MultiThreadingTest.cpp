#include <iostream>
#include <thread>

using namespace std;

void HelloWorldThread()
{
    cout << "Hello world thread" << endl;
}

int main()
{
    std::cout << "Hello World!\n";

    thread Hello(HelloWorldThread);

    //Cannot go beyond this point until hello thread is ran
    Hello.join();
    return 0;
}

