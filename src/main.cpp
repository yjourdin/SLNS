#include <cmath>
#include <fstream>
#include <iostream>
#include <random>

#include "slns.h"

int main(int argc, char* argv[]) {
  // Set random seed

  std::random_device r;
  unsigned random_seed = r();

  // Get instance file

  std::ifstream file("instances/CVRP/A/A-n32-k5.vrp");

  // Create instance

  Instance instance(file);

  // Create init solution

  ClarkWright initialisation;
  auto best = initialisation.init(instance);

  // Phase 1 : Fleet minimisation

  // SLNS parameters

  Destruction_size small_destruction_size_min = 1;
  Destruction_size small_destruction_size_max = 20;
  Destruction_size large_destruction_size_min = 20;
  Destruction_size large_destruction_size_max = 80;

  std::vector<DestroyOperator*> small_destroy_operators;
  small_destroy_operators.push_back(new RandomRemoval());
  std::vector<DestroyOperator*> large_destroy_operators;
  large_destroy_operators.push_back(new RandomRemoval());
  std::vector<RepairOperator*> small_repair_operators;
  small_repair_operators.push_back(new Random());
  std::vector<RepairOperator*> large_repair_operators;
  large_repair_operators.push_back(new Random());

  Iteration_count LNS_freq = 10 * std::pow(instance.get_nb_customers(), 1.5);

  StopCriterionSet stop;
  stop.push_back(new IterationLimit(25000));
  stop.push_back(new IterationsImprovementLimit(2000));
  stop.push_back(CostVRP(0, best->get_nb_routes(), 0));

  RandomWalk small_accept;
  RandomWalk large_accept;

  // Create SLNS

  SLNS slns(small_destruction_size_min, small_destruction_size_max,
            large_destruction_size_min, large_destruction_size_max,
            small_destroy_operators, large_destroy_operators,
            small_repair_operators, large_repair_operators, LNS_freq, stop,
            small_accept, large_accept);

  slns.initialise(best);

  Route_count nb_route = best->get_nb_routes();
  do {
    RouteRemoval route_removal;
    route_removal(best, 1);
    best.remove_empty_routes();
    best = slns.run(std::move(best), random_seed);
  } while (best->is_feasible());

  // Phase 2 : Distance minimisation

  // SLNS parameters

  IterationLimit stop(50000);

  // Create SLNS

  slns.set_stop(&stop);

  slns.initialise(best);

  best = slns.run(std::move(best), random_seed);
}