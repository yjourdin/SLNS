#pragma once

#include "../compile_parameters.h"

#ifdef CVRP
#include "cost_VRP.h"
using Cost = CostVRP;
#endif

#ifdef VRPTW
#include "cost_VRP.h"
using Cost = CostVRP;
#endif