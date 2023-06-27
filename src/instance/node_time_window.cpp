#include "node_time_window.h"

TimeWindow::TimeWindow(Time start, Time end) : start(start), end(end){};

NodeTimeWindow::NodeTimeWindow(Instance* instance, Node_index index,
                               Coordinates coordinates, Capacity demand,
                               TimeWindow time_window, Duration service_time)
    : NodeBase(instance, index, coordinates, demand),
      time_window(time_window),
      service_time(service_time),
      service_time_start(0){};