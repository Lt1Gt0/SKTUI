#include "terminal/terminal.h"

#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <vector>

namespace SKTUI
{
    Terminal::Terminal()
    {
        // Store original terminal attributes
        tcgetattr(fileno(stdout), &mCurrentTerm);
    }

    Point Terminal::GetSize()
    {
        return this->mSize;
    }

    void Terminal::SetSize(Point newSize)
    {
        this->mSize = newSize;
    }

    void Terminal::SetTerminalAttributes()
    {
        termios term = termios();

        // Default raw mode configuration from man page, subject to change
       term.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL | IXON);
       term.c_oflag &= ~OPOST;
       term.c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
       term.c_cflag &= ~(CSIZE | PARENB);
       term.c_cflag |= CS8;

       SetTerminalAttributes(term);
    }

    void Terminal::SetTerminalAttributes(termios newTerm)
    {
        mCurrentTerm = newTerm;
        tcsetattr(fileno(stdout), TCSAFLUSH, &mCurrentTerm);
    }

    void Terminal::ResetTerminalAttributes()
    {
        mCurrentTerm = mOrigTerm;
        tcsetattr(fileno(stdout), TCSAFLUSH, &mCurrentTerm);
    }


    int Terminal::NewWindow() 
    {
        Window win = Window();
        mWindows.insert({win.mID, win});
        return win.mID;
    }

    Window* Terminal::FindWindow(int winID)
    {
        for (auto it = mWindows.begin(); it != mWindows.end(); it++) {
            if ((int)it->first == winID)
                return &it->second;
        }

        std::cerr << "ID [" << winID << "] Not found\n";
        return nullptr;
    }

    void Terminal::RemoveWindow(int winID)
    {
        for (auto it = mWindows.begin(); it != mWindows.end(); it++) {
            if ((int)it->first == winID) {
                it = mWindows.erase(it);
                return;
            }
        }

        std::cerr << "ID [" << winID << "] Not found, so there is nothing to delete\n";
    }
}
