#include "terminal/screen.h"
#include "terminal/terminal.h"

#include <iostream>
#include <sstream>

namespace SKTUI 
{
    Screen::Screen()
    {
        mSize = Terminal::size();
        mBorderVisible = true;
        preInit();
    }

    Screen::Screen(Dimension size)
    {
        mSize = size;
        mBorderVisible = false;
        preInit();
    }

    Screen::Screen(Dimension size, bool borderVisible)
    {
        mSize = size;
        mBorderVisible = borderVisible;
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
        mBorder = Border();
    }

    void Screen::Loop()
    {
        while (1) {
            Draw();
        }
    }

    void Screen::Draw()
    {
        if (mBorderVisible)
            mBorder.Draw();

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
