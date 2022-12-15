#pragma once
#ifndef _SKTUI_UTIL_H
#define _SKTUI_UTIL_H

#include <stddef.h>
#include <stdint.h>

namespace SKTUI 
{
    constexpr size_t UNDEFINED_DIM = -1;
    constexpr size_t UNDEFINED_POS = -1;

    struct Dimension {
        size_t X; // Total width (x-axis)
        size_t Y; // Total height (y-axis)
    };
    
    struct Position {
        size_t X;
        size_t Y;
    };
}

#endif // _SKTUI_UTIL_H
