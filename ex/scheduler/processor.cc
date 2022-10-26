#include <mutex>
#include "scheduler/processor.h"

namespace ex{
namespace scheduler{

void Processor::Run()
{
    for(;;)
    {
        context_->Wait();
        context_->Process();
    }

}

void Processor::BindContext(const std::shared_ptr<ProcessorContext>& context)
{
    context_ =context;
    std::call_once(thread_flag_,[this](){
        thread_=std::thread(&Processor::Run,this);
    });
}

}
}