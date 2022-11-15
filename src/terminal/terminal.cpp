#include "terminal/terminal.h"

#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <iostream>

namespace SKTUI
{
    namespace Terminal
    {
        static bool bSignalsHandled = false;

        static void SigIntHandler(int sig)
        {
            std::cerr << "TODO: Handle sigint properly" << std::endl;
            std::cerr << "Sig int got: " << sig << std::endl;
            exit(-1);
        }

        void SetSignalHandlers()
        {
            if (bSignalsHandled) {
                std::cerr << "Signals have already been handled" << std::endl;
                return;
            }
            
            signal(SIGINT, SigIntHandler);

            bSignalsHandled = true;
        }

        Dimension size() 
        {
            winsize ws;
            if (ioctl(fileno(stdout), TIOCGWINSZ, &ws) == -1) {
                fprintf(stderr, "Unable to get terminal size");
                abort();
            }

            return {ws.ws_row, ws.ws_col};
        }
    }
}
