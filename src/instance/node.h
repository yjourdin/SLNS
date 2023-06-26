#pragma once

#include <array>
#include <cmath>
#include <memory>

#include "instance.h"
#include "../types.h"

class Coordinates {
 public:
  Coordinates(Coordinate_type x, Coordinate_type y);
  Distance distance(Coordinates& other) {
    return sqrt(pow(coords[0] - other.get_x(), 2) +
                pow(coords[1] - other.get_y(), 2));
  };
  Coordinate_type get_x() const { return coords[0]; };
  Coordinate_type get_y() const { return coords[1]; };

 private:
  const std::array<Coordinate_type, 2> coords;
};

struct Node {
 public:
  Node(std::shared_ptr<Instance> instance, Node_index index,
       Coordinates coordinates, Capacity demand);
  Distance distance(const Node& other) const;
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