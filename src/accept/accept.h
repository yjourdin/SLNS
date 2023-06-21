#pragma once

#include <memory>

#include "../slns.h"
#include "../types.h"

class Accept {
 public:
  virtual void initialise(std::shared_ptr<Solution> start) = 0;
  virtual bool accept(std::shared_ptr<Solution> neighbor, std::shared_ptr<Solution> best, std::shared_ptr<Solution> current, const progress progress) = 0;
};