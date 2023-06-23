#pragma once

#include <memory>

#include "../solution/solution.h"

class StopCriterion {
 public:
  virtual void start(std::shared_ptr<Solution> init) = 0;
  virtual const bool stop(std::shared_ptr<Solution> best) const = 0;
  virtual const Progress progress(std::shared_ptr<Solution> best) const = 0;
};