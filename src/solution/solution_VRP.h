#pragma once

#include <functional>
#include <vector>

#include "route.h"
#include "solution_abstract.h"

class SolutionVRP : public SolutionAbstract<SolutionVRP> {
 public:
  SolutionVRP(Instance* instance);
  bool is_feasible() const { return routes.empty(); };
  bool is_better(SolutionVRP& other) const {
    return this->cost.is_better(other.get_cost());
  };
  void compute_cost();
  const unsigned get_size() const {
    return this->instance->get_nb_customers();
  };
  Route_count get_nb_routes() const { return routes.size(); };
  Route& get_route(Route_count pos) {
    return routes[pos];
  };
  void remove_empty_routes();
  void sort_request_bank(std::function<bool(const Node&, const Node&)> less);
  Distance update_distance();
  Distance get_distance() const { return distance; };

 protected:
  std::vector<Route> routes;
  std::vector<Node*> request_bank;
  Distance distance;
};