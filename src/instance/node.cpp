#include "node.h"

Coordinates::Coordinates(Coordinate_type x, Coordinate_type y) : x(x), y(y){};

Node::Node(std::shared_ptr<Instance> instance, Node_index index,
           Coordinates coordinates, Capacity demand)
    : instance(instance),
      index(index),
      coordinates(coordinates),
      demand(demand){};

TimeWindow::TimeWindow(Time start, Time end) : start(start), end(end){};

NodeTimeWindow::NodeTimeWindow(std::shared_ptr<Instance> instance,
                               Node_index index, Coordinates coordinates,
                               Capacity demand, TimeWindow time_window,
                               Duration service_time)
    : Node(instance, index, coordinates, demand),
      time_window(time_window),
      service_time(service_time){};