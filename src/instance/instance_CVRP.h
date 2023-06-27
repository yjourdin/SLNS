#pragma once

#include "instance_VRP.h"

struct InstanceCVRP : public InstanceVRP {
 public:
  InstanceCVRP(std::ifstream& file);
};