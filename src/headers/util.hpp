#pragma once
#ifndef _SKTUI_UTIL_HPP_
#define _SKTUI_UTIL_HPP_

#include <stddef.h>
#include <stdint.h>

#define CTRL_KEY(k) ((k) & (0x1F))

namespace SKTUI 
{
    constexpr int UNDEFINED_DIM = -1;
    constexpr int UNDEFINED_POS = -1;

    struct Point {
        int X;
        int Y;
    };
}

#endif // _SKTUI_UTIL_HPP_
