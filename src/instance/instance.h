#pragma once

#include "../solution/solution.h"

class Instance {
    public:
        virtual Solution create_solution()=0;
};