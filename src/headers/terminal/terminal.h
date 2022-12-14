#pragma once
#ifndef _SKTUI_TERMINAL_H
#define _SKTUI_TERMINAL_H

#include "util.h"
#include "terminal/window.h"

#include <vector>

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

            Dimension GetSize();
            void SetSize(Dimension newSize);

        private:
            static Terminal* tInstance;
            Dimension mSize;
            std::vector<Window*> mWindows;

            /* Will return a new window handle */
            int AddWindow(Window* win);
            void RemoveWindow(int winHandle);

            Terminal()
            {

            }
    };

    //namespace Terminal
    //{
        //void SetSignalHandlers();
        //Dimension size(); 
        //void AddWindow(Window* win);
        //void Render();
    //}
}

#endif // _SKTUI_TERMINAL_H
