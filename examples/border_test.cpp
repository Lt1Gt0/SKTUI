#include <iostream>
#include "sktui.h"
#include "terminal/terminal.h"
#include "terminal/window.h"
#include "elements/border.h"

int main() {
    using namespace SKTUI;
    SKTUI::Init();

    Terminal* term = Terminal::GetInstance();
    int win = term->NewWindow();
    SKTUI::Render();

    return 0;
}
