#include "slns.h"

#include <utility>

SLNS::SLNS(destruction_size small_destruction_size_min,
           destruction_size small_destruction_size_max,
           destruction_size large_destruction_size_min,
           destruction_size large_destruction_size_max,
           std::vector<DestroyOperator> small_destroy_operators,
           std::vector<DestroyOperator> large_destroy_operators,
           std::vector<RepairOperator> small_repair_operators,
           std::vector<RepairOperator> large_repair_operators,
           frequency LNS_freq, std::unique_ptr<Init> init,
           std::unique_ptr<StopCriterion> stop,
           std::unique_ptr<Accept> small_accept,
           std::unique_ptr<Accept> large_accept)
    : small_destruction_size_min(small_destruction_size_min),
      small_destruction_size_max(small_destruction_size_max),
      large_destruction_size_min(large_destruction_size_min),
      large_destruction_size_max(large_destruction_size_max),
      small_destroy_operators(std::move(small_destroy_operators)),
      large_destroy_operators(std::move(large_destroy_operators)),
      small_repair_operators(std::move(small_repair_operators)),
      large_repair_operators(std::move(large_repair_operators)),
      LNS_freq(LNS_freq),
      init(std::move(init)),
      stop(std::move(stop)),
      small_accept(std::move(small_accept)),
      large_accept(std::move(large_accept)){};
