#pragma once

#include <list>
#include <memory>

#include "../types.h"

template <class TNode>
class Route {
 public:
  Distance get_distance() const { return distance; };
  void insert(typename std::list<Node*>::const_iterator pos,
              TNode&& node);
  void erase(TNode& node);
  bool is_empty() const { return route.empty(); };

 private:
  std::list<std::shared_ptr<TNode>> route;
  Distance distance;
  Capacity capacity;
};