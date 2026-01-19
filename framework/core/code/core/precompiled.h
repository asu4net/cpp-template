#pragma once

#include <memory>
#include <string>
#include <random>
#include <utility>
#include <cmath>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <array>

#include "imgui.h"
#include "core/platform/base.h"
#include "core/platform/limits.h"
#include "core/platform/slot_map.h"
#include "core/platform/span.h"
#include "core/platform/time.h"
#include "core/platform/audio.h"

#include "core/algebra/common_f32.h"
#include "core/algebra/vector2.h"
#include "core/algebra/vector3.h"
#include "core/algebra/vector4.h"
#include "core/algebra/quaternion.h"
#include "core/algebra/matrix4.h"
#include "core/algebra/camera.h"