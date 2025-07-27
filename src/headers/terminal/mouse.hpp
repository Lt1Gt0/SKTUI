#pragma once
#ifndef _MOUSE_HPP_
#define _MOUSE_HPP_

namespace SKTUI
{
    // https://invisible-island.net/xterm/ctlseqs/ctlseqs.html#h2-Mouse-Tracking
    constexpr int XTERM_SET_X10_MOUSE               {9};
    constexpr int XTERM_SET_VT200_MOUSE             {1000};
    constexpr int XTERM_SET_VT200_HIGHLIGHT_MOUSE   {1001};
    constexpr int XTERM_SET_BTN_EVENT_MOUSE         {1002};
    constexpr int XTERM_SET_ANY_EVENT_MOUSE         {1003};
    
    constexpr int XTERM_SET_FOCUS_EVENT_MOUSE       {1004};
    
    constexpr int XTERM_SET_ALTERNATE_SCROLL        {1007};
    
    constexpr int XTERM_SET_EXT_MODE_MOUSE          {1005};
    constexpr int XTERM_SET_SGR_EXT_MODE_MOUSE      {1006};
    constexpr int XTERM_SET_URXVT_EXT_MODE_MOUSE    {1015};
    constexpr int XTERM_SET_PIXEL_POSITION_MOUSE    {1016};
}

#endif // _MOUSE_HPP_
