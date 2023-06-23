#pragma once

#include <list>

#include "../types.h"

template <class T>
class Route {
 public:
  Distance get_distance() const { return distance; };
  void insert(typename std::list<T*>::const_iterator pos, T&& node);
  void erase(T& node);
  bool is_empty() const { return route.empty(); };

 private:
  std::list<T*> route;
  Distance distance;
  Capacity capacity;
};