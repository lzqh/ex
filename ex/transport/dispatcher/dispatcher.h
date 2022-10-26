#ifndef __TRANSPORT_DISPATCHER_H
#define __TRANSPORT_DISPATCHER_H

#include <memory>
#include <unordered_map>
#include <functional>
#include <mutex>
#include "transport/message/listener_handler_base.h"

namespace ex{

namespace transport{

class Dispatcher{
public:
    template <typename T>
     using Callback =std::function<void(const std::shared_ptr<T>&)>;
    virtual ~Dispatcher() {};
    
    template <typename T>
    bool Dispatch(uint64_t channelid,const std::shared_ptr<T>& msg);
    template <typename T>
    bool AddListener(uint64_t channelid, const Callback<T>& func);
    template <typename T>
    bool RemoveListener(uint64_t channelid,const Callback<T>& func);

protected:
    std::mutex id_listener_handler_map_mutex_;
    std::unordered_map<uint64_t, std::shared_ptr<ListenerHandlerBase>> id_listener_handler_map_;
    
};

}//end transport

}//end ex

#endif
