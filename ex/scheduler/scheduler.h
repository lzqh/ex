#ifndef __EX_SCHEDULER_H
#define __EX_SCHEDULER_H

#include <mutex>
#include <memory>
#include <unordered_map>
#include "coroutine/coroutine_factory.h"
#include "coroutine/coroutine.h"
#include "data/data_visitor_base.h"

namespace ex{
namespace scheduler{
using coroutine::CoroutineFactory;
using coroutine::Coroutine;
using data::DataVisitorBase;

class Scheduler{
public:
    Scheduler(const Scheduler& ) =delete;
    Scheduler& operator= (const Scheduler& ) =delete;
    Scheduler() {}
    virtual ~Scheduler() { id_crs_map_.clear(); }

    bool CreateTask(const coroutine::CoroutineFactory& factory,std::string& task_name);
    bool CreateTask(std::function<void()>&& func,std::shared_ptr<DataVisitorBase> visitor=nullptr,const std::string& task_name="");

    virtual bool DispatchTask(const std::shared_ptr<Coroutine> &) =0;
    virtual void NotifyProcessor(uint64_t taskid) =0;
protected:
    std::mutex id_crs_map_mutex_;
    std::unordered_map<uint64_t, std::shared_ptr<coroutine::Coroutine>> id_crs_map_;


};

}

}


#endif
