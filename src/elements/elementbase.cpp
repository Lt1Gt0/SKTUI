#include "elements/elementbase.h"
#include "terminal/terminal.h"

#include <string>

namespace SKTUI 
{
    ElementBase::ElementBase(int winID, Point size, Point pos)
    {
        if (pos.X == UNDEFINED_POS && pos.Y == UNDEFINED_POS)
            mStartPos = {0, 0};
        else
            mStartPos = pos;

        if (size.X == UNDEFINED_DIM && size.Y == UNDEFINED_DIM)
            mSize = mWindow->GetSize();
        else
            mSize = size;

        mWindow = Terminal::GetInstance()->FindWindow(winID);
        mWindowPixelMap = mWindow->GetPixelMap();

        for (int i = 0; i < mSize.Y; i++) {
            Vec<Pixel> row = Vec<Pixel>(mSize.X);

            for (int j = 0; j < mSize.X; j++) {
                row[j] = Pixel();
            }

            mPixelMap.push_back(row);
        }
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
