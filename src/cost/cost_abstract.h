#pragma once

#include <memory>

#include "../types.h"

template <class TCost>
struct CostAbstract {
 public:
  virtual bool is_better(const TCost& other) const = 0;
  virtual bool is_better_or_equal(const TCost& other) const = 0;
  virtual double to_double() const = 0;
};