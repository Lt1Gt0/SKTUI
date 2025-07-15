#include "elements/border.h"
#include "terminal/literals.h"

namespace SKTUI 
{
    BorderOutline::BorderOutline()
    {
        mTopLeft = BD_SINGLE_TL;
        mTopRight = BD_SINGLE_TR;
        mBottomLeft = BD_SINGLE_BL;
        mBottomRight = BD_SINGLE_BR;
    }

    BorderOutline::BorderOutline(const char* topLeft, const char* topRight, const char* bottomLeft, const char* bottomRight)
    {
        mTopLeft = topLeft;
        mTopRight = topRight;
        mBottomLeft = bottomLeft;
        mBottomRight = bottomRight;
    }

    BorderOutline::~BorderOutline() { }

    Border::Border(int winID, Point size, Point pos) : ElementBase(winID, size, pos)
    {
        mOutline = BorderOutline();
    }

    Border::~Border() { }

    BorderOutline Border::GetOutline()
    {
        return mOutline;
    }

    void Border::SetOutlineSingle()
    {
        mOutline.mTopLeft = BD_SINGLE_TL;
        mOutline.mTopRight = BD_SINGLE_TR;
        mOutline.mBottomLeft = BD_SINGLE_BL;
        mOutline.mBottomRight = BD_SINGLE_BR;
    }

    void Border::SetOutlineDouble()
    {
        mOutline.mTopLeft = BD_DOUBLE_TL;
        mOutline.mTopRight = BD_DOUBLE_TR;
        mOutline.mBottomLeft = BD_DOUBLE_BL;
        mOutline.mBottomRight = BD_DOUBLE_BR;
    }

    void Border::SetOutlineCustom(const BorderOutline& borderOutline)
    {
        mOutline = borderOutline;
    }

    void Border::UpdatePixelMap()
    {
        for (int i = 0; i < mSize.Y; i++) {
            for (int j = 0; j < mSize.X; j++) {
                mPixelMap[i][j]->mChar = G_BLANK;
            }
        }

        // Set up where the corners will be
        mPixelMap[0][0]->mChar = mOutline.mTopLeft;
        mPixelMap[0][mSize.X - 1]->mChar = mOutline.mTopRight;
        mPixelMap[mSize.Y - 1][0]->mChar = mOutline.mBottomLeft;
        mPixelMap[mSize.Y - 1][mSize.X - 1]->mChar = mOutline.mBottomRight;

        // Print col verticals
        for (int i = 1; i < mSize.Y - 1; i++) {
            mPixelMap[i][0]->mChar = G_VERTICAL;
            mPixelMap[i][mSize.X - 1]->mChar = G_VERTICAL;
        }
        
        // Print row horizontals
        for (int i = 1; i < mSize.X - 1; i++) {
            mPixelMap[0][i]->mChar = G_HORIZONTAL;
            mPixelMap[mSize.Y - 1][i]->mChar = G_HORIZONTAL;
        }
    }
}
