#include "elements/border.h"
#include "terminal/literals.h"

#include <iostream>

namespace SKTUI 
{
    Border::Border(int winID, Point size, Point pos) : ElementBase(winID, size, pos)
    {
        if (pos.X == UNDEFINED_POS && pos.Y == UNDEFINED_POS)
            mStartPos = {0, 0};
        else
            mStartPos = pos;

        if (size.X == UNDEFINED_DIM && size.Y == UNDEFINED_DIM)
            mSize = mWindow->GetSize();
        else
            mSize = size;
    }

    Border::~Border()
    {

    }
   
    void Border::UpdatePixelMap()
    {
        std::cout << "Calling border update\n";
        Pixel p = Pixel(); 
        p.mChar = D_BD_TL;
        mPixelMap[0][0] = p;
    }

    void Border::Draw()
    {
        for (auto row : mPixelMap) {
            for (auto col : row) {
                std::cout << col.mChar;
            }
        }
    }
}
