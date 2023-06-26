#pragma once

#include <memory>

#include "../cost/cost.h"
#include "../instance/instance.h"
#include "../types.h"

template <class TSolution>
class SolutionAbstract {
 public:
  virtual bool is_feasible() const = 0;
  virtual bool is_better(std::shared_ptr<TSolution> other) const = 0;
  virtual void compute_cost() = 0;
  virtual const unsigned get_size() const = 0;
  const Instance* get_instance() const { return instance; };
  Cost& get_cost() const { return cost; };

 protected:
  const Instance* instance;
  Cost cost;
};