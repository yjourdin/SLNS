#pragma once

#include <cstdlib>

#include "cost.h"
#include "types.h"

struct CostVRP : public Cost {
 public:
  std::size_t request_bank_size;
  std::size_t nb_routes;
  distance distance;
};