#include "scheduler/policy/classic_scheduler.h"

namespace ex{
namespace scheduler{

void ClassicScheduler::Init()
{   
    CreateProcessorGroup();
}

void ClassicScheduler::CreateProcessorGroup()
{
    for(int i=0;i<5;i++)
    {
        std::shared_ptr<ClassicContext> context = std::make_shared<ClassicContext>();
        std::shared_ptr<Processor> processor(new Processor());
        processor->BindContext(context);
        processors_.emplace_back(processor);
    }
   

}


bool ClassicScheduler::DispatchTask(const std::shared_ptr<Coroutine>& cr)
{

    {
        std::lock_guard<std::mutex> lock(ClassicContext::multi_prio_queue_mutex_);
        ClassicContext::multi_prio_queue_.at(MAX_PRIO-1).emplace_back(cr);

    }
    ClassicContext::Notify();
    return true;

}

void ClassicScheduler::NotifyProcessor(uint64_t taskid)
{
   ClassicContext::Notify();
}

}
}