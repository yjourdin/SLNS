#pragma once

#include "../compile_parameters.h"

#ifdef CVRP
#include "node_base.h"
using Node = NodeBase;
#endif

#ifdef VRPTW
#include "node_time_window.h"
using Node = NodeTimeWindow;
#endif