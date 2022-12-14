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
    term->RemoveWindow(win);

    //Terminal::AddWindow(&win);
    
    //Terminal::Render();

    return 0;
}
