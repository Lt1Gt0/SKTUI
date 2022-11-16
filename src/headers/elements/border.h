#pragma once
#ifndef _SKTUI_ELEMENT_BORDER_H
#define _SKTUI_ELEMENT_BORDER_H

#include "elements/elementbase.h"
#include "terminal/screen.h"

namespace SKTUI 
{
    class Border : public ElementBase 
    {
        public:
            Border(Screen* screen) : ElementBase(screen)
            {          

            }

            ~Border();
            void Draw();
    };
}

#endif // _SKTUI_ELEMENT_BORDER_H
