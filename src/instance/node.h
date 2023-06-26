#pragma once

#include <array>
#include <cmath>
#include <memory>

#include "instance.h"

struct Coordinates {
 public:
  Coordinates(Coordinate_type x, Coordinate_type y);
  Distance distance(Coordinates& other) {
    return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
  };
  const Coordinate_type x;
  const Coordinate_type y;
};

struct Node {
 public:
  Node(std::shared_ptr<Instance> instance, Node_index index,
       Coordinates coordinates, Capacity demand);
  Distance distance(const Node& other) const {return instance->distance(this, other);};
  const Node_index index;
  const Coordinates coordinates;
  const Capacity demand;

 protected:
  std::shared_ptr<Instance> instance;
};

struct TimeWindow {
 public:
  TimeWindow(Time start, Time end);
  bool in(const Time t) const { return (start <= t) and (t <= end); };
  bool in(const Time t, const Duration dur) const {
    return (start <= t) and (t + dur <= end);
  };
  const Time start;
  const Time end;
};

struct NodeTimeWindow : public Node {
 public:
  NodeTimeWindow(std::shared_ptr<Instance> instance, Node_index index,
       Coordinates coordinates, Capacity demand, TimeWindow time_window,
       Duration serice_time);
  const TimeWindow time_window;
  const Duration serice_time;
};