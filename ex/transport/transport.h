#ifndef EX_TRANSPORT_H
#define EX_TRANSPORT_H

#include <memory>
#include "receiver/receiver.h"
#include "transmitter/transmitter.h"
#include "transmitter/intra_transmitter.h"
#include "receiver/intra_receiver.h"

namespace ex{

namespace transport{

template <typename T>
using MessageListener =
    std::function<void(const proto::RoleAttributes& reader_attr,const std::shared_ptr<T>&)>;

template <typename T>
auto CreateReceiver(const proto::RoleAttributes& attr, const MessageListener<T>& msglistener)->std::shared_ptr<Receiver<T>>
{
    std::shared_ptr<IntraReceiver<T>> intra_receiver= std::make_shared<IntraReceiver<T>>(attr, msglistener);
    return intra_receiver;
}

template <typename T>
auto CreateTransmitter(const proto::RoleAttributes& attr)->std::shared_ptr<Transmitter<T>>
{
    std::shared_ptr<IntraTransmitter<T>> intra_transmitter = std::make_shared<IntraTransmitter<T>>(attr);
    if(intra_transmitter)
    {
        intra_transmitter->Enable();
    }
    return intra_transmitter;
}



/*
template <typename MessageT>
auto CreateTransmitter()->std::shared_ptr<Transmitter<MessageT>>;

template<typename MessageT>
auto CreateReceiver()->std::shared_ptr<Receiver<MessageT>>;

*/
}//end namespace transport

}//end namespace ex


#endif // MYCYBER_TRANSPORT_H

