#include "sktui.hpp"
#include "terminal/terminal.hpp"
#include "terminal/mouse.hpp"

#include "util.hpp"
#include <iostream>
#include <signal.h>
#include <atomic>
#include <locale.h>
#include <string>
#include <sys/ioctl.h>
#include <termios.h>
#include <thread>

namespace SKTUI
{
    Terminal* Terminal::tInstance = new Terminal();
    std::atomic_int Window::currentID;

    static void CleanSKTUI()
    {
        Terminal::GetInstance()->ResetTerminalAttributes();

        // Disable mouse move tracking
        char xterm_set_buf[20];
        sprintf(xterm_set_buf, "\x1B[?%dl", XTERM_SET_ANY_EVENT_MOUSE);
        std::cout << xterm_set_buf;
    }

    void Init()
    {
        std::string termType = Terminal::GetInstance()->GetTermType();
        if (!IsSupportedTermType(termType))
            std::cerr << "Terminal Type [" << termType << "] has not been tested... Possible errors may occur\n";

        Terminal::GetInstance()->SetTerminalAttributes();
        std::atexit(CleanSKTUI);
    }

    void RenderLoop()
    {
        Terminal* t = Terminal::GetInstance();
        while (1) {
            // ANSI escape code to clear screen and move cursor to top-left
            std::cout << "\x1B[2J"; // Erase screen
            std::cout << "\x1B[H"; // Move cursor to 0,0

            for (auto it = t->mWindows.begin(); it != t->mWindows.end(); it++) {
                it->second.Draw();
            }
        }
    }

    void Render()
    {
        std::thread tTermInput(TerminalHandleInput);
        std::thread tTermRender(RenderLoop);
        tTermInput.join();
        tTermRender.join();
    }
}
