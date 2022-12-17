#include "terminal/window.h"
#include "terminal/terminal.h"

#include <iostream>
#include <sstream>

namespace SKTUI 
{
    Window::Window() : mID(currentID++)
    {
        mSize = Terminal::GetInstance()->GetSize();
        PreInit();
    }

    Window::Window(Point size)
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

    void Window::Draw()
    {
        for (ElementBase element : mElements) {
            element.UpdatePixelMap();
        }

        Print();
    }

    Point Window::GetSize()
    {
        return mSize;
    }

    void Window::SetSize(Point size)
    {
        mSize = size;
    }

    Vec<Vec<Pixel>> Window::GetPixelMap()
    {
        return mPixels;
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

    void Window::AddElement(ElementBase element)
    {
        mElements.push_back(element);
    }
}
