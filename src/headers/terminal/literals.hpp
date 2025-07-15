#pragma once
#ifndef _SKTUI_TERMINAL_LITERALS_HPP_
#define _SKTUI_TERMINAL_LITERALS_HPP_

namespace SKTUI
{
    /*
     * GENERIC LITERALS
     * Generic literals will be prefixed with "G_"
     *
     * VERTICAL -> │ (u2500)
     * HORIZONTAL -> ─ (u2502)
     **/

    // GENERICAL LITERAL
    constexpr const char G_BLANK = ' ';

    constexpr const char G_HORIZONTAL[4] = "\u2500";
    constexpr const char G_VERTICAL[4] = "\u2502";
    //

    /* 
     * BOX LITERALS
     * Border literals will be prefixed with "BD_"
     * Border derivatives will be postfixed with _<Derived>
     *      Example BD_TL_DOUBLE ("╔" u2554) 
     *
     * (These are defaults, there are derived options)
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
    constexpr const char BD_SINGLE_TL[4] = "\u250C";
    constexpr const char BD_SINGLE_TR[4] = "\u2510";
    constexpr const char BD_SINGLE_BL[4] = "\u2514";
    constexpr const char BD_SINGLE_BR[4] = "\u2518";

    // TODO
    constexpr const char BD_DOUBLE_TL[4] = "";
    constexpr const char BD_DOUBLE_TR[4] = "";
    constexpr const char BD_DOUBLE_BL[4] = "";
    constexpr const char BD_DOUBLE_BR[4] = "";
    //
    
    /*
     * LINE LITERALS
     * Line literals will be prefixed with "LN_"
     **/
    // LINE LITERALS
    //
}

#endif // _SKTUI_TERMINAL_LITERALS_HPP_
