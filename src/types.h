#pragma once

#include "compile_parameters.h"

// SLNS

using Destruction_size = float;
using Iteration_count = unsigned long;

// VRP

#ifdef DISCRETE
using Distance = unsigned;
using Duration = unsigned;
using Time = unsigned;
#else
using Distance = double;
using Duration = double;
using Time = double;
#endif
using Capacity = unsigned short;
using Coordinate_type = double;
using Node_index = unsigned;
using Node_count = unsigned;
using Route_count = unsigned short;

// Accept

using Progress = float;
using Threshold = float;
using Temperature = float;
using H_type = float;
using Great_deluge_parameter = float;
using Water_level = float;
using Probability = float;
