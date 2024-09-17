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
    Border border = Border(win, {0, 0}, {10, 10});

    Point size = term->GetSize();
    std::cout << size.X << " : " << size.Y << "\n";

    // border.UpdatePixelMap();
    // border.Draw();

    SKTUI::Render();

    return 0;
}
