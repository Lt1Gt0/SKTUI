#pragma once
#ifndef _SKTUI_TERMINAL_H
#define _SKTUI_TERMINAL_H

#include "util.h"
#include "terminal/window.h"

#include <vector>
#include <unordered_map>

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

            /* Will return a new window handle */
            int NewWindow();
            Window* FindWindow(int winHandle);
            void RemoveWindow(int winHandle);

            std::unordered_map<uint32_t, Window> mWindows;

        private:
            static Terminal* tInstance;
            Dimension mSize;

            Terminal() {}
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
