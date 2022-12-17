#pragma once
#ifndef _SKTUI_ELEMENT_BORDER_H
#define _SKTUI_ELEMENT_BORDER_H

#include "elements/elementbase.h"
#include "terminal/window.h"

namespace SKTUI 
{
    class Border : public ElementBase 
    {
        public:
            Border(int winID, Point size = {UNDEFINED_DIM, UNDEFINED_DIM}, Point pos = {UNDEFINED_POS, UNDEFINED_POS});
            ~Border();
            void Draw();
            void UpdatePixelMap();
    };
}

#endif // _SKTUI_ELEMENT_BORDER_H
