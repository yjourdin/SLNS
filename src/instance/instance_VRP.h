#pragma once

#include <boost/numeric/ublas/matrix.hpp>
#include <fstream>
#include <iostream>
#include <vector>

#include "instance.h"
#include "node.h"
#include "types.h"

template <class T>
class InstanceVRP : public Instance {
 public:
  distance distance(const Node& node1, const Node& node2) const {
      return distance_matrix[node1.index, node2.index]};
  std::shared_ptr<Node> get_depot() const {return nodes[0]};
  std::shared_ptr<Node> get_customer(node_index pos) const {
      return nodes[pos]};
  node_count get_nb_customer() const {return nodes.size()};

 protected:
  const boost::numeric::ublas::matrix<distance> distance_matrix;
  const quantity max_capacity;
  const std::vector<T> nodes;
};

class InstanceCVRP : public InstanceVRP<Node> {
  public:
  InstanceCVRP(std::ifstream& file);
};

class InstanceVRPTW : public InstanceVRP<NodeTimeWindow> {
  InstanceVRPTW(std::ifstream& file);
};