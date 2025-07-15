#pragma once
#ifndef _SKTUI_ELEMENT_BORDER_HPP_
#define _SKTUI_ELEMENT_BORDER_HPP_

#include "elements/elementbase.hpp"
// #include "terminal/window.h"

namespace SKTUI 
{
    struct BorderOutline {
        public: 
            BorderOutline();
            BorderOutline(const char* topLeft, const char* topRight, const char* bottomLeft, const char* bottomRight);
            ~BorderOutline();

            const char* mTopLeft;
            const char* mTopRight;
            const char* mBottomLeft;
            const char* mBottomRight;
    };

    class Border : public ElementBase 
    {
        public:
            Border(int winID, Point size = {UNDEFINED_DIM, UNDEFINED_DIM}, Point pos = {UNDEFINED_POS, UNDEFINED_POS});
            ~Border();

            // void Draw();
            void UpdatePixelMap();

            BorderOutline GetOutline();

            void SetOutlineSingle();
            void SetOutlineDouble();
            void SetOutlineCustom(const BorderOutline& borderOutline);

        private:
            BorderOutline mOutline;
    };
}

#endif // _SKTUI_ELEMENT_BORDER_HPP_
