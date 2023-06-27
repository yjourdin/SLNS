#include "cost_VRP.h"

#include <cmath>

CostVRP::CostVRP(Node_count request_bank_size, Route_count nb_routes,
                 Distance distance)
    : request_bank_size(request_bank_size),
      nb_routes(nb_routes),
      distance(distance){};

bool CostVRP::is_better(const CostVRP& other) const {
  return (request_bank_size < other.request_bank_size) or
         ((request_bank_size == other.request_bank_size) and
          ((nb_routes < other.nb_routes) or
           ((nb_routes == other.nb_routes) and (distance < other.distance))));
};

bool CostVRP::is_better_or_equal(const CostVRP& other) const {
  return (request_bank_size < other.request_bank_size) or
         ((request_bank_size == other.request_bank_size) and
          ((nb_routes < other.nb_routes) or
           ((nb_routes == other.nb_routes) and
            (distance <= other.distance))));
};

double CostVRP::to_double() const {
  return request_bank_size * std::pow(10, 9) + nb_routes * std::pow(10, 6) +
         distance;
};