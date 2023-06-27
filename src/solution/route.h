#pragma once

#include <list>
#include <memory>

#include "../types.h"
#include "../instance/node.h"

class Route {
 public:
  Distance get_distance() const { return distance; };
  void insert(typename std::list<Node*>::const_iterator pos,
              Node&& node);
  void erase(Node& node);
  bool is_empty() const { return route.empty(); };

 private:
  std::list<Node*> route;
  Distance distance;
  Capacity capacity;
};