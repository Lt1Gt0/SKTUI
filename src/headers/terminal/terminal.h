#pragma once
#ifndef _SKTUI_TERMINAL_H
#define _SKTUI_TERMINAL_H

#include "util.h"
#include "terminal/window.h"

#include <vector>
#include <unordered_map>
#include <termios.h>

namespace SKTUI 
{
    // Singleton class
    class Terminal 
    {
        public:
            Terminal(const Terminal& obj) = delete;
            static Terminal* GetInstance()
            {
                return tInstance;
            }

            Point GetSize();
            void SetSize(Point newSize);

            void SetTerminalAttributes();
            void SetTerminalAttributes(termios newTerm);
            void ResetTerminalAttributes();

            /* Will return a new window handle */
            int NewWindow();
            Window* FindWindow(int winHandle);
            void RemoveWindow(int winHandle);

            std::unordered_map<uint32_t, Window> mWindows;

        private:
            Terminal();

            static Terminal* tInstance;
            Point mSize;
            termios mOrigTerm;
            termios mCurrentTerm;
    };

    void TerminalHandleInput();
}

#endif // _SKTUI_TERMINAL_H
