#ifndef _DATA_CACHE_BUFFER_H
#define _DATA_CACHE_BUFFER_H

#include <memory>
#include <vector>
#include <mutex>
#include "common/log.h"

namespace ex{
namespace data{

template <typename T>
class CacheBuffer
{
    using DataType = std::shared_ptr<T>;
public:
    CacheBuffer(const int size = 100);
    ~CacheBuffer();

    bool Put(const DataType &data);
    DataType Get();

    bool Full();
    bool Empty();
    uint64_t GetIndex(uint64_t pos);

private:
    std::vector<DataType> buffer_;
    int head_, rear_;
    uint64_t capicity_;
    std::mutex buffer_mutex_;
};

template <typename T>
CacheBuffer<T>::CacheBuffer(const int size):head_(0),rear_(0)
{
    capicity_ = size;
    buffer_.resize(capicity_);
}

template <typename T>
CacheBuffer<T>::~CacheBuffer() {buffer_.clear();}

template <typename T>
bool CacheBuffer<T>::Full()
{
    return  GetIndex(head_+1) == rear_;
}

template <typename T>
bool CacheBuffer<T>::Empty()
{
    return head_==rear_;
}
template <typename T>
uint64_t CacheBuffer<T>::GetIndex(uint64_t pos)
{
    return pos % capicity_;
}

template <typename T>
bool CacheBuffer<T>::Put(const DataType& data)
{
    
    {
        std::lock_guard<std::mutex> lock(buffer_mutex_);
        if(Full())
        {
            return false;
        }else{
             buffer_[head_]=data;
             head_ =GetIndex(++head_);
        }
       
    }
    return true;
}

template <typename T>
std::shared_ptr<T> CacheBuffer<T>::Get() 
{
    DataType data = nullptr;
    {
        std::lock_guard<std::mutex> lock(buffer_mutex_);
        if(Empty())
        {
            //LOG(WARNING) <<"CacheBuffer::IS Empty" <<"\n";
        }else {
            data = buffer_[rear_];
            rear_ = GetIndex(++rear_);
        }
    }

    return data;
}

} // data namespace

} // ex namespace
#endif
