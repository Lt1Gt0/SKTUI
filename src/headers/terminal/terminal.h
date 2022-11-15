#pragma once
#ifndef _SKTUI_TERMINAL_H
#define _SKTUI_TERMINAL_H

#include "util.h"

namespace SKTUI 
{
    namespace Terminal
    {
        void SetSignalHandlers();
        Dimension size(); 
    }
}

#endif // _SKTUI_TERMINAL_H
