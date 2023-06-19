#pragma once

#include "../solution/solution.h"

class RepairOperator {
 public:
  virtual void repair(Solution& solution) = 0;
};