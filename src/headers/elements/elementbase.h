#pragma once
#ifndef _SKTUI_ELEMENT_BASE_H
#define _SKTUI_ELEMENT_BASE_H

#include "terminal/screen.h"

namespace SKTUI 
{
    class ElementBase
    {
        public:
            ElementBase(Screen* screen);
            ~ElementBase();

            virtual void Draw();
    };
}

#endif // _SKTUI_ELEMENT_BASE_H
