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
            ElementBase(int winID, Point size = {UNDEFINED_DIM, UNDEFINED_DIM}, Point pos = {UNDEFINED_POS, UNDEFINED_POS});
            ~ElementBase();

            virtual void Draw();

        protected:
            Window* mWindow;
            Vec<Vec<Pixel>> mPixelMap;
            Point mSize;
            Point mPos;
    };
}

#endif // _SKTUI_ELEMENT_BASE_H
