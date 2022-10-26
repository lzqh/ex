#ifndef _EX_GLOBAL_H
#define _EX_GLOBAL_H

#include <unordered_map>
#include <mutex>
#include <string>
#include "common/macros.h"

namespace ex{
namespace data{

class GlobalData{
public:
    ~GlobalData() {}
    uint64_t RegisterNodeName(const std::string &node_name);
    uint64_t RegisterChannelName(const std::string &channel_name);

private:
    std::mutex node_map_mutex_;
    std::mutex channal_map_mutex_;
    std::unordered_map<uint64_t,std::string> node_map_;
    std::unordered_map<uint64_t,std::string> channel_map_;

    DECLARE_SINGLETON(GlobalData)

};

inline GlobalData::GlobalData() {}

}
}

#endif
