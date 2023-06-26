#pragma once

#include <memory>
#include <vector>

#include "accept/accept.h"
#include "destroy_operator/destroy_operator.h"
#include "initialisation/initialisation.h"
#include "repair_operator/repair_operator.h"
#include "solution/solution.h"
#include "stop_criterion/stop_criterion.h"
#include "types.h"

class SLNS {
 public:
  SLNS(Destruction_size small_destruction_size_min,
       Destruction_size small_destruction_size_max,
       Destruction_size large_destruction_size_min,
       Destruction_size large_destruction_size_max,
       std::vector<DestroyOperator*> small_destroy_operators,
       std::vector<DestroyOperator*> large_destroy_operators,
       std::vector<RepairOperator*> small_repair_operators,
       std::vector<RepairOperator*> large_repair_operators,
       Iteration_count LNS_frequency, StopCriterion* stop, Accept* small_accept,
       Accept* large_accept);
  void initialise(const Solution& start);
  Solution run(Solution start, const unsigned random_seed);
  void set_small_destruction_size_min(
      Destruction_size small_destruction_size_min) {
    this->small_destruction_size_min = small_destruction_size_min;
  };
  void set_small_destruction_size_max(
      Destruction_size small_destruction_size_max) {
    this->small_destruction_size_max = small_destruction_size_max;
  };
  void set_large_destruction_size_min(
      Destruction_size large_destruction_size_min) {
    this->large_destruction_size_min = large_destruction_size_min;
  };
  void set_large_destruction_size_max(
      Destruction_size large_destruction_size_max) {
    this->large_destruction_size_max = large_destruction_size_max;
  };
  void set_small_destroy_operators(
      std::vector<DestroyOperator*> small_destroy_operators) {
    this->small_destroy_operators = small_destroy_operators;
  };
  void set_large_destroy_operators(
      std::vector<DestroyOperator*> large_destroy_operators) {
    this->large_destroy_operators = large_destroy_operators;
  };
  void set_small_repair_operators(
      std::vector<RepairOperator*> small_repair_operators) {
    this->small_repair_operators = small_repair_operators;
  };
  void set_large_repair_operators(
      std::vector<RepairOperator*> large_repair_operators) {
    this->large_repair_operators = large_repair_operators;
  };
  void set_LNS_frequency(Iteration_count LNS_frequency) {
    this->LNS_frequency = LNS_frequency;
  };
  void set_stop(StopCriterion* stop) { this->stop = stop; };
  void set_small_accept(Accept* small_accept) {
    this->small_accept = small_accept;
  };
  void set_large_accept(Accept* large_accept) {
    this->large_accept = large_accept;
  };

 private:
  Destruction_size small_destruction_size_min;
  Destruction_size small_destruction_size_max;
  Destruction_size large_destruction_size_min;
  Destruction_size large_destruction_size_max;
  std::vector<DestroyOperator*> small_destroy_operators;
  std::vector<DestroyOperator*> large_destroy_operators;
  std::vector<RepairOperator*> small_repair_operators;
  std::vector<RepairOperator*> large_repair_operators;
  Iteration_count LNS_frequency;
  StopCriterion* stop;
  Accept* small_accept;
  Accept* large_accept;
  std::shared_ptr<Solution> best;
  std::shared_ptr<Solution> current;
  std::shared_ptr<Solution> neighbor;
};