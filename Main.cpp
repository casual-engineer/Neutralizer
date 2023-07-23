#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>

void hideConsoleWindow() {
	HWND consoleHandle = GetConsoleWindow();
	ShowWindow(consoleHandle, SW_HIDE);
}

void killProcess(DWORD processId)
{
	try
	{
		const HANDLE processHandle = OpenProcess(PROCESS_TERMINATE, false, processId);
		TerminateProcess(processHandle, 1);
		CloseHandle(processHandle);
	}
	catch (std::exception)
	{
		;
	}
}

void getProcessId()
{
	DWORD processId;
	HWND windowHandle = FindWindow(NULL, "League of Legends");
	if (windowHandle)
	{
		GetWindowThreadProcessId(windowHandle, &processId);
		killProcess(processId);
	}
	else
	{
		;
	}
}

int main()
{
	hideConsoleWindow();
	while (true)
	{
		getProcessId();
		Sleep(1000);
	}
	_getch();
}
