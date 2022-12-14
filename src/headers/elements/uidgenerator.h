#pragma once
#ifndef _SKTUI_ELEMENT_UID_GENERATOR_H
#define _SKTUI_ELEMENT_UID_GENERATOR_H

#include <vector>

namespace SKTUI
{
    class UIDGenerator
    {
        public:
            UIDGenerator();
            ~UIDGenerator();

            int GenerateUID();

        private:
            std::vector<int> mUIDs;
            bool UIDInUse(int UID);
    };
}

#endif // _SKTUI_ELEMENT_UID_GENERATOR_H

