#include "elements/line.hpp"

namespace SKTUI 
{
    Line::Line(int winID, Point size, Point pos) : ElementBase(winID, size, pos) { }
    Line::~Line() { }

    void Line::UpdatePixelMap()
    {
    }
}
