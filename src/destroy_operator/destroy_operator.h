#pragma once

#include "../types.h"
#include "../solution/solution.h"

class DestroyOperator {
    public:
        virtual void destroy(Solution& solution, const destruction_size size)=0;
};