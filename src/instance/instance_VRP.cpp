#include "instance_VRP.h"

InstanceVRP::InstanceVRP(
    Capacity max_capacity,
    boost::numeric::ublas::matrix<Distance> distance_matrix,
    std::vector<Node> nodes)
    : max_capacity(max_capacity),
      distance_matrix(distance_matrix),
      nodes(nodes){};