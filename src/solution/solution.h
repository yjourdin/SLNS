#pragma once

#include <memory>

#include "../cost/cost.h"
#include "../instance/instance.h"
#include "../types.h"

class Solution {
 public:
  virtual bool is_feasible() const = 0;
  virtual bool is_better(Solution& other) const = 0;
  virtual std::shared_ptr<Solution> copy() const = 0;
  virtual void compute_cost() = 0;
  virtual const unsigned get_size() const = 0;
  const std::shared_ptr<Instance> get_instance() const { return instance; };
  std::shared_ptr<Cost> get_cost() const {
    return std::make_shared<Cost>(cost);
  };

 protected:
  const std::shared_ptr<Instance> instance;
  std::unique_ptr<Cost> cost;
};