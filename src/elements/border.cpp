#include "elements/border.h"
#include "terminal/literals.h"
#include <iostream>

namespace SKTUI 
{
    Border::Border(int winID, Point size, Point pos) : ElementBase(winID, size, pos)
    {
        if (pos.X == UNDEFINED_POS && pos.Y == UNDEFINED_POS)
            mPos = {0, 0};
        else
            mPos = pos;

        if (size.X == UNDEFINED_DIM && size.Y == UNDEFINED_DIM)
            mSize = mWindow->GetSize();
        else
            mSize = size;
    }

    Border::~Border()
    {

    }

    void Border::Draw()
    {
        Pixel p = Pixel(); 
        p.mChar = D_BD_TL;
        mPixelMap[0][0] = p;
    }
}
