#pragma once

#include "../instance/instance_VRPTW.h"
#include "../instance/node.h"
#include "solution_VRP.h"

class SolutionVRPTW : public SolutionVRP<NodeTimeWindow> {
 public:
  SolutionVRPTW(std::shared_ptr<InstanceVRPTW> instance);
};