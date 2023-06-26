#pragma once

#include <memory>

#include "../solution/solution.h"

class StopCriterion {
 public:
  virtual void start(const Solution& init) = 0;
  virtual const bool stop(const Solution& best) const = 0;
  virtual const Progress progress(const Solution& best) const = 0;
};