#pragma once

#include <memory>

#include "../cost.h"
#include "../instance/instance.h"
#include "../types.h"

class Solution {
 public:
  virtual bool is_feasible() const = 0;
  virtual Cost get_cost() const = 0;
  virtual bool is_better(Solution& other) const = 0;

 private:
  std::shared_ptr<Instance> instance;
  Cost cost;
};