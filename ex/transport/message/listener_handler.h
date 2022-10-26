#ifndef __MESSAGE_LISTENER_HANDLER_H
#define __MESSAGE_LISTENER_HANDLER_H

#include "listener_handler_base.h"
#include "base/signal.h"
#include  <vector>

namespace ex{

namespace transport{


template <typename T>
class ListenerHandler: public ListenerHandlerBase
{
public:
    using MsgType =std::shared_ptr<T>;
    using Callback = std::function<void(const MsgType&)>;
    using SignalType =base::Signal<const MsgType&>;
    using SlotType = base::Slot<const MsgType&>;
    using ConnectionType =base::Connection<const MsgType&>;
   

    bool AddListener(const Callback&);
    bool RemoveListener(Callback&);
    void Run(const MsgType &msg);
private:
    uint64_t channel_id_;
    SignalType signal_;
    std::vector<ConnectionType> connections_;
};

template <typename T>
void ListenerHandler<T>::Run(const MsgType &msg)
{
    signal_(msg);

}

template <typename T>
bool ListenerHandler<T>::AddListener(const Callback& func)
{
    auto conn =signal_.Connect(func);
    connections_.emplace_back(conn);
    return true;

}

template <typename T>
bool ListenerHandler<T>::RemoveListener(Callback& func)
{
    return true;
}

}// end transport
}// end ex

#endif
