#pragma once

#include "compile_parameters.h"

// SLNS

using Destruction_size = float;
using Iteration_count = unsigned long;

// VRP

#ifdef DISCRETE
using Coordinate_type = int;
using Distance = unsigned;
using Duration = unsigned;
using Time = unsigned;
#else
using Coordinate_type = double;
using Distance = double;
using Duration = double;
using Time = double;
#endif
using Capacity = unsigned short;
using Node_index = unsigned;
using Node_count = unsigned;
using Route_count = unsigned short;

// Accept

using Progress = double;
using Threshold = double;
using Temperature = double;
using H_type = double;
using Great_deluge_parameter = double;
using Water_level = double;
using Probability = double;
