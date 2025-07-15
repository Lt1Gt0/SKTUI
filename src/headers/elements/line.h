#pragma once
#ifndef _SKTUI_ELEMENT_LINE_H
#define _SKTUI_ELEMENT_LINE_H

#include "elements/elementbase.h"

namespace SKTUI 
{
    class Line : public ElementBase 
    {
        public:
            Line(int winID, Point size = {UNDEFINED_DIM, UNDEFINED_DIM}, Point pos = {UNDEFINED_POS, UNDEFINED_POS});
            ~Line();

            void UpdatePixelMap();
    };
}

#endif // _SKTUI_ELEMENT_LINE_H
