#include "node_base.h"

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

struct NodeTimeWindow : public NodeBase {
 public:
  NodeTimeWindow(Instance* instance, Node_index index, Coordinates coordinates,
                 Capacity demand, TimeWindow time_window,
                 Duration service_time);
  const TimeWindow time_window;
  const Duration service_time;

 protected:
  Time service_time_start;
};