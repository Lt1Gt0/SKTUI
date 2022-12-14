#include <iostream>
#include "sktui.h"
#include "terminal/terminal.h"
#include "terminal/window.h"
#include "elements/border.h"

int main() {
    using namespace SKTUI;
    std::cout << "border test" << std::endl;
    
    SKTUI::Init();
    Window win = Window();
    Terminal::AddWindow(&win);
    

    Terminal::Render();

    return 0;
}
