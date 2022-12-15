#pragma once
#ifndef _SKTUI_UTIL_H
#define _SKTUI_UTIL_H

#include <stddef.h>
#include <stdint.h>

namespace SKTUI 
{
    constexpr int UNDEFINED_DIM = -1;
    constexpr int UNDEFINED_POS = -1;

    struct Point {
        int X;
        int Y;
    };
}

#endif // _SKTUI_UTIL_H
