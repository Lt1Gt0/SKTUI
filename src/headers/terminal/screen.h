#pragma once
#ifndef _SKTUI_SCREEN_H
#define _SKTUI_SCREEN_H

#include "util.h"
#include "terminal/pixel.h"
#include "elements/elementbase.h"
#include "elements/border.h"
#include <vector>
#include <string>

template<typename T>
using Vec = std::vector<T>;

namespace SKTUI 
{
    class Screen 
    {
        public:
            Screen();
            Screen(Dimension size);
            Screen(Dimension size, bool borderVisible);

            ~Screen();

            void Loop();
            void AddElement(ElementBase& element);

        protected:
            void preInit();
            std::string ToString();
            void Draw();
            void Print();

            Dimension mSize;
            Vec<Vec<Pixel>> mPixels;

            bool mBorderVisible;

        private:
            Border mBorder;
    };
}

#endif // _SKTUI_SCREEN_H
