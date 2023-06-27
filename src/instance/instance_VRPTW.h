#pragma once

#include "instance_VRP.h"

struct InstanceVRPTW : public InstanceVRP {
  InstanceVRPTW(std::ifstream& file);
};