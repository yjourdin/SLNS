#pragma once

#include <memory>
#include "../types.h"
#include "../instance/instance.h"

class Solution {
    public:
        virtual bool is_feasible() const=0;
        virtual cost get_cost() const=0;
        virtual bool is_better(Solution& other) const=0;
    
    private:
        std::shared_ptr<Instance> instance;
        cost cost;
};