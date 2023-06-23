#pragma once

#include "../solution/solution.h"
#include "../types.h"

class DestroyOperator {
 public:
  virtual void destroy(Solution& solution, const unsigned size) = 0;
};