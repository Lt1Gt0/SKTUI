#include <iostream>
#include "sktui.h"
#include "terminal/terminal.h"
#include "terminal/window.h"
#include "elements/border.h"

int main() {
    using namespace SKTUI;
    SKTUI::Init();

    std::cout << "Border Test\n\r";
    Terminal* term = Terminal::GetInstance();
    int win = term->NewWindow();
    Window* mainWin = term->FindWindow(win);

    Border border = Border(win);
    mainWin->AddElement(&border);

    SKTUI::Render();

    return 0;
}
