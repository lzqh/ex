#ifndef __EX_CLASSIC_SCHDULE_H
#define __EX_CLASSIC_SCHDULE_H

#include <memory>
#include "scheduler/scheduler.h"
#include "scheduler/processor.h"
#include "coroutine/coroutine.h"
#include "base/macros.h"
#include "scheduler/policy/classic_context.h"


namespace ex{
namespace scheduler{

using ex::coroutine::CoroutineFactory;
using ex::coroutine::Coroutine;

class ClassicScheduler :public Scheduler{
public:
    
    void Init();
    bool Stop();
    void CreateProcessorGroup();
    bool DispatchTask(const std::shared_ptr<Coroutine>& ) override;
    void NotifyProcessor(uint64_t taskid) override;

private:
    bool LoadTaskConfig();
    std::vector<std::shared_ptr<Processor>> processors_;
    
    DECLARE_SINGLETON(ClassicScheduler)

};

inline ClassicScheduler::ClassicScheduler() {Init();}
} //end scheduler

}//end ex

#endif