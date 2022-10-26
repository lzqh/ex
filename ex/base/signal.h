#ifndef __BASE_SIGNAL_H
#define __BASE_SIGNAL_H

#include <list>
#include <mutex>

namespace ex{
namespace base{

template <typename... Args>
class Connection;

template <typename... Args>
class Slot;


template<typename... Args>
class Signal{
public:
    using ConnectType = base::Connection<Args...>;
    using Callback =std::function<void(Args... )>;
    using SlotType = base::Slot<Args...>;
    using SlotPtr =std::shared_ptr<SlotType>;
    using SlotList =std::list<SlotPtr>;


    void operator()(Args...args)
    {
        for(auto &slot :slot_list_)
        {
            (*slot)(args...);
        }
    }


    ConnectType Connect(const Callback& cb)
    {
        auto slot = std::make_shared<SlotType>(cb);
        {
            std::lock_guard<std::mutex> lock(slot_mutex_);
            slot_list_.emplace_back(slot);
        }
        return ConnectType(slot,this);
    }

    void Disconnect(const ConnectType &con)
    {
        for(auto &slot : slot_list_ )
        {
            if(con.Has_slot(slot))
            {
                slot->Disconnect();
            }
        }

        ClearDisconnectedSlots();
    }

    void ClearDisconnectedSlots()
    {

    }

private:
    std::mutex slot_mutex_;
    SlotList slot_list_;
};

template<typename... Args>
class Slot {
public:
    using Callback =std::function<void(Args...)>;

    void operator()(Args... args)
    {
        if(connected_ && cb_)
        {
            cb_(args...);
        }
    }

    explicit Slot(const Callback &cb, bool connected =true)
        :cb_(cb),connected_(connected){}

    Slot(const Slot& another)
        :cb_(another.cb_),connected_(another.connected_){}

    bool Connected() const  { return connected_; }
    void Disconnect() { connected_ =false; }


private:
    Callback cb_;
    bool connected_=true;

};

template<typename... Args>
class Connection
{
public:
    using SignalPtr = std::shared_ptr<base::Signal<Args...>>;
    using SlotPtr = std::shared_ptr<base::Slot<Args...>>;
    using SlotType = base::Slot<Args...>;
    using SignalTypePtr =base::Signal<Args...>*;

    Connection(const SlotPtr& slot, const SignalTypePtr& signal)
        :signal_(signal),slot_(slot){}

    void Disconnect()
    {
        slot_->Disconnect();
    }

    bool HasSlot(const SlotPtr& slot)
    {
        return slot == slot_ ? true:false;
    }

private:
    SignalTypePtr signal_;
    SlotPtr slot_;
};


}

}

#endif
