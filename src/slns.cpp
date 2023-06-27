#include "slns.h"

#include <random>
#include <utility>

SLNS::SLNS(Destruction_size small_destruction_size_min,
           Destruction_size small_destruction_size_max,
           Destruction_size large_destruction_size_min,
           Destruction_size large_destruction_size_max,
           std::vector<DestroyOperator*> small_destroy_operators,
           std::vector<DestroyOperator*> large_destroy_operators,
           std::vector<RepairOperator*> small_repair_operators,
           std::vector<RepairOperator*> large_repair_operators,
           Iteration_count LNS_frequency, StopCriterion* stop,
           Accept* small_accept, Accept* large_accept)
    : small_destruction_size_min(small_destruction_size_min),
      small_destruction_size_max(small_destruction_size_max),
      large_destruction_size_min(large_destruction_size_min),
      large_destruction_size_max(large_destruction_size_max),
      small_destroy_operators(small_destroy_operators),
      large_destroy_operators(large_destroy_operators),
      small_repair_operators(small_repair_operators),
      large_repair_operators(large_repair_operators),
      LNS_frequency(LNS_frequency),
      stop(std::move(stop)),
      small_accept(std::move(small_accept)),
      large_accept(std::move(large_accept)){};

void SLNS::initialise(const Solution& start) {
  // Start the Stop criterion

  stop->start(start);

  // Initialize acceptance criteria

  small_accept->initialise(start);
  large_accept->initialise(start);
}

Solution SLNS::run(Solution start, unsigned random_seed) {
  // Initialize solution

  auto current = std::make_shared<Solution>(start);
  auto best = current->is_feasible() ? current : nullptr;
  std::shared_ptr<Solution> neighbor;

  // Set random seed

  std::default_random_engine gen;
  gen.seed(random_seed);

  // Set number of iterations before LNS to 0

  Iteration_count iter = 0;

  // Main loop

  while (not stop->stop(*best)) {
    if (iter < LNS_frequency) {
      // Small Neighborhood Search

      ++iter;

      // Copy the current solution

      neighbor = std::make_shared<Solution>(*current);

      // Choose random destruction size

      unsigned min;
      if (small_destruction_size_min < 1) {
        min = small_destruction_size_min * neighbor->get_size();
      } else {
        min = small_destruction_size_min;
      }

      unsigned max;
      if (small_destruction_size_max < 1) {
        max = small_destruction_size_max * neighbor->get_size();
      } else {
        max = small_destruction_size_max;
      }

      std::uniform_int_distribution<> distrib_destruction_size(min, max);
      Node_count destruction_size = distrib_destruction_size(gen);

      // Pick random destroy and repair operators

      std::uniform_int_distribution<> distrib_destroy(
          0, small_destroy_operators.size());
      auto destroy = small_destroy_operators[distrib_destroy(gen)];

      std::uniform_int_distribution<> distrib_repair(
          0, small_repair_operators.size());
      auto repair = small_repair_operators[distrib_repair(gen)];

      // Destroy & repair the neighbor solution

      destroy->destroy(*neighbor, destruction_size);
      repair->repair(*neighbor);

      // Accept the neighbor

      if (small_accept->accept(*neighbor, *best, *current, stop->progress(*best))) {
        current = neighbor;
      }
    } else {
      // Large Neighborhood Search

      iter = 0;

      // Copy the best solution, or the current if not

      neighbor = std::make_shared<Solution>(*best);

      // Choose random destruction size

      std::uniform_int_distribution<> distrib(large_destruction_size_min,
                                              large_destruction_size_max);
      Destruction_size destruction_size = distrib(gen);

      // Pick random destroy and repair operators

      std::uniform_int_distribution<> distrib_destroy(
          0, large_destroy_operators.size());
      auto destroy = large_destroy_operators[distrib_destroy(gen)];

      std::uniform_int_distribution<> distrib_repair(
          0, large_repair_operators.size());
      auto repair = large_repair_operators[distrib_repair(gen)];

      // Destroy & repair the neighbor solution

      destroy->destroy(*neighbor, destruction_size);
      repair->repair(*neighbor);

      // Accept the neighbor

      if (large_accept->accept(*neighbor, *best, *current, stop->progress(*best))) {
        current = neighbor;
      }
    }

    // Update the best solution

    if (neighbor->is_feasible() and neighbor->is_better(*best)) {
      best = neighbor;
      iter = 0;
    }
  }

  return *best;
};