#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

class AutoClicker {
private:
    bool click;
    int interval;
public:
    AutoClicker() : click(false), interval(1) {}

    void menu() {
        cout << "Press 'X' to enable and 'Z' to disable autoclicker\n";
    }

    void startClicker() {
        while (true) {
            if (GetAsyncKeyState('X')) {
                click = true;
            }
            else if (GetAsyncKeyState('Z')) {
                click = false;
            }
            if (click) {
                mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
                mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
                Sleep(1);
            }
        }
    }
};

int main()
{
    AutoClicker autoClicker;
    autoClicker.menu();
    autoClicker.startClicker();

    return 0;
}
