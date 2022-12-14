#include "terminal/window.h"
#include "terminal/terminal.h"

#include <iostream>
#include <sstream>

namespace SKTUI 
{
    Window::Window()
    {
        mSize = Terminal::size();
        PreInit();
    }

    Window::Window(Dimension size)
    {
        mSize = size;
        PreInit();
    }

    Window::~Window()
    {

    } 
    
    // Initialize class members
    void Window::PreInit()
    {
        // Initialize enough size to fit the screen
        mPixels.reserve(mSize.Y);
    }

    void Window::Loop()
    {
        while (1) {
            Draw();
        }
    }

    void Window::Draw()
    {
        //if (mBorderVisible)
            //mBorder.Draw();

        Print();
    }

    void Window::Print()
    {
        std::cout << ToString() << '\0';
        std::cout << std::flush;
    }

    std::string Window::ToString()
    {
        std::stringstream strWindow; 
        for (Vec<Pixel> row : mPixels) {
            for (Pixel col : row) {
                strWindow << col.mChar;
            }

            strWindow << "\n";
        }

        return strWindow.str();
    }

    //template<typename E_BASE>
    //void Window::AddElement(E_BASE& element)
    //{
        //ElementBase* e = (ElementBase*)&element;
    //}
}
