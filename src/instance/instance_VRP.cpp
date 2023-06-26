#include "instance_VRP.h"

template <class TNode>
InstanceVRP<TNode>::InstanceVRP(
    Capacity max_capacity,
    boost::numeric::ublas::matrix<Distance> distance_matrix,
    std::vector<TNode> nodes)
    : max_capacity(max_capacity),
      distance_matrix(distance_matrix),
      nodes(nodes){};