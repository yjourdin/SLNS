#pragma once

#include "cost_abstract.h"

template <class T>
class SolutionVRP;

struct CostVRP : public CostAbstract<CostVRP> {
 public:
  bool is_better(const std::shared_ptr<CostVRP> other) const;
  bool is_better_or_equal(const std::shared_ptr<CostVRP> other) const;
  double to_double() const;

 private:
  Node_count request_bank_size;
  Route_count nb_routes;
  Distance distance;

  template <class T>
  friend class SolutionVRP;
};