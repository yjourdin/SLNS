#pragma once

class Node;

#include <boost/numeric/ublas/matrix.hpp>
#include <fstream>
#include <iostream>
#include <memory>
#include <vector>

#include "../types.h"

template <class TNode>
class InstanceVRP {
 public:
  InstanceVRP(Capacity max_capacity,
              boost::numeric::ublas::matrix<Distance> distance_matrix,
              std::vector<Node> nodes);
  Distance distance(const Node& node1, const Node& node2) const {
    return distance_matrix(node1.index, node2.index);
  };
  std::shared_ptr<TNode> get_depot() const { return nodes[0]; };
  std::shared_ptr<TNode> get_customer(Node_index pos) const {
    return nodes[pos];
  };
  Node_count get_nb_customers() const { return nodes.size(); };

 protected:
  const boost::numeric::ublas::matrix<Distance> distance_matrix;
  const Capacity max_capacity;
  const std::vector<TNode> nodes;
};