#include "terminal/screen.h"
#include "terminal/terminal.h"

#include <iostream>
#include <sstream>

namespace SKTUI 
{
    Screen::Screen()
    {
        mSize = Terminal::size();
        preInit();
    }

    Screen::Screen(Dimension size)
    {
        mSize = size;
        preInit();
    }

    Screen::~Screen()
    {

    } 
    
    // Initialize class members
    void Screen::preInit()
    {
        // Initialize enough size to fit the screen
        mPixels.reserve(mSize.Y);
    }

    void Screen::Loop()
    {

        Draw();
    }

    void Screen::Draw()
    {
        Print();
    }

    void Screen::Print()
    {
        std::cout << ToString() << '\0';
        std::cout << std::flush;
    }

    std::string Screen::ToString()
    {
        std::stringstream strScreen; 
        for (Vec<Pixel> row : mPixels) {
            for (Pixel col : row) {
                strScreen << col.mChar;
            }

            strScreen << "\n";
        }

        return strScreen.str();
    }
}
