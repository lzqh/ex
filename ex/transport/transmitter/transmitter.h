#ifndef __TRANSPORT_TRANSMITTER_H
#define __TRANSPORT_TRANSMITTER_H

#include "transport/dispatcher/dispatcher.h"
#include "proto/role_attributes.pb.h"

namespace ex{

namespace transport{

template <typename T>
class Transmitter
{
public:
    using Msgtype =std::shared_ptr<T>;
    
    Transmitter(const proto::RoleAttributes& attr):attr_(attr) {}
    virtual ~Transmitter() {}

    virtual bool Transmit(const Msgtype&) =0;
    virtual void Enable() =0;
    virtual void Disable() =0;

protected:
    proto::RoleAttributes attr_;

};

}//end transport
}//end ex



#endif
