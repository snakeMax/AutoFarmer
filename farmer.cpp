#include <iostream>
#include <Windows.h>
using namespace std;

INPUT ip;

void menu()
{
	cout << "Press 'X' to enable and 'Z' to disable auto farmer\n";
}

void clicker()
{
	bool click = false; //sets click to false

	while (true)
	{
		if (GetAsyncKeyState('X')) //if X is pressed click = true
		{
			click = true;
		}
		else if (GetAsyncKeyState('Z')) //if 'Z' is pressed click = false
		{
			click = false;
		}
		if (click == true) // if click = true it will press the mouse button down and up really fast
		{
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1); //you can adjust the speed of the click here
		}
	}
}

int main()
{	
	ip.type = INPUT_KEYBOARD;
	ip.ki.wScan = 0; // hardware scan code for key
	ip.ki.time = 0;
	ip.ki.dwExtraInfo = 0;

	// Press the "A" key
	ip.ki.wVk = 0x45; // virtual-key code for the "a" key
	ip.ki.dwFlags = 0; // 0 for key press

	menu();
	clicker();

	return 0;
}
