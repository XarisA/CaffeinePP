#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <signal.h>
#include <time.h>

using namespace std;

HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_CURSOR_INFO cursorInfo;


void signal_handler(int signum) {
	SetThreadExecutionState(ES_CONTINUOUS);
	Sleep(1000);
	cursorInfo.bVisible = true;
	SetConsoleCursorInfo(out, &cursorInfo);
	exit(signum);
}


int main(int argc, char *argv[], char *envp[])
{
	bool control_switch = 1;
	time_t start, end;
	start = time(NULL);
	double elapsed;
	double timer=0;

	if (argc > 4)
	{
		cout << "Wrong number of arguments.";
		return EXIT_FAILURE;
	}
	else if (argc > 1 and argc <= 4)
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
			else
			{
				cout << "\rInvalid argument " << argv[i] <<", please try again.";
				ShowWindow(GetConsoleWindow(), SW_NORMAL);
				Sleep(1500);
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
	while (control_switch) {
		end = time(NULL);
		elapsed = difftime(end, start);
		cout << "\rElapsed " << elapsed << " seconds";
		if (elapsed >= timer && timer >0 )
			control_switch = 0;
		SetThreadExecutionState(ES_CONTINUOUS | ES_DISPLAY_REQUIRED | ES_SYSTEM_REQUIRED | ES_AWAYMODE_REQUIRED);
	}
	cursorInfo.bVisible = true;
	SetConsoleCursorInfo(out, &cursorInfo);
	return EXIT_SUCCESS;
}
