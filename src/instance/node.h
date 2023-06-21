#include <array>
#include <cmath>
#include <memory>

#include "instance_VRP.h"
#include "types.h"

class Coordinates {
 public:
  distance distance(Coordinates& other) {
    return sqrt(pow(coords[0] - other.get_x(), 2) +
                pow(coords[1] - other.get_y(), 2));
  };
  coordinate_type get_x() const { return coords[0]; };
  coordinate_type get_y() const { return coords[1]; };

 private:
  const std::array<coordinate_type, 2> coords;
};

class Node {
 public:
  Node(std::shared_ptr<InstanceVRP<Node>> instance, node_index index,
       Coordinates coordinates, quantity demand);
  distance distance(const Node& other) const;
  const node_index index;
  const Coordinates coordinates;
  const quantity demand;

 protected:
  std::shared_ptr<InstanceVRP<Node>> instance;
};

class TimeWindow {
 public:
  bool in(const time t) const { return (start <= t) and (t <= end); };
  bool in(const time t, const duration dur) const {
    return (start <= t) and (t + dur <= end);
  };
  const time start;
  const time end;
};

class NodeTimeWindow : public Node {
  public:
  const TimeWindow time_window;
  const duration serice_time;
};