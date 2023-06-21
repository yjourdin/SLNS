#pragma once

#include <memory>

#include "../instance/instance.h"
#include "../solution/solution.h"

class Initialisation {
 public:
  virtual std::unique_ptr<Solution> init(const Instance& instance) = 0;

 protected:
  virtual void fill_solution(Solution& solution) = 0;
};