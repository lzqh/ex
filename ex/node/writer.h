#ifndef __EX_WRITER_H
#define __EX_WRITER_H

#include <string>
#include <memory>
#include "writer_base.h"
#include "transport/transmitter/transmitter.h"
#include "transport/transport.h"


namespace ex{

template <typename T>
class Writer : public WriterBase
{
    using MsgType =std::shared_ptr<T>;
public:
    explicit Writer(const proto::RoleAttributes& attr);
    ~Writer();

    bool Write(MsgType& msg);
    bool Init();

private:
    std::shared_ptr<transport::Transmitter<T>> transmitter_=nullptr;

};

template <typename T>
Writer<T>::Writer(const proto::RoleAttributes& attr):WriterBase(attr){}

template <typename T>
Writer<T>::~Writer() {}

template <typename T>
bool Writer<T>::Init()
{
    transmitter_ =transport::CreateTransmitter<T>(writer_attr_); 
    if(transmitter_ ==nullptr)
        return false;
    return true;
    
}

template <typename T>
bool Writer<T>::Write(MsgType& msg)
{
    return transmitter_->Transmit(msg);
}

}//end namespace ex


#endif // __MYCYBER_WRITER_H
