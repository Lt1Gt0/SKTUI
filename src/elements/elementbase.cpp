#include "elements/elementbase.h"
#include "terminal/terminal.h"

#include <string>

namespace SKTUI 
{
    ElementBase::ElementBase(int winID, Point size, Point pos)
    {
        mWindow = Terminal::GetInstance()->FindWindow(winID);

        if (pos.X == UNDEFINED_POS && pos.Y == UNDEFINED_POS)
            mStartPos = {0, 0};
        else
            mStartPos = pos;

        if (size.X == UNDEFINED_DIM && size.Y == UNDEFINED_DIM)
            mSize = mWindow->GetSize();
        else
            mSize = size;

        mWindowPixelMap = mWindow->GetPixelMap();
        for (int i = 0; i < mSize.Y; i++) {
            Vec<Pixel*> row = Vec<Pixel*>(mSize.X);

            for (int j = 0; j < mSize.X; j++) {
                row[j] = new Pixel;
            }

            mPixelMap.push_back(row);
        }
    }

    void ElementBase::UpdatePixelMap()
    {
        // As a default update loop, clear the pixel map
        for (size_t row = 0; row < mPixelMap.size(); row++) {
            for (size_t col = 0; col < mPixelMap[row].size(); col++) {
                mPixelMap[row][col]->mChar = '-';
            }
        }
    }

    void ElementBase::Draw()
    {
        for (size_t row = 0; row < mPixelMap.size(); row++) {
            for (size_t col = 0; col < mPixelMap[row].size(); col++) {
                *mWindowPixelMap[row + mStartPos.Y][col + mStartPos.X] = *mPixelMap[row][col];
            }
        }
    }
}
