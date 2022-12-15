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

    int Terminal::NewWindow() 
    {
        Window win = Window();
        mWindows.insert({win.mID, win});
        return win.mID;
    }

    Window* Terminal::FindWindow(int winID)
    {
        for (auto it = mWindows.begin(); it != mWindows.end(); it++) {
            if ((int)it->first == winID) {
                it = mWindows.erase(it);
                std::cout << "Found id: " << winID << "...\nRemoving...\n";
                return &it->second;
            }
        }

        std::cerr << "ID [" << winID << "] Not found\n";
        return nullptr;
    }

    void Terminal::RemoveWindow(int winID)
    {
        for (auto it = mWindows.begin(); it != mWindows.end(); it++) {
            if ((int)it->first == winID) {
                it = mWindows.erase(it);
                std::cout << "Found id: " << winID << "...\nRemoving...\n";
                return;
            }
        }

        std::cerr << "ID [" << winID << "] Not found, so there is nothing to delete\n";
    }
}
