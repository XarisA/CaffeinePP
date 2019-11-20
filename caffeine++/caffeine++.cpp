#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <signal.h>
#include <time.h>

using namespace std;


void signal_handler(int signum) {
	cout << "Caught exit signal " << signum << endl;
	SetThreadExecutionState(ES_CONTINUOUS);
	cout << "Cya!";
	Sleep(1000);
	exit(signum);
}


int main(int argc, char *argv[], char *envp[])
{
	//#define NUM_SECS 1.0f // delay period
	bool control_switch = 1;
	time_t start, end;
	start = time(NULL);
	double elapsed; //seconds
	double timer=0;
	if (argc > 4)
	{
		cout << "Wrong number of arguments.";
		return 0;
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
				//TODO Implement Timer function
				cout << "\nRunning the -t hand";
				string input = argv[i + 1];
				timer = atof(input.c_str());
				i++;
			}
			else
			{
				cout << "\rInvalid argument " << argv[i] <<", please try again.\n";
				ShowWindow(GetConsoleWindow(), SW_NORMAL);
				Sleep(1500);
				return EXIT_FAILURE;
			}
			//Debug
			//cout << "\nArgc is \"" << argc << "\"" << "\nArgv is :\"" << argv[1] << "\"\n" << (argv[1] == "-m" ? "true" : "false")<<"\n";
		}
	}
	// Hide Cursor from cmd
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO     cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(out, &cursorInfo);
	
	// Add signal interupt
	signal(SIGINT, signal_handler);

	//Inform user
	cout << "Caffeine++ is runnning\n";
	cout << "Use Control-C to stop this service and restore previous state\n";
	
	// Run Caffeine++
	while (control_switch) {
		end = time(NULL);
		elapsed = difftime(end, start);
		cout << "\rElapsed " << elapsed << " seconds";
		if (elapsed >= timer && timer >0 )
			control_switch = 0;
		SetThreadExecutionState(ES_CONTINUOUS | ES_DISPLAY_REQUIRED | ES_SYSTEM_REQUIRED | ES_AWAYMODE_REQUIRED);
	}
	return EXIT_SUCCESS;
}
