#include "slns.h"

#include <random>
#include <utility>

SLNS::SLNS(
    Destruction_size small_destruction_size_min,
    Destruction_size small_destruction_size_max,
    Destruction_size large_destruction_size_min,
    Destruction_size large_destruction_size_max,
    std::vector<std::shared_ptr<DestroyOperator>> small_destroy_operators,
    std::vector<std::shared_ptr<DestroyOperator>> large_destroy_operators,
    std::vector<std::shared_ptr<RepairOperator>> small_repair_operators,
    std::vector<std::shared_ptr<RepairOperator>> large_repair_operators,
    Iteration_count LNS_frequency, std::unique_ptr<StopCriterion> stop,
    std::unique_ptr<Accept> small_accept, std::unique_ptr<Accept> large_accept)
    : small_destruction_size_min(small_destruction_size_min),
      small_destruction_size_max(small_destruction_size_max),
      large_destruction_size_min(large_destruction_size_min),
      large_destruction_size_max(large_destruction_size_max),
      small_destroy_operators(std::move(small_destroy_operators)),
      large_destroy_operators(std::move(large_destroy_operators)),
      small_repair_operators(std::move(small_repair_operators)),
      large_repair_operators(std::move(large_repair_operators)),
      LNS_frequency(LNS_frequency),
      stop(std::move(stop)),
      small_accept(std::move(small_accept)),
      large_accept(std::move(large_accept)){};

void SLNS::initialise(const std::shared_ptr<Solution> start) {
  // Start the Stop criterion

  stop->start(start);

  // Initialize acceptance criteria

  small_accept->initialise(start);
  large_accept->initialise(start);
}

std::shared_ptr<Solution> SLNS::run(std::shared_ptr<Solution> start,
                                    unsigned random_seed) {
  // Initialize solution

  std::shared_ptr<Solution> best = start->is_feasible() ? start : nullptr;
  auto current = start;
  std::shared_ptr<Solution> neighbor = nullptr;

  // Set random seed

  std::default_random_engine gen;
  gen.seed(random_seed);

  // Set number of iterations before LNS to 0

  Iteration_count iter = 0;

  // Main loop

  while (not stop->stop(best)) {
    if (iter < LNS_frequency) {
      // Small Neighborhood Search

      ++iter;

      // Copy the current solution

      neighbor = std::make_shared<Solution>(current->copy());

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

      std::uniform_int_distribution<> distrib(min, max);
      node_count destruction_size = distrib(gen);

      // Pick random destroy and repair operators

      std::uniform_int_distribution<> distrib(0,
                                              small_destroy_operators.size());
      auto destroy = std::make_unique<DestroyOperator>(
          small_destroy_operators[distrib(gen)]);

      std::uniform_int_distribution<> distrib(0, small_repair_operators.size());
      auto repair = std::make_unique<RepairOperator>(
          small_repair_operators[distrib(gen)]);

      // Destroy & repair the neighbor solution

      destroy->destroy(*neighbor, destruction_size);
      repair->repair(*neighbor);

      // Accept the neighbor

      if (small_accept->accept(neighbor, best, current, stop->progress(best))) {
        current = neighbor;
      }
    } else {
      // Large Neighborhood Search

      iter = 0;

      // Copy the best solution, or the current if not

      neighbor = std::make_shared<Solution>(best->copy());

      // Choose random destruction size

      std::uniform_int_distribution<> distrib(large_destruction_size_min,
                                              large_destruction_size_max);
      Destruction_size destruction_size = distrib(gen);

      // Pick random destroy and repair operators

      std::uniform_int_distribution<> distrib(0,
                                              large_destroy_operators.size());
      auto destroy = std::make_unique<DestroyOperator>(
          large_destroy_operators[distrib(gen)]);

      std::uniform_int_distribution<> distrib(0, large_repair_operators.size());
      auto repair = std::make_unique<RepairOperator>(
          large_repair_operators[distrib(gen)]);

      // Destroy & repair the neighbor solution

      destroy->destroy(*neighbor, destruction_size);
      repair->repair(*neighbor);

      // Accept the neighbor

      if (large_accept->accept(neighbor, best, current, stop->progress(best))) {
        current = neighbor;
      }
    }

    // Update the best solution

    if (neighbor->is_feasible() and neighbor->is_better(*best)) {
      best = neighbor;
      iter = 0;
    }
  }

  return best;
};