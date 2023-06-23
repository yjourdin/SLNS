#include "instance_VRP.h"

template <class T>
InstanceVRP<T>::InstanceVRP(
    Capacity max_capacity,
    boost::numeric::ublas::matrix<Distance> distance_matrix,
    std::vector<T> nodes)
    : max_capacity(max_capacity),
      distance_matrix(distance_matrix),
      nodes(nodes){};