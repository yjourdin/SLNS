#pragma once

#include <functional>
#include <vector>

#include "route.h"
#include "solution_abstract.h"

template <class T>
class SolutionVRP : public SolutionAbstract<SolutionVRP<T>> {
 public:
  bool is_feasible() const { return routes.empty(); };
  bool is_better(SolutionVRP<T>& other) const {
    return this->cost.is_better(other.get_cost());
  };
  void compute_cost() {
    this->cost.request_bank_size =
        request_bank.size();
    this->cost.nb_routes = routes.size();
    this->cost.distance = distance;
  };
  const unsigned get_size() const {return this->instance->get_nb_customers();};
  Route_count get_nb_routes() const { return routes.size(); };
  Route<T>* get_route(Route_count pos) const { return routes[pos]; }
  Route<T>* get_route(T* node) const;
  void remove_empty_routes();
  void sort_request_bank(std::function<bool(const T&, const T&)> less);
  Distance update_distance();
  Distance get_distance() const { return distance; };

 private:
  std::vector<Route<T>> routes;
  std::vector<T*> request_bank;
  Distance distance;
};