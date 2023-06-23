#pragma once

#include "node.h"

class InstanceVRPTW : public InstanceVRP<NodeTimeWindow> {
  InstanceVRPTW(std::ifstream& file);
};