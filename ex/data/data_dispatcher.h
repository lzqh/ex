#ifndef __DATA_DATA_DISPATCHER_H
#define __DATA_DATA_DISPATCHER_H

#include <memory>
#include <mutex>
#include <unordered_map>
#include "channel_buffer.h"
#include "common/macros.h"
#include "data/data_notifier.h"

namespace ex
{

    namespace data
    {

        template <typename T>
        class DataDispatcher
        {
        public:
            using MsgType = std::shared_ptr<T>;

            ~DataDispatcher() {}
            void Dispatch(uint64_t channel_id, const MsgType &msg);
            std::shared_ptr<ChannelBuffer<T>> GetChannelBuffer(uint64_t channel_id);
            void SetChannelBuffer(uint64_t channel_id, const std::shared_ptr<ChannelBuffer<T>> &);

        private:
            std::unordered_map<uint64_t, std::shared_ptr<ChannelBuffer<T>>> id_buffers_;
            std::mutex id_buffers_mutex_;

            DECLARE_SINGLETON(DataDispatcher)
        };

        template <typename T>
        inline DataDispatcher<T>::DataDispatcher() {}

        template <typename T>
        void DataDispatcher<T>::Dispatch(uint64_t channel_id, const MsgType &msg)
        {
            auto search = id_buffers_.find(channel_id);
            if (search != id_buffers_.end())
            {
                std::shared_ptr<ChannelBuffer<T>> channelbuffer = search->second;
                (*channelbuffer).Put(msg);
            }
            else
            {

                std::cout << "channel_id not find in datadispathcer" << channel_id << std::endl;
            }
            data::DataNotifier::Instance()->Notify(channel_id);
        }

        template <typename T>
        std::shared_ptr<ChannelBuffer<T>> DataDispatcher<T>::GetChannelBuffer(uint64_t channel_id)
        {
            auto search = id_buffers_.find(channel_id);
            if (search != id_buffers_.end())
            {
                return search->second;
            }
            else
            {
            }
            return nullptr;
        }

        template <typename T>
        void DataDispatcher<T>::SetChannelBuffer(uint64_t channel_id, const std::shared_ptr<ChannelBuffer<T>> &channel_buffer)
        {
            std::lock_guard<std::mutex> lock(id_buffers_mutex_);
            id_buffers_.emplace(channel_id, channel_buffer);
        }

       
    } // end namespace data
} // end namespace ex

#endif // __DATA_DATA_DISPATCHER_H
