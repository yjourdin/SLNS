#pragma once

#include <memory>

#include "../types.h"

template <class T>
struct CostAbstract {
 public:
  virtual bool is_better(const std::shared_ptr<T> other) const = 0;
  virtual bool is_better_or_equal(const std::shared_ptr<T> other) const = 0;
  virtual double to_double() const = 0;
};