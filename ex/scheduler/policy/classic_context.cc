#include "scheduler/policy/classic_context.h"
#include "base/atomic_rw_lock.h"
#include "base/rw_lock_guard.h"
#include "common/log.h"

namespace ex{
namespace scheduler{

using base::AtomicRWLock;
using base::ReadLockGuard;
using base::WriteLockGuard;

std::mutex ClassicContext::multi_prio_queue_mutex_;
Multi_Prio_Queue ClassicContext::multi_prio_queue_;
std::mutex ClassicContext::notify_count_mutex_;
uint64_t ClassicContext::notify_count_;
std::condition_variable ClassicContext::cv_;
LockQueue ClassicContext::lock_queue_;

void ClassicContext::Notify()
{
    {
        std::lock_guard<std::mutex> lock(notify_count_mutex_);
        ++notify_count_;
    }
    cv_.notify_one();

}

void ClassicContext::Wait()
{
    std::unique_lock<std::mutex> lock(notify_count_mutex_);
    //cv_.wait_for(lock,std::chrono::milliseconds(1000),[]{ return notify_count_>0; });
    cv_.wait(lock,[]{ return notify_count_>0; });
   
    if(notify_count_>0)
    {
        --notify_count_;
    }

}

void ClassicContext::Process()
{
    
    /*
    std::lock_guard<std::mutex> lock(multi_prio_queue_mutex_);
    for(int i=MAX_PRIO-1; i>=0; i--)
    {
        for(auto &cr : multi_prio_queue_.at(i))
        {   
            (*cr)();
        }
    }*/

    
    for(int i=MAX_PRIO-1; i>=0; i--)
    {   
        ReadLockGuard<AtomicRWLock> lk(lock_queue_.at(i));
        for(auto &cr : multi_prio_queue_.at(i))
        {   
            (*cr)();
        }
    }

}

}
}