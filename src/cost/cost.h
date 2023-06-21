#pragma once

#include <cstdlib>

#include "types.h"

struct Cost {
 public:
  virtual bool is_better(const Cost& other) const = 0;
  virtual double to_double() const = 0;
};