#pragma once

#include <memory>
#include "../instance/instance.h"
#include "../solution/solution.h"

class Init {
    public:
        virtual Solution init(const Instance instance)=0;
};