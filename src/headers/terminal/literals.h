#pragma once
#ifndef _SKTUI_TERMINAL_LITERALS
#define _SKTUI_TERMINAL_LITERALS

namespace SKTUI
{
    constexpr const char BLANK = ' ';

    /* 
     * BOX LITERALS
     * Border literals will be prefixed with BD_
     * Border defaults will be prefixed with D_ 
     * Border derivatives will be postfixed with _<Derived>
     *      Example BD_TL_DOUBLE ("╔" u2554) 
     *
     * (These are defaults, there are derived options)
     * VERTICAL -> │ (u2500)
     * HORIZONTAL -> ─ (u2502)
     * TL (Top Left) -> ┌ (u250C)
     * TR (Top Right) -> ┐ (u2510)
     * BL (Bottom Left) -> └ (u2514)
     * BR (Bottom Right) -> ┘ (u2518)
     *
     * ┌─────────┐
     * │         │
     * └─────────┘
     * ┌┐
     * └┘
     **/

    // BOX LITERALS
    constexpr const char D_BD_HORIZONTAL[4] = "\u2500";
    constexpr const char D_BD_VERTICAL[4] = "\u2502";
    constexpr const char D_BD_TL[4] = "\u250C";
    constexpr const char D_BD_TR[4] = "\u2510";
    constexpr const char D_BD_BL[4] = "\u2514";
    constexpr const char D_BD_BR[4] = "\u2518";
    //
}

#endif // _SKTUI_TERMINAL_LITERALS
