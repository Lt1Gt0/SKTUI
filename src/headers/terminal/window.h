#pragma once
#ifndef _SKTUI_WINDOW_H
#define _SKTUI_WINDOW_H

#include "util.h"
#include "terminal/pixel.h"
//#include "elements/elementbase.h"
//#include "elements/border.h"
#include <vector>
#include <string>

template<typename T>
using Vec = std::vector<T>;

namespace SKTUI 
{
    class Window 
    {
        public:
            Window();
            Window(Dimension size);
            ~Window();

            void Loop();

            //template<typename E_BASE>
            //void AddElement(E_BASE& element);

        protected:
            void PreInit();
            std::string ToString();
            void Draw();
            void Print();

            Dimension mSize;
            Vec<Vec<Pixel>> mPixels;
    };
}

#endif // _SKTUI_WINDOW_H
