#include <nlohmann/json.hpp>
#include <string>

#include "mtx/events/common.hpp"
#include "mtx/events/messages/text.hpp"

using json = nlohmann::json;

namespace mtx {
namespace events {
namespace msg {

void
from_json(const json &obj, Text &content)
{
    content.body    = obj.at("body").get<std::string>();
    content.msgtype = obj.at("msgtype").get<std::string>();

    if (obj.count("format") != 0)
        content.format = obj.at("format").get<std::string>();

    if (obj.count("formatted_body") != 0)
        content.formatted_body = obj.at("formatted_body").get<std::string>();

    content.relations = common::parse_relations(obj);
    content.mentions  = common::parse_mentions(obj);
}

void
to_json(json &obj, const Text &content)
{
    obj["msgtype"] = "m.text";
    obj["body"]    = content.body;

    if (!content.formatted_body.empty()) {
        obj["format"]         = mtx::common::FORMAT_MSG_TYPE;
        obj["formatted_body"] = content.formatted_body;
    }

    common::add_mentions(obj, content.mentions);
    common::apply_relations(obj, content.relations);
}

} // namespace msg
} // namespace events
} // namespace mtx
