#pragma once

#include "../compile_parameters.h"

#ifdef CVRP
#include "instance_CVRP.h"
using Instance = InstanceCVRP;
#endif

#ifdef VRPTW
#include "instance_VRPTW"
using Instance = InstanceVRPTW;
#endif