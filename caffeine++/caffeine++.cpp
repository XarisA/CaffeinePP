#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <signal.h>
#include <time.h>
#include <chrono>
#include <thread>
#include <string>

using namespace std;

HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_CURSOR_INFO cursorInfo;


void signal_handler(int signum) {
	SetThreadExecutionState(ES_CONTINUOUS);
	std::this_thread::sleep_for(std::chrono::seconds(1));
	cursorInfo.bVisible = true;
	SetConsoleCursorInfo(out, &cursorInfo);
	exit(signum);
}

void typeCharacter(char c) {
	// Display the character
	std::cout << c << std::flush;

	// Simulate key press
	keybd_event(VkKeyScanA(c), 0, 0, 0);

	// Pause for a short duration
	std::this_thread::sleep_for(std::chrono::milliseconds(120));

	// Simulate key release
	keybd_event(VkKeyScanA(c), 0, KEYEVENTF_KEYUP, 0);
}

int main(int argc, char *argv[], char *envp[])
{
	bool control_switch = 1;
	time_t start, end;
	start = time(NULL);
	int elapsed;
	double timer=0;
	int mode = 0;

	if (argc > 5)
	{
		cout << "Wrong number of arguments.";
		return EXIT_FAILURE;
	}
	else if (argc > 1 and argc <= 6)
	{
		for (int i = 1; i < argc; ++i)
		{
			if (argv[i] == string("-m") || argv[i] == string("-start-minimised"))
			{
				ShowWindow(GetConsoleWindow(), SW_MINIMIZE);
			}
			else if (argv[i] == string("-t") || argv[i] == string("-timer"))
			{
				string input = argv[i + 1];
				timer = atof(input.c_str());
				i++;
			}
			else if (argv[i] == string("-i") || argv[i] == string("-hide-console"))
			{
				ShowWindow(GetConsoleWindow(), SW_HIDE);
			}
			else if (argv[i] == string("-k") || argv[i] == string("-simulate-keypress"))
			{
				mode = 1;
			}
			else
			{
				cout << "\rInvalid argument " << argv[i] <<", please try again.";
				ShowWindow(GetConsoleWindow(), SW_NORMAL);
				std::this_thread::sleep_for(std::chrono::milliseconds(1500));
				return EXIT_FAILURE;
			}
		}
	}

	// Hide Cursor from cmd
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(out, &cursorInfo);
	
	// Add signal interupt
	signal(SIGINT, signal_handler);

	//Inform user
	cout << "Caffeine++ is runnning" << endl;
	cout << "Use Control-C to stop this service and restore previous state" << endl;
	// Run Caffeine++
	switch (mode) {
		case 0:
			while (control_switch) {
				end = time(NULL);
				elapsed = difftime(end, start);
				cout << "\rElapsed " << elapsed << " seconds";
				if (elapsed >= timer && timer > 0)
					control_switch = 0;
				SetThreadExecutionState(ES_CONTINUOUS | ES_DISPLAY_REQUIRED | ES_SYSTEM_REQUIRED | ES_AWAYMODE_REQUIRED);
			}
			break;
		case 1:
			system("cls");  // Clear the console window before start typing
			while (control_switch) {
				end = time(NULL);
				elapsed = difftime(end, start);
				std::string output = "\rElapsed " + std::to_string(elapsed+1) + " seconds";
				if (elapsed >= timer && timer > 0)
					control_switch = 0;
				SetThreadExecutionState(ES_CONTINUOUS | ES_DISPLAY_REQUIRED | ES_SYSTEM_REQUIRED | ES_AWAYMODE_REQUIRED);
				cout << "Caffeine++ is runnning" << endl;
				cout << "Use Control-C to stop this service and restore previous state" << endl;
				for (char c : output) {
					if (GetConsoleWindow() == GetForegroundWindow()) {
						// Type the character
						typeCharacter(c);
					}
				}
				std::this_thread::sleep_for(std::chrono::seconds(2));  // Pause for 1 second
				system("cls");  // Clear the console window
			}
			break;
		default:
			cout << "\rI didn't forgot default..";
		}
	
	cursorInfo.bVisible = true;
	SetConsoleCursorInfo(out, &cursorInfo);
	return EXIT_SUCCESS;
}
