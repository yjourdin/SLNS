#pragma once

#include "../compile_parameters.h"

#ifdef CVRP
#include "cost_VRP.h"
struct Cost : public CostVRP {
  using CostVRP::CostVRP;
};
#endif

#ifdef VRPTW
#include "cost_VRP.h"
struct Cost : public CostVRP {
  using CostVRP::CostVRP;
};
#endif