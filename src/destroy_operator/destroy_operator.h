#pragma once

#include "../solution/solution.h"
#include "../types.h"

class DestroyOperator {
 public:
  virtual void destroy(Solution& solution, const destruction_size size) = 0;
};