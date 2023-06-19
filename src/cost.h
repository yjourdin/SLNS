#pragma once

#include <cstdlib>

#include "types.h"

struct Cost {
 public:
  std::size_t request_bank_size;
  std::size_t nb_routes;
  distance distance;
};