#include "data/global_data.h"
#include "common/utility.h"

namespace ex{
namespace data{

uint64_t GlobalData::RegisterNodeName(const std::string &node_name)
{
    return common::Hash(node_name);
}
uint64_t GlobalData::RegisterChannelName(const std::string &channel_name)
{
     return common::Hash(channel_name);
}

}
}