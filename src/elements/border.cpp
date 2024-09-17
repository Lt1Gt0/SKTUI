#include "elements/border.h"
#include "terminal/literals.h"

namespace SKTUI 
{
    Border::Border(int winID, Point size, Point pos) : ElementBase(winID, size, pos) { }
    Border::~Border() { }
   
    void Border::UpdatePixelMap()
    {
        for (size_t i = 0; i < mPixelMap.size(); i++) {
            for (size_t j = 0; j < mPixelMap[i].size(); j++) {
                mPixelMap[i][j]->mChar = D_BD_TL;
            }
        }
    }
}
