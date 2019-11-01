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

	if (argc > 2)
	{
		cout << "Wrong number of arguments.";
		return 0;
	}
	else if (argc == 2)
	{
		if (strcmp(argv[1],"-m") || strcmp(argv[1], "-start-minimised"))
		{
			ShowWindow(GetConsoleWindow(), SW_MINIMIZE);
		}
		else
		{
			cout << "Invalid arguments, please try again.\n";
			Sleep(2000);
			exit(0);
		}
		//Debug
		//cout << "\nArgc is \"" << argc << "\"" << "\nArgv is :\"" << argv[1] << "\"\n" << (argv[1] == "-m" ? "true" : "false")<<"\n";
	}

	signal(SIGINT, signal_handler);
	cout << "Caffeine++ is runnning\n";
	cout << "Use Control-C to stop this service and restore previous state\n";
	while (1) {
		SetThreadExecutionState(ES_CONTINUOUS | ES_DISPLAY_REQUIRED | ES_SYSTEM_REQUIRED | ES_AWAYMODE_REQUIRED);
	}
	return EXIT_SUCCESS;
}
