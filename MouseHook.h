#pragma once

/*
	Win32 mouse hook helper
    kali 2021-2022

    Based on code by Julien Harbulot
    https://scripting.tips
*/

#include <iostream>
#include <Windows.h>
#include <functional>
#include "Timer.h"

using namespace std;

// Task to run when the lowLevelMouseProc
// receives a message.
function<void(string, MSLLHOOKSTRUCT*)> hook_task;

// This is the LowLevelMouseProc implementation
// Your implementation must be fast, otherwise
// Windows will remove your hook without notice.
LRESULT CALLBACK lowLevelMouseProc(_In_ int nCode, _In_ WPARAM wParam, _In_ LPARAM lParam)
{
	MSLLHOOKSTRUCT* lp = (MSLLHOOKSTRUCT*)lParam;

    const char* msg;
    char msg_buff[128];
    msg = "";

    switch (wParam)
    {
        case WM_LBUTTONDOWN: msg = "WM_LBUTTONDOWN"; break;
        case WM_LBUTTONUP: msg = "WM_LBUTTONUP"; break;
        case WM_MOUSEMOVE: msg = "WM_MOUSEMOVE"; break;
        case WM_RBUTTONDOWN: msg = "WM_RBUTTONDOWN"; break;
        case WM_RBUTTONUP: msg = "WM_RBUTTONUP"; break;
        default: 
            sprintf(msg_buff, "Unknown msg: %u", wParam); 
            break;
    }

    if (msg != "")
        if (hook_task != NULL)
            hook_task(msg, lp);

	return CallNextHookEx(0, nCode, wParam, lParam);
}

class MouseHook
{
private:
    HHOOK handle;
    
public:
    MouseHook(void) { handle = SetWindowsHookExA(WH_MOUSE_LL, &lowLevelMouseProc, NULL, 0); }
    
    ~MouseHook(void) { cleanup(); }

    int cleanup(void)
    {
        if (!UnhookWindowsHookEx(handle))
        {
            cout << "Error: unable to unhook" << endl;
            return -1;
        }
        return 0;
    }

    HHOOK get_handle(void) { return handle; }
};