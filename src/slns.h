#pragma once

#include <memory>
#include <vector>

#include "accept/accept.h"
#include "destroy_operator/destroy_operator.h"
#include "initialisation/initialisation.h"
#include "instance/instance.h"
#include "repair_operator/repair_operator.h"
#include "solution/solution.h"
#include "stop_criterion/stop_criterion.h"
#include "types.h"

class SLNS {
 public:
  SLNS(destruction_size small_destruction_size_min,
       destruction_size small_destruction_size_max,
       destruction_size large_destruction_size_min,
       destruction_size large_destruction_size_max,
       std::vector<DestroyOperator> small_destroy_operators,
       std::vector<DestroyOperator> large_destroy_operators,
       std::vector<RepairOperator> small_repair_operators,
       std::vector<RepairOperator> large_repair_operators,
       iteration_count LNS_freq, std::unique_ptr<StopCriterion> stop,
       std::unique_ptr<Accept> small_accept,
       std::unique_ptr<Accept> large_accept);
  void initialise(const std::shared_ptr<Solution> start);
  std::shared_ptr<Solution> run(std::shared_ptr<Solution> start,
                                const unsigned random_seed);

 private:
  destruction_size small_destruction_size_min;
  destruction_size small_destruction_size_max;
  destruction_size large_destruction_size_min;
  destruction_size large_destruction_size_max;
  std::vector<DestroyOperator> small_destroy_operators;
  std::vector<DestroyOperator> large_destroy_operators;
  std::vector<RepairOperator> small_repair_operators;
  std::vector<RepairOperator> large_repair_operators;
  iteration_count LNS_freq;
  std::unique_ptr<StopCriterion> stop;
  std::unique_ptr<Accept> small_accept;
  std::unique_ptr<Accept> large_accept;
  std::shared_ptr<Solution> best;
  std::shared_ptr<Solution> current;
  std::shared_ptr<Solution> neighbor;
};