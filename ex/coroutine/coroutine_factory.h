#ifndef __EX_COROUTINE_FACTORY_H
#define __EX_COROUTINE_FACTORY_H

#include <functional>
#include <memory>
#include "data/data_visitor.h"
#include "data/data_visitor_base.h"

namespace ex{
namespace coroutine{

    using ex::data::DataVisitor;
    using ex::data::DataVisitorBase;
    //using CallbackFunc= std::function<void(std::shared_ptr<int>&)>;
    using VoidFunc =std::function<void()>;
    using Coroutinefunc =std::function<VoidFunc()>;
    class CoroutineFactory;

    //CoroutineFactory CreateCoroutineFactory(const std::shared_ptr<DataVisitor>& visitor,CallbackFunc& func);

    class CoroutineFactory
    {
    public:
        //CoroutineFactory(const DataVisitor& visitor,const CallbackFunc&);
        //~CoroutineFactory();
        //Coroutinefunc& CreateCoroutineFunction();
        //CoroutineFactory(const DataVisitor& visitor,const Coroutinefunc& func);
        CoroutineFactory();
        ~CoroutineFactory();

        Coroutinefunc create_routine;
        inline void SetDataVisitor(const std::shared_ptr<data::DataVisitorBase>& dv) {
            visitor_ = dv;
        }
        inline std::shared_ptr<data::DataVisitorBase> GetDataVisitor() const {
            return visitor_;
        }
    private:
        std::shared_ptr<DataVisitorBase> visitor_=nullptr;

    };






template <typename T>
CoroutineFactory CreateCoroutineFactory(const std::shared_ptr<DataVisitor<T>>& visitor,std::function<void(const std::shared_ptr<T>&)>&& func)
{
    CoroutineFactory factory;
    factory.SetDataVisitor(visitor);
    factory.create_routine =[=]() {
        return [=]() {
            std::shared_ptr<T> msg;
            if(visitor->TryGet(msg))
            {
                func(msg);
            }else
            {
                //LOG(WARNING) << "visitor->TryGet return False";

            }
            
        };

    };
    return factory;
}

}

}

#endif
