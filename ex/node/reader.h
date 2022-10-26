#ifndef _EX_READER_H
#define _EX_READER_H

#include "node/reader_base.h"
#include "proto/role_attributes.pb.h"
#include "data/data_visitor.h"
#include "coroutine/coroutine_factory.h"
#include "scheduler/policy/classic_scheduler.h"

namespace ex{
    
using proto::RoleAttributes;
using ex::scheduler::ClassicScheduler;

template <typename T>
class Reader : public ReaderBase
{
public:
    using CallbackFunc = std::function<void(const std::shared_ptr<T>&)>;
    explicit Reader(const RoleAttributes& attr,const CallbackFunc& func);
    ~Reader();

    bool Init();
    bool Stop();
private:
    CallbackFunc func_;    
    
};

template <typename T>
Reader<T>::Reader(const RoleAttributes& attr,const CallbackFunc& func):ReaderBase(attr),func_(func)
{

}
template <typename T>
Reader<T>::~Reader() {}

template <typename T>
bool Reader<T>::Init()
{
    std::shared_ptr<data::DataVisitor<T>> visitor= std::make_shared<data::DataVisitor<T>>(attr_);
    std::function<void(const std::shared_ptr<T>& msg)> read_func_;
    if(func_ != nullptr)
    {
        read_func_ =[this](const std::shared_ptr<T>& msg){
            this->func_(msg);
        };
    }else{
        return false;
    }
    coroutine::CoroutineFactory factory =coroutine::CreateCoroutineFactory<T>(visitor,std::move(read_func_));
    std::string taskname = attr_.node_name()+ "_" + attr_.channel_name();
    ClassicScheduler::Instance()->CreateTask(factory, taskname);
    
    auto receiver =ReceiverManger<T>::Instance()->GetReceiver(attr_);
    receiver->Enable();
    return true;
}




}

#endif
