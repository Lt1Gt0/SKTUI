#include "terminal/terminal.h"

#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>

namespace SKTUI
{
    namespace Terminal
    {
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
