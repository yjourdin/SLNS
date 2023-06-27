#include "../solution/route.h"
#include "instance.h"
#include "node.h"

Coordinates::Coordinates(Coordinate_type x, Coordinate_type y) : x(x), y(y){};

NodeBase::NodeBase(Instance* instance, Node_index index,
                   Coordinates coordinates, Capacity demand)
    : instance(instance),
      index(index),
      coordinates(coordinates),
      demand(demand),
      route(nullptr){};

inline Distance NodeBase::distance(const NodeBase& other) const {
  return this->instance->distance(*this, other);
};

inline void NodeBase::set_route(const Route* route) { this->route = route; };