#ifndef _DATA_CHANNEL_BUFFER_H
#define _DATA_CHANNEL_BUFFER_H

#include <memory>
#include <vector>
#include <mutex>
#include "data/cache_buffer.h"

namespace ex{
namespace data{

template <typename T>
class ChannelBuffer
{
    using MsgType =std::shared_ptr<T>;
    using CacheBufferPtr = std::shared_ptr<CacheBuffer<T>>;
public:
    ChannelBuffer(uint64_t channel_id);
    ~ChannelBuffer();
    void Add(CacheBufferPtr& buffer_ptr);
    void Put(const MsgType& msg);
    bool Delete();
private:
    std::mutex buffers_mutex_;
    std::vector<CacheBufferPtr> buffers_;
    uint64_t channel_id_;
};

template <typename T>
ChannelBuffer<T>::ChannelBuffer(uint64_t channel_id):channel_id_(channel_id) {}

template <typename T>
ChannelBuffer<T>::~ChannelBuffer() {buffers_.clear();}


template <typename T>
void ChannelBuffer<T>::Add(CacheBufferPtr& buffer_ptr)
{
    buffers_.emplace_back(buffer_ptr);
}

template <typename T>
void ChannelBuffer<T>::Put(const MsgType& msg)
{
    for(auto &buffer : buffers_)
    {
        (*buffer).Put(msg);
    }
}

}// data namespace

}// ex namespace

#endif
