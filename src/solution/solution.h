#pragma once

#include "../compile_parameters.h"

#ifdef CVRP
#include "solution_CVRP.h"
using Solution = SolutionCVRP;
#endif

#ifdef VRPTW
#include "solution_VRPTW.h"
using Solution = SolutionVRPTW;
#endif