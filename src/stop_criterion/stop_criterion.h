#pragma once

#include <memory>
#include "../types.h"
#include "../slns.h"

class StopCriterion {
    public:
        virtual const bool stop() const=0;
        virtual const progress progress() const=0;
    
    private:
        std::shared_ptr<SLNS> slns;
};