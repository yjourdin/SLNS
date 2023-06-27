#pragma once

#include <cmath>
#include <memory>

#include "../types.h"

class Instance;
class Route;

struct Coordinates {
 public:
  Coordinates(Coordinate_type x, Coordinate_type y);
  Distance distance(Coordinates& other) {
    return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
  };
  const Coordinate_type x;
  const Coordinate_type y;
};

struct NodeBase {
 public:
  NodeBase(Instance* instance, Node_index index, Coordinates coordinates,
           Capacity demand);
  inline Distance distance(const NodeBase& other) const;
  inline void set_route(const Route* route);
  const Node_index index;
  const Coordinates coordinates;
  const Capacity demand;

 protected:
  const Instance* instance;
  const Route* route;
};
