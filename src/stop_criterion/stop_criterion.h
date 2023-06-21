#pragma once

#include <memory>

#include "../slns.h"
#include "../types.h"

class StopCriterion {
 public:
  virtual void start(std::shared_ptr<Solution> init) = 0;
  virtual const bool stop(std::shared_ptr<Solution> best) const = 0;
  virtual const progress progress(std::shared_ptr<Solution> best) const = 0;
};