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
            Border(int winID, Dimension size = {-1, -1}, Dimension pos = {-1, -1});
            ~Border();
            void Draw();
    };
}

#endif // _SKTUI_ELEMENT_BORDER_H
