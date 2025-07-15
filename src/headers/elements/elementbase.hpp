#pragma once
#ifndef _SKTUI_ELEMENT_BASE_HPP_
#define _SKTUI_ELEMENT_BASE_HPP_

#include "terminal/pixel.hpp"
#include "util.hpp"
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
            virtual ~ElementBase() {};

            virtual void Draw();
            virtual void UpdatePixelMap();

        protected:
            Window* mWindow;

            // FIXME
            // In the future before the codebase because much larger
            // I would like to convert these into flattened vectors
            // to reduce execution times
            Vec<Vec<Pixel*>> mWindowPixelMap;
            Vec<Vec<Pixel*>> mPixelMap;

            Point mSize;
            Point mStartPos;
            Point mRenderPos;
    };
}

#endif // _SKTUI_ELEMENT_BASE_HPP_
