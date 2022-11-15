#pragma once
#ifndef _SKTUI_SCREEN_H
#define _SKTUI_SCREEN_H

#include "util.h"
#include "terminal/pixel.h"
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
            ~Screen();

            void Loop();

        protected:
            void preInit();
            std::string ToString();
            void Draw();
            void Print();

            Dimension mSize;
            Vec<Vec<Pixel>> mPixels;

        private:
    };
}

#endif // _SKTUI_SCREEN_H
