#pragma once

#include <functional>
#include <vector>

#include "route.h"
#include "solution_abstract.h"

template <class TNode>
class SolutionVRP : public SolutionAbstract<SolutionVRP<TNode>> {
 public:
  bool is_feasible() const { return routes.empty(); };
  bool is_better(std::shared_ptr<SolutionVRP<TNode>> other) const {
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
  std::shared_ptr<Route<TNode>> get_route(Route_count pos) const {
    return routes[pos];
  }
  std::shared_ptr<Route<TNode>> get_route(std::shared_ptr<TNode> node) const;
  void remove_empty_routes();
  void sort_request_bank(std::function<bool(const TNode&, const TNode&)> less);
  Distance update_distance();
  Distance get_distance() const { return distance; };

 private:
  std::vector<Route<TNode>> routes;
  std::vector<std::shared_ptr<TNode>> request_bank;
  Distance distance;
};