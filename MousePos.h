#pragma once

/*
    Mouse position functions library
    SharktasticA 2020
    https://sharktastica.co.uk
*/

#ifdef _WIN32
    #include <windows.h>
#endif

#ifdef __linux__
    #include <X11/Xlib.h>
    #include <assert.h>
#endif

#include "Vector2D.h"

using namespace std;

/*
    Class of static methods for getting and setting the mouse
    position, automatically handling different operating systems.
*/
class MousePos
{
private:
    MousePos() {};

public:
    /*
        Returns the current mouse position.
        Returns: 2D vector of the X and Y mouse pos
        coordinates.
    */
    static Vector2D get_pos()
    {
        #ifdef _WIN32
            POINT cur;
            GetCursorPos(&cur);
            return Vector2D(cur.x, cur.y);
        #endif

        #ifdef __linux__
            Window win_ret;
            int cur_x, cur_y, win_x, win_y;
            unsigned int mask_ret;

            Display* disp = XOpenDisplay(NULL);
            assert(disp);
            XQueryPointer(disp, XRootWindow(disp, 0), &win_ret, &win_ret, &cur_x, &cur_y, &win_x, &win_y, &mask_ret);
            XCloseDisplay(disp);
            return Vector2D(cur_x, cur_y);
        #endif

        return Vector2D();
    }

    /*
        Sets the mouse position.
        Parametres:
            pos - 2d Vector of the desired X and Y mouse pos
    */
    static void set_pos(Vector2D pos)
    {
        #ifdef _WIN32
            SetCursorPos(pos.int_X(), pos.int_Y());
        #endif

        #ifdef __linux__
            Display* disp = XOpenDisplay(0);
            Window win_root = XRootWindow(disp, 0);
            XSelectInput(disp, win_root, KeyReleaseMask);
            XWarpPointer(disp, None, win_root, 0, 0, 0, 0, pos.int_X(), pos.int_Y());
            XFlush(disp);
            XCloseDisplay(disp);
        #endif
    }
};