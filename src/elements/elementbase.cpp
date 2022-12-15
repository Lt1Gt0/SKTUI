#include "elements/elementbase.h"
#include "terminal/terminal.h"

#include <string>

namespace SKTUI 
{
    ElementBase::ElementBase(int winID, Point size, Point pos)
    {
        mWindow = Terminal::GetInstance()->FindWindow(winID);
        mPixelMap = mWindow->GetPixelMap();

        mSize = size;
        mPos = pos;
    }

    ElementBase::~ElementBase()
    {

    }

    void ElementBase::Draw()
    {
        //for (Vec<Pixel> row : mPixelMap) {
            //for (Pixel pixel : row) {
                //std::string pixelStr = pixel.
            //}
        //}
    }
}
