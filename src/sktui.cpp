#include "sktui.h"
#include "terminal/terminal.h"
#include <iostream>
#include <signal.h>
#include <atomic>
#include <locale.h>
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
    }

    void Init()
    {
        Terminal::GetInstance()->SetTerminalAttributes();
        std::atexit(CleanSKTUI);
    }

    void RenderLoop()
    {
        Terminal* t = Terminal::GetInstance();
        while (1) {
            fputs("\033c", stdout);
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
