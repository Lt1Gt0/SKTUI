#include "terminal/terminal.h"

#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

#include <iostream>
#include <vector>

namespace SKTUI
{
    // TERMINAL SIGNALS
    static void SigIntHandler(int sig)
    {
        std::cerr << "TODO: Handle sigint properly\n\r";
        std::cerr << "Sig int got: " << sig << "\n\r";
        exit(-1);
    }

    static void SigWinchHandler(int sig) 
    {
        winsize ws;

        if (ioctl(fileno(stdout), TIOCGWINSZ, &ws)) {
            std::cerr << "Unable to handle window size change\nExiting...\n\r";
            exit(-1);
        }

        std::cout << "Window size changed\n\r";
        Terminal::GetInstance()->SetSize({ws.ws_col, ws.ws_row});
    }
    //////////////////// 

    Terminal::Terminal()
    {
        // Store original terminal attributes
        tcgetattr(fileno(stdout), &mOrigTerm);

        // Store initial terminal size
        winsize ws;
        ioctl(0, TIOCGWINSZ, &ws);
        SetSize({.X=ws.ws_col, .Y=ws.ws_row});
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
        tcsetattr(fileno(stdout), TCSANOW, &mCurrentTerm);
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

        std::cerr << "ID [" << winID << "] Not found\n\r";
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

        std::cerr << "ID [" << winID << "] Not found, so there is nothing to delete\n\r";
    }

    void TerminalHandleInput()
    {
        while (1) {
            char c;
            read(fileno(stdout), &c, 1);

            switch(c) {
                case CTRL('C'):
                {
                    SigIntHandler(SIGINT);
                    break;
                }
            }
        }
    }
}
