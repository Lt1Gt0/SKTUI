#pragma once
#ifndef _COLOR_HPP_
#define _COLOR_HPP_

#include <stdint.h>

namespace SKTUI
{
    enum Pallette {
        p1,
        p8,
        p256,
    };
    
    enum Pallette1 : uint8_t{

    };

    enum Pallette16 : uint8_t {

    };

    enum Pallette256 : uint8_t {

    };



    struct Color {
        Color RGB(int r, int g, int b);
    };
}

#endif // _COLOR_HPP_
