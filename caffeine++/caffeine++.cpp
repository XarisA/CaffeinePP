#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <signal.h>

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
	int i;
	if (argc > 3)
	{
		cout << "Wrong number of arguments.";
		return 0;
	}
	else if (argc > 1 and argc <= 3)
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
				cout << "Running the -t hand\n";
			}
			else
			{
				cout << "Invalid argument " << argv[i] <<", please try again.\n";
				ShowWindow(GetConsoleWindow(), SW_NORMAL);
				Sleep(1500);
				exit(1);
			}
			//Debug
			//cout << "\nArgc is \"" << argc << "\"" << "\nArgv is :\"" << argv[1] << "\"\n" << (argv[1] == "-m" ? "true" : "false")<<"\n";
		}
	}

	signal(SIGINT, signal_handler);
	cout << "Caffeine++ is runnning\n";
	cout << "Use Control-C to stop this service and restore previous state\n";
	while (1) {
		SetThreadExecutionState(ES_CONTINUOUS | ES_DISPLAY_REQUIRED | ES_SYSTEM_REQUIRED | ES_AWAYMODE_REQUIRED);
	}
	return EXIT_SUCCESS;
}
