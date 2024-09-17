#include "elements/border.h"
#include "terminal/literals.h"

namespace SKTUI 
{
    Border::Border(int winID, Point size, Point pos) : ElementBase(winID, size, pos) { }
    Border::~Border() { }
   
    void Border::UpdatePixelMap()
    {
        for (int i = 0; i < mSize.Y; i++) {
            for (int j = 0; j < mSize.X; j++) {
                mPixelMap[i][j]->mChar = "-";
            }
        }

        // Set up where the corners will be
        mPixelMap[0][0]->mChar = D_BD_TL;
        mPixelMap[0][mSize.X - 1]->mChar = D_BD_TR;
        mPixelMap[mSize.Y - 1][0]->mChar = D_BD_BL;
        mPixelMap[mSize.Y - 1][mSize.X - 1]->mChar = D_BD_BR;


        // Print col verticals
        for (int i = 1; i < mSize.Y - 1; i++) {
            mPixelMap[i][0]->mChar = D_BD_VERTICAL;
            mPixelMap[i][mSize.X - 1]->mChar = D_BD_VERTICAL;
        }
        
        // Print row horizontals
        for (int i = 1; i < mSize.X - 1; i++) {
            mPixelMap[0][i]->mChar = D_BD_HORIZONTAL;
            mPixelMap[mSize.Y - 1][i]->mChar = D_BD_HORIZONTAL;
        }
    }
}
