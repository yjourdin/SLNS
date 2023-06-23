#pragma once

#include "../instance/instance_CVRP.h"
#include "../instance/node.h"
#include "solution_VRP.h"

class SolutionCVRP : public SolutionVRP<Node> {
 public:
  SolutionCVRP(std::shared_ptr<InstanceCVRP> instance);
};