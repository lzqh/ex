#ifndef _EX_CLASSIC_CONTEXT_H
#define _EX_CLASSIC_CONTEXT_H

#include <condition_variable>
#include <vector>
#include <mutex>
#include "scheduler/processor_context.h"
#include "coroutine/coroutine.h"
#include "base/atomic_rw_lock.h"

namespace ex{
namespace scheduler{
static constexpr uint32_t MAX_PRIO = 20;
using ex::coroutine::Coroutine;
using Queue =std::vector<std::shared_ptr<Coroutine>>;
using Multi_Prio_Queue =std::array<Queue,MAX_PRIO>;
using LockQueue =std::array<base::AtomicRWLock,MAX_PRIO>;

class ClassicContext : public ProcessorContext{
public:

    static void Notify();
    void Wait() override;
    void Process() override;

    static std::mutex multi_prio_queue_mutex_;
    static Multi_Prio_Queue multi_prio_queue_;

    static std::mutex notify_count_mutex_;
    static uint64_t notify_count_;
    static std::condition_variable cv_;
    static LockQueue lock_queue_;
    
};

}
}
#endif