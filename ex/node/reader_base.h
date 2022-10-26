#ifndef __EX_READER_BASE_H
#define __EX_READER_BASE_H

#include <memory>
#include "proto/role_attributes.pb.h"
#include "transport/receiver/receiver.h"
#include "transport/transport.h"
#include "data/data_dispatcher.h"
#include "common/log.h"

namespace ex{

using transport::Receiver;

class ReaderBase{
public:
    ReaderBase(const proto::RoleAttributes& attr):attr_(attr) {}
    virtual ~ReaderBase() {}

protected:
    proto::RoleAttributes attr_;

};


template <typename T>
class ReceiverManger
{
public:
   ~ReceiverManger(){receiver_map_.clear();}
   auto GetReceiver(const proto::RoleAttributes& attr)->std::shared_ptr<Receiver<T>>;
private:
    std::mutex receiver_map_mutex_;
    std::unordered_map<uint64_t, std::shared_ptr<Receiver<T>>> receiver_map_;

    DECLARE_SINGLETON(ReceiverManger)
};

template <typename T>
inline ReceiverManger<T>::ReceiverManger() {}

template <typename T>
auto ReceiverManger<T>::GetReceiver(const proto::RoleAttributes& attr)->std::shared_ptr<Receiver<T>>
{
    std::shared_ptr<Receiver<T>> receiver=nullptr;
    auto search = receiver_map_.find(attr.channel_id());
    if (search != receiver_map_.end()) {
        receiver =search->second;
    } else {
        //LOG(INFO) << "channelid Not found in receiver_map_  ="<<attr.channel_id() <<"\n";
        uint64_t channelid =attr.channel_id();
        receiver =transport::CreateReceiver<T>(attr,[](const proto::RoleAttributes& reader_attr,const std::shared_ptr<T>& msg){
            (void)reader_attr;
            data::DataDispatcher<T>::Instance()->Dispatch(reader_attr.channel_id(),msg);
        });
        receiver_map_.insert({attr.channel_id(),receiver});
    }
    return receiver;
}

} //end ex namespace
#endif
