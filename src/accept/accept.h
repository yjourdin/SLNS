#pragma once

#include "../solution/solution.h"
#include "../types.h"

class Accept {
 public:
  virtual void initialise(const Solution& start) = 0;
  virtual const bool accept(const Solution& neighbor, const Solution& best,
                            const Solution& current,
                            const Progress progress) = 0;
};