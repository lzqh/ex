#ifndef __TRANSPORT_INTRA_DISPATCHER_H
#define __TRANSPORT_INTRA_DISPATCHER_H

#include <map>
#include <typeinfo>
#include "dispatcher.h"
#include "base/signal.h"
#include "transport/message/listener_handler.h"
#include "common/macros.h"
#include "base/atomic_rw_lock.h"
#include "base/rw_lock_guard.h"
#include <glog/logging.h>



namespace ex{
namespace transport{

template <typename T>
using Callback =std::function<void(const std::shared_ptr<T>& )>;
using TypeHandlerMap =std::map<std::string, std::shared_ptr<ListenerHandlerBase> >;

class IntraDispatcher : public Dispatcher{
public:
    template <typename T>
    bool AddListener(uint64_t channelid, const Callback<T>& func);
    template <typename T>
    bool RemoveListener(uint64_t channelid,const Callback<T>& func);
    template <typename T>
    bool Dispatch(uint64_t channelid,const std::shared_ptr<T>& msg);
private:
    base::AtomicRWLock rwlock_;
    std::mutex id_type_handler_map_mutex_;
    std::unordered_map<uint64_t, TypeHandlerMap> id_type_handler_map_;
    DECLARE_SINGLETON(IntraDispatcher)
};

inline IntraDispatcher::IntraDispatcher() {}

template <typename T>
bool IntraDispatcher::AddListener(uint64_t channelid, const Callback<T>& func)
{
    std::shared_ptr<ListenerHandler<T>> handler =nullptr;
    std::shared_ptr<ListenerHandlerBase>* handler_base =nullptr;
    TypeHandlerMap type_map;
    
    const std::type_info& info =typeid(T);
    std::string msg_type =info.name();
    std::lock_guard<std::mutex> lock(id_type_handler_map_mutex_);
    auto search =id_type_handler_map_.find(channelid);
    if(search != id_type_handler_map_.end())
    {
        type_map =search->second;
        auto finded =type_map.find(msg_type);
        if(finded != type_map.end())
        {
            handler_base= &type_map[msg_type];
            handler = std::dynamic_pointer_cast<ListenerHandler<T>>(*handler_base);
            if(handler==nullptr)
            {
                LOG(ERROR) <<"find hander but cast is null";
                return false;
            }else
            {
                
            }
        }else
        {
            handler.reset( new ListenerHandler<T>());
            id_type_handler_map_[channelid][msg_type] =handler;
        }
        
           
    }else{
        handler.reset( new ListenerHandler<T>());
        id_type_handler_map_[channelid]=  std::map<std::string,std::shared_ptr<ListenerHandlerBase>>();
        id_type_handler_map_[channelid][msg_type] =handler;
    }
   return handler->AddListener(func);

}

template <typename T>
bool IntraDispatcher::Dispatch(uint64_t channelid,const std::shared_ptr<T>& msg)
{
    const std::type_info& info =typeid(T);
    std::string msg_type =info.name();
    TypeHandlerMap type_map;


    auto search =id_type_handler_map_.find(channelid);
    if(search !=id_type_handler_map_.end())
    {
        type_map =search->second;
        auto finded =type_map.find(msg_type);
        if(finded != type_map.end())
        {
            std::shared_ptr<ListenerHandlerBase> handlerbase= type_map[msg_type];
            std::shared_ptr<ListenerHandler<T>> handler= std::dynamic_pointer_cast<ListenerHandler<T>>(handlerbase);

            if(handler==nullptr)
            {
                LOG(ERROR) <<"find hander but is null";
                return false ;
            }else
            {
                handler->Run(msg);
            }
        }else{
            //

        }
    }else{

        LOG(INFO)<< "not find listener_handler for channelid="<< channelid <<"\n";
    }
    return true;

}


template <typename T>
bool IntraDispatcher::RemoveListener(uint64_t channelid,const Callback<T>& func)
{
    return true;
}


}// end transport
}//end ex

#endif // __TRANSPORT_INTRA_DISPATCHER_H
