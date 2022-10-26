#ifndef __DATA_DATA_NOTIFIER_H
#define __DATA_DATA_NOTIFIER_H

#include <functional>
#include <vector>
#include <unordered_map>
#include <mutex>
#include "common/macros.h"
#include "base/atomic_hash_map.h"
namespace ex {

namespace data{


struct Notifier{
    std::function<void()> callback_;
};

class DataNotifier{
public:
    using NotifierVector =std::vector<std::shared_ptr<Notifier>>;
    ~DataNotifier() {}

    bool Notify(uint64_t channel_id);
    void AddNotifier(uint64_t channel_id, const std::shared_ptr<Notifier>& notifier);
private:
    std::mutex notifiers_map_mutex_;
    std::unordered_map<uint64_t, NotifierVector> notifiers_map_;    

    DECLARE_SINGLETON(DataNotifier)

};

inline DataNotifier::DataNotifier() {}

inline void DataNotifier::AddNotifier(uint64_t channel_id, const std::shared_ptr<Notifier>& notifier)
{
    std::lock_guard<std::mutex> lock(notifiers_map_mutex_);
    NotifierVector* notifier_vector =nullptr;
    auto search =notifiers_map_.find(channel_id);
    if(search !=notifiers_map_.end())
    {
        notifier_vector =&search->second;
        notifier_vector->emplace_back(notifier);
    }else{
        NotifierVector new_notify = {notifier};
        notifiers_map_.insert({channel_id,new_notify});
    }
}

inline bool DataNotifier::Notify(uint64_t channel_id)
{
    NotifierVector* notifier_vector =nullptr;
    auto search =notifiers_map_.find(channel_id);
    if(search !=notifiers_map_.end())
    {
        notifier_vector =&search->second;
        for(auto &notifier : *notifier_vector)
        {
            if(notifier && notifier->callback_)
            {
                notifier->callback_();
            }
        }
        return true;
    }else{
        return false;
    }
}



}

}


#endif
