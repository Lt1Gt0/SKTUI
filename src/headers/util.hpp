#pragma once
#ifndef _SKTUI_UTIL_HPP_
#define _SKTUI_UTIL_HPP_

#include <stddef.h>
#include <stdint.h>
#include <string>
#include <vector>

#define CTRL_KEY(k) ((k) & (0x1F))

namespace SKTUI 
{
    using namespace std;

    constexpr int UNDEFINED_DIM = -1;
    constexpr int UNDEFINED_POS = -1;

    struct Point {
        int X;
        int Y;
    };

    // I am writing this while being a little rusty with c++ so this
    // is by no means a good way to do this, once I get back into c++
    // programming I will update this
    inline vector<string> GetSupportedTerminals()
    {
        return vector<string> {
            "tmux-256color",
        };
    }

    inline bool IsSupportedTermType(std::string termType)
    {
        bool isSupported = false;

        for (std::string type : GetSupportedTerminals()) {
            if (type == termType) {
                isSupported = true;
                break;
            }
        }

        return isSupported;
    }
}

#endif // _SKTUI_UTIL_HPP_
