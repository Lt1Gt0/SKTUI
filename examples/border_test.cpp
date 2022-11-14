#include <iostream>
#include "terminal/terminal.h"

int main() {
    using namespace SKTUI;
    std::cout << "border test" << std::endl;
    Dimension tSize = Terminal::size();

    std::cout << "Terminal Size X: " << tSize.X << "\n";
    std::cout << "Terminal Size Y: " << tSize.Y << "\n";

    return 0;
}
