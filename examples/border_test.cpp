#include <iostream>
#include "sktui.h"
#include "terminal/terminal.h"
#include "terminal/window.h"
#include "elements/border.h"

int main() {
    using namespace SKTUI;
    SKTUI::Init();

    std::cout << "Border Test" << std::endl;
    Terminal* term = Terminal::GetInstance();
    int win = term->NewWindow();
    Border border = Border(win);

    //SKTUI::Render();

    return 0;
}
