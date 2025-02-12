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
        for (int i = 0; i < mSize.Y; i++) {
            Vec<Pixel*> row = Vec<Pixel*>(mSize.X);

            for (int j = 0; j < mSize.X; j++) {
                row[j] = new Pixel;
            }

            mPixels.push_back(row);
        }
    }

    void Window::Draw()
    {
        for (ElementBase* element : mElements) {
            element->UpdatePixelMap();
            element->Draw();
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

    Vec<Vec<Pixel*>> Window::GetPixelMap()
    {
        return mPixels;
    }

    void Window::Print()
    {
        std::cout << ToString() << '\0';
    }

    std::string Window::ToString()
    {
        // std::stringstream strWindow; 
        std::string strWindow;
        for (auto row : mPixels) {
            for (auto col : row) {
                strWindow += col->mChar;
            }

            strWindow += "\n\r";
        }

        return strWindow;
    }

    void Window::AddElement(ElementBase* element)
    {
        mElements.push_back(element);
    }
}
