#include "elements/elementbase.h"
#include "terminal/terminal.h"

#include <string>

namespace SKTUI 
{
    ElementBase::ElementBase(int winID, Point size, Point pos)
    {
        mWindow = Terminal::GetInstance()->FindWindow(winID);
        mWindowPixelMap = mWindow->GetPixelMap();

        mSize = size;
        mStartPos = pos;
    }

    void ElementBase::UpdatePixelMap()
    {
        // As a default update loop, clear the pixel map
        for (int row = 0; row < mSize.Y; row++) {
            for (int col = 0; col < mSize.X; col++) {
                Pixel pixel = Pixel();
                pixel.mChar = '-';
                mPixelMap[row][col] = pixel;
            }
        }
        
    }

    void ElementBase::Draw()
    {
        for (int row = 0; row < mSize.Y; row++) {
            for (int col = 0; col < mSize.X; col++) {
                mWindowPixelMap[row + mStartPos.Y][col + mStartPos.X] = mPixelMap[row][col];
            }
        }
    }
}
