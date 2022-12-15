#include "sktui.h"
#include "terminal/terminal.h"
#include <iostream>
#include <signal.h>
#include <atomic>
#include <locale.h>
#include <sys/ioctl.h>

namespace SKTUI
{
    Terminal* Terminal::tInstance = new Terminal();
    std::atomic_int Window::currentID;

    static bool bSignalsHandled = false;

    static void SigIntHandler(int sig)
    {
        std::cerr << "TODO: Handle sigint properly" << std::endl;
        std::cerr << "Sig int got: " << sig << std::endl;
        exit(-1);
    }

    static void SigWinchHandler(int sig) 
    {
        winsize ws;

        if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws)) {
            std::cerr << "Unable to handle window size change\nExiting..." << std::endl;
            exit(-1);
        }

        Terminal::GetInstance()->SetSize({ws.ws_col, ws.ws_row});
    }

    static void SetSignalHandlers()
    {
        if (bSignalsHandled) {
            std::cerr << "Signals have already been handled" << std::endl;
            return;
        }
        
        signal(SIGINT, SigIntHandler);
        signal(SIGWINCH, SigWinchHandler);

        bSignalsHandled = true;
    }

    void Init()
    {
        SetSignalHandlers();
    }

    void Render()
    {
        Terminal* t = Terminal::GetInstance();

        for (auto it = t->mWindows.begin(); it != t->mWindows.end(); it++) {
            it->second.Loop();
        }
    }
}
