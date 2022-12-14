#include "terminal/terminal.h"

#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <vector>

namespace SKTUI
{
    Dimension Terminal::GetSize()
    {
        return this->mSize;
    }

    void Terminal::SetSize(Dimension newSize)
    {
        this->mSize = newSize;
    }

    int Terminal::AddWindow(Window* win) 
    {
        
    }

    void RemoveWindow(int winHandle)
    {

    }

    //std::vector<Window*> windows;

    //namespace Terminal
    //{
        //Dimension size() 
        //{
            //winsize ws;
            //if (ioctl(fileno(stdout), TIOCGWINSZ, &ws) == -1) {
                //fprintf(stderr, "Unable to get terminal size");
                //abort();
            //}

            //return {ws.ws_row, ws.ws_col};
        //}

        //void AddWindow(Window* win)
        //{
            //windows.push_back(win);
        //}

        //void Render()
        //{
            //for (Window* win : windows) {
                //win->Loop();
            //}
        //}
    //}
}
