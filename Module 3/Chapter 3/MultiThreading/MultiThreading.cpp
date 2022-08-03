#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <atomic>

using namespace std;

bool DidQuit = false;
bool ShouldDecrementLife = false;
mutex Mutex;

struct Character
{
    float Position = 0.0f;
    atomic<int> Score = 0;
    int Lives = 1;

    void DisplayStats()
    {
        cout << "Lives: " << Lives << endl;
    }
};

Character Player;

void UpdateCharacter1()
{
    while (!DidQuit)
    {
        lock_guard<mutex>Guard(Mutex);
        if (ShouldDecrementLife)
        {
            if (Player.Lives > 0)
            {
                //the two lines below essentially do the same thing
                //this_thread::sleep_for(chrono::milliseconds(500));
                //this_thread::yield();
                --Player.Lives;
            }
        }
    }
}

void UpdateCharacter2()
{
    while (!DidQuit)
    {
        if (ShouldDecrementLife)
        {
            //Will lock this scope (the curly bracket after ShouldDecrementLife)
            lock_guard<mutex>Guard(Mutex);
            if (Player.Lives > 0)
            {
                //the two lines below essentially do the same thing
                //this_thread::sleep_for(chrono::milliseconds(500));
                //this_thread::yield();
                --Player.Lives;
            }
        }
    }
}

void ProcessInput()
{
    while (!DidQuit)
    {
        cout << "'a' to decrement player life" << endl;
        cout << "'d' to display player stats" << endl;
        cout << "'q' to quit" << endl;

        char UserInput;
        cin >> UserInput;

        switch (UserInput)
        {
        case 'a':
            ShouldDecrementLife = true;
            break;
        case 'd':
            Player.DisplayStats();
            break;
        case 'q':
            DidQuit = true;
            break;
        default:
            break;
        }

        DidQuit = (UserInput == 'q');
    }
}


int main()
{
    thread InputHandler(ProcessInput);
    thread CharacterUpdate1(UpdateCharacter1);
    thread CharacterUpdate2(UpdateCharacter2);

    InputHandler.join();
    CharacterUpdate1.join();
    CharacterUpdate2.join();

    return 0;
}
