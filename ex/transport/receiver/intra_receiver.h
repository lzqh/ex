#ifndef EX_TRANSPORT_INTRA_RECEIVER_H
#define EX_TRANSPORT_INTRA_RECEIVER_H

#include "receiver.h"
#include "transport/dispatcher/intra_dispatcher.h"


namespace ex{

namespace transport{

template <typename T>
class IntraReceiver: public Receiver<T>{
public:
    using MessagePtr =std::shared_ptr<T>;
    using MessageListener = std::function<void(const proto::RoleAttributes& attr,const MessagePtr&)>;

    IntraReceiver(const proto::RoleAttributes& attr,const MessageListener& listener);
    virtual ~IntraReceiver();
    
    bool Enable() override;
    bool Disable() override;
private:
    IntraDispatcher* dispatcher_;

};

template <typename T>
IntraReceiver<T>::IntraReceiver(const proto::RoleAttributes& attr,const MessageListener& listener):Receiver<T>(attr,listener)
{
    dispatcher_ = IntraDispatcher::Instance();
}

template <typename T>
IntraReceiver<T>::~IntraReceiver()
{
    Disable();
}


template <typename T>
bool IntraReceiver<T>::Enable()
{
    return dispatcher_->AddListener<T>(IntraReceiver<T>::attr_.channel_id(),std::bind(&IntraReceiver<T>::OnNewMessage,this,std::placeholders::_1));
}

template <typename T>
bool IntraReceiver<T>::Disable()
{
    return true;
}



}
}

#endif
