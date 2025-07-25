#pragma once
#ifndef _SKTUI_WINDOW_HPP_
#define _SKTUI_WINDOW_HPP_

#include "util.hpp"
#include "terminal/pixel.hpp"
#include "elements/elementbase.hpp"
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
            Window(Point size);
            ~Window();

            void Draw();
            void AddElement(ElementBase* element);
            Point GetSize();
            void SetSize(Point size);

            // FIXME
            // Should return flattened pixel map later
            Vec<Vec<Pixel*>> GetPixelMap();

        protected:
            void PreInit();
            std::string ToString();
            //void Draw();
            void Print();

            Point mSize;
            Vec<ElementBase*> mElements;

            // FIXME
            // Should be flattened pixel map
            Vec<Vec<Pixel*>> mPixels;
    };
}

#endif // _SKTUI_WINDOW_HPP_
