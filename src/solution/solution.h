#pragma once

#include "../compile_parameters.h"

#ifdef CVRP
#include "solution_VRP.h"
class Solution : public SolutionVRP {
  using SolutionVRP::SolutionVRP;
};
#endif

#ifdef VRPTW
#include "solution_VRP.h"
class Solution : public SolutionVRP {
  using SolutionVRP::SolutionVRP;
};
#endif