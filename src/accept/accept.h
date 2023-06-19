#pragma once

#include <memory>

#include "../types.h"
#include "../slns.h"

class Accept {
    public:
        virtual void init()=0;
        virtual bool accept(const progress progress)=0;
    
    private:
        std::shared_ptr<SLNS> slns;
};