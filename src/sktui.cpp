#include "sktui.h"
#include "terminal/terminal.h"

namespace SKTUI
{
    void Init()
    {
        Terminal::SetSignalHandlers();
    }
}
