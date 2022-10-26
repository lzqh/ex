#include "scheduler/scheduler.h"
#include "common/utility.h"
#include <memory>
#include "data/data_visitor_base.h"
#include "common/log.h"
namespace ex{
namespace scheduler{

using ex::data::DataVisitorBase;

bool Scheduler::CreateTask(const coroutine::CoroutineFactory& factory,std::string& task_name)
{
    return CreateTask(factory.create_routine(),factory.GetDataVisitor(),task_name);
}

bool Scheduler::CreateTask(std::function<void()>&& func,std::shared_ptr<DataVisitorBase> visitor,const std::string& task_name)
{
    auto taskid =common::Hash(task_name);
    std::shared_ptr<Coroutine> cr=std::make_shared<Coroutine>(func); 
    cr->set_cr_id(taskid);

    visitor->RegisterNotifierCallback( [this,taskid]()
    {
        this->NotifyProcessor(taskid);
    });

    if(DispatchTask(cr))
    {
        id_crs_map_.insert({taskid,cr});
    }else{


    }
    return true;
}


}
}