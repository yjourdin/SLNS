#pragma once

#include <memory>

#include "../solution/solution.h"

class Instance {
 public:
  virtual std::unique_ptr<Solution> create_solution() = 0;
};