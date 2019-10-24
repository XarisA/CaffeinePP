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


int main()
{
	signal(SIGINT, signal_handler);
	cout << "Caffeine++ is runnning\n";
	cout << "Use Control-C to stop this service and restore previous state\n";
	while (1) {
		SetThreadExecutionState(ES_CONTINUOUS | ES_DISPLAY_REQUIRED | ES_SYSTEM_REQUIRED | ES_AWAYMODE_REQUIRED);
	}
	return EXIT_SUCCESS;
}
