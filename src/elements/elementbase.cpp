#include "elements/elementbase.hpp"
#include "terminal/terminal.hpp"

#include <string>

namespace SKTUI 
{
    ElementBase::ElementBase(int winID, Point size, Point pos)
    {
        mWindow = Terminal::GetInstance()->FindWindow(winID);

        // --- TODO ---
        // Calculate next offset depending on previous or current
        // elements on window
        //
        // This could be a flag passed into the window to determine if
        // new elements with undefined positions should just overide the 
        // top most element or if they should attempt to find a new
        // poision to the [left, right, up, down] of the nearest
        // element (flag passed to window to determine these actions)
        //
        // If the flag is passed to determine the next position is set
        // there should also be another flag to determine if the new
        // calculated position should also dynamically determine the
        // padding between elements
        // ------------
        if (pos.X == UNDEFINED_POS && pos.Y == UNDEFINED_POS) {
            mStartPos = {0, 0};
        } else {
            mStartPos = pos;
        }

        // FIXME
        if (size.X == UNDEFINED_DIM)
            mSize.X = 0;
        else
            mSize.X = size.X;

        // FIXME
        if (size.Y == UNDEFINED_DIM)
            mSize.Y = 0;
        else
            mSize.Y = size.Y;

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
