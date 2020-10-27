#pragma once

#if __has_include(<nlohmann/json_fwd.hpp>)
#include <nlohmann/json_fwd.hpp>
#else
#include <nlohmann/json.hpp>
#endif

namespace mtx {
namespace responses {

//! Response from the `GET /_matrix/client/versions` endpoint.
//
//! Gets the versions of the specification supported by the server.
struct Versions
{
        //! The supported versions.
        std::vector<std::string> versions;
};

void
from_json(const nlohmann::json &obj, Versions &response);
}
}
