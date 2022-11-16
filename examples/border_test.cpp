#include <iostream>
#include "sktui.h"
#include "terminal/screen.h"

int main() {
    using namespace SKTUI;
    std::cout << "border test" << std::endl;
    
    SKTUI::Init();
    Screen s;
    s.Loop();

    return 0;
}
