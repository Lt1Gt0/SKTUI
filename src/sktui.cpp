#include "sktui.h"
#include "terminal/terminal.h"
#include <iostream>
#include <signal.h>


namespace SKTUI
{
    Terminal* Terminal::tInstance = new Terminal();
    static bool bSignalsHandled = false;

    static void SigIntHandler(int sig)
    {
        std::cerr << "TODO: Handle sigint properly" << std::endl;
        std::cerr << "Sig int got: " << sig << std::endl;
        exit(-1);
    }

    static void SetSignalHandlers()
    {
        if (bSignalsHandled) {
            std::cerr << "Signals have already been handled" << std::endl;
            return;
        }
        
        signal(SIGINT, SigIntHandler);

        bSignalsHandled = true;
    }

    void Init()
    {
        SetSignalHandlers();
    }

    void Render()
    {
        Terminal* t = Terminal::GetInstance();

    }
}
