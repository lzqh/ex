#ifndef __DATA_DATA_VISITOR_H
#define __DATA_DATA_VISITOR_H

#include <memory>
#include <functional>
#include "proto/role_attributes.pb.h"
#include "data/data_notifier.h"
#include "data/cache_buffer.h"
#include "data/data_visitor_base.h"
#include "data/data_dispatcher.h"

namespace ex{
namespace data{

using ex::proto::RoleAttributes;

template <typename T>
class DataVisitor: public DataVisitorBase
{
public:
    using DataBuffer = data::CacheBuffer<T>;
    using DataType = std::shared_ptr<T>;
    explicit DataVisitor(const RoleAttributes &attr);
    ~DataVisitor();

    bool Put(DataType &);
    DataType &Get();
    bool TryGet(DataType &);
private:
    std::shared_ptr<DataBuffer> databuffer_ = nullptr;
};

template <typename T>
DataVisitor<T>::DataVisitor(const RoleAttributes &attr):DataVisitorBase()
{
    databuffer_=std::make_shared<CacheBuffer<T>>();
    
    std::shared_ptr<ChannelBuffer<T>> buffers =DataDispatcher<T>::Instance()->GetChannelBuffer(attr.channel_id());
    if(buffers != nullptr)
    {
        buffers->Add(databuffer_);
    }else{

        std::shared_ptr<ChannelBuffer<T>> channel_buffer(new ChannelBuffer<T>(attr.channel_id()));
        channel_buffer->Add(databuffer_);
        DataDispatcher<T>::Instance()->SetChannelBuffer(attr.channel_id(),channel_buffer);
    }
    DataNotifier::Instance()->AddNotifier(attr.channel_id(),DataVisitor<T>::notifier_);
}

template <typename T>
DataVisitor<T>::~DataVisitor() {}


template <typename T>
 bool DataVisitor<T>::TryGet(DataType& data)
 {
    data =databuffer_->Get();
    if(data)
        return true;
    return false;
 }
        
} // end data namespace

} // end ex namespace

#endif
