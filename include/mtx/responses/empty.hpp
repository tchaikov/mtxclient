#pragma once

#if __has_include(<nlohmann/json_fwd.hpp>)
#include <nlohmann/json_fwd.hpp>
#else
#include <nlohmann/json.hpp>
#endif

#include "mtx/identifiers.hpp"

namespace mtx {
namespace responses {

// Used to represent empty responses
struct Empty
{};

void
from_json(const nlohmann::json &, Empty &);

using Logout      = Empty;
using DisplayName = Empty;
using RoomInvite  = Empty;
}
}
