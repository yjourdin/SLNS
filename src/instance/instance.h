#pragma once

#include "../compile_parameters.h"

#ifdef CVRP
#include "instance_CVRP.h"
class Instance : public InstanceCVRP {
  using InstanceCVRP::InstanceCVRP;
};
#endif

#ifdef VRPTW
#include "instance_VRPTW"
class Instance : public InstanceVRPTW {
  using InstanceVRPTW::InstanceVRPTW;
};
#endif