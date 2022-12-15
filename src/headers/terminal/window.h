#pragma once
#ifndef _SKTUI_WINDOW_H
#define _SKTUI_WINDOW_H

#include "util.h"
#include "terminal/pixel.h"
#include "elements/elementbase.h"
#include <vector>
#include <string>
#include <atomic>

template<typename T>
using Vec = std::vector<T>;

namespace SKTUI 
{
    class Window 
    {
        public:
            int mID;

            static std::atomic_int currentID;

            Window();
            Window(Dimension size);
            ~Window();

            void Draw();
            void AddElement(ElementBase element);
            Vec<Vec<Pixel>> GetPixelMap();

        protected:
            void PreInit();
            std::string ToString();
            //void Draw();
            void Print();

            Dimension mSize;
            Vec<Vec<Pixel>> mPixels;
    };
}

#endif // _SKTUI_WINDOW_H
