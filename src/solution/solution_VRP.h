#pragma once

#include <functional>
#include <vector>

#include "route.h"
#include "solution_abstract.h"

class SolutionVRP : public SolutionAbstract<SolutionVRP> {
 public:
  bool is_feasible() const { return routes.empty(); };
  bool is_better(SolutionVRP& other) const {
    return this->cost.is_better(other.get_cost());
  };
  void compute_cost() {
    this->cost.request_bank_size = request_bank.size();
    this->cost.nb_routes = routes.size();
    this->cost.distance = distance;
  };
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

 private:
  std::vector<Route> routes;
  std::vector<Node*> request_bank;
  Distance distance;
};