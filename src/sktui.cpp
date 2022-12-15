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

    void Render()
    {
        Terminal* t = Terminal::GetInstance();

        std::thread tTermInput(TerminalHandleInput);
        tTermInput.join();


        while (1) {
            for (auto it = t->mWindows.begin(); it != t->mWindows.end(); it++) {
                it->second.Draw();
            }
        }
    }
}
