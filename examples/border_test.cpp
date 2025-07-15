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

    Border border = Border(win, {10, 10}, {0, 1});
    Border border2 = Border(win, {20, 10}, {10, 11});

    // Set outline
    BorderOutline customOutline = BorderOutline("a", "a", "a", "a");
    border2.SetOutlineCustom(customOutline);


    mainWin->AddElement(&border);
    mainWin->AddElement(&border2);

    SKTUI::Render();

    return 0;
}
