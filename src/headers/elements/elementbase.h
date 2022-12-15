#pragma once
#ifndef _SKTUI_ELEMENT_BASE_H
#define _SKTUI_ELEMENT_BASE_H

#include "terminal/pixel.h"
#include "util.h"
#include <vector>

template<typename T>
using Vec = std::vector<T>;

namespace SKTUI 
{
    class Window;
    class ElementBase
    {
        public:
            ElementBase(int winID, Dimension size = {-1, -1}, Dimension pos = {-1, -1});
            ~ElementBase();

            virtual void Draw();

        protected:
            Window* mWindow;
            Vec<Vec<Pixel>> mPixelMap;
            Dimension mSize;
            Dimension mPos;
    };
}

#endif // _SKTUI_ELEMENT_BASE_H
