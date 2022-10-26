#ifndef __TRANSPORT_INTRA_TRANSMITTER_H
#define __TRANSPORT_INTRA_TRANSMITTER_H

#include "transmitter.h"
#include "transport/dispatcher/intra_dispatcher.h"

namespace ex{

namespace transport{

template <typename T>
class IntraTransmitter : public Transmitter<T>
{
public:
    using MsgType =std::shared_ptr<T>;
    IntraTransmitter(const proto::RoleAttributes& attr):Transmitter<T>(attr) {}
    virtual ~IntraTransmitter() {}

    bool Transmit(const MsgType& msg);
    void Enable() override;
    void Disable() override;

private:
    IntraDispatcher* dispatcher_=nullptr;
};

template <typename T>
void IntraTransmitter<T>::Enable()
{
    dispatcher_ = IntraDispatcher::Instance();
}

template <typename T>
void IntraTransmitter<T>::Disable()
{
    dispatcher_=nullptr;
}

template <typename T>
bool IntraTransmitter<T>::Transmit(const MsgType& msg)
{
    return dispatcher_->Dispatch(IntraTransmitter<T>::attr_.channel_id(),msg);  
}

}
}


#endif // __TRANSPORT_INTRA_TRANSMITTER_H
