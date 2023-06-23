#pragma once

#include "instance_VRP.h"
// #include "node.h"
struct Node;

class InstanceCVRP : public InstanceVRP<Node> {
 public:
  InstanceCVRP(std::ifstream& file);
};