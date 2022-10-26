#ifndef __EX_SCHEDULER_PROCESSOR_H
#define __EX_SCHEDULER_PROCESSOR_H


#include <memory>
#include <vector>
#include <thread>
#include <mutex>
#include "scheduler/processor_context.h"

namespace ex{
namespace scheduler{

class Processor{
public:
 
    void Run();
    void BindContext(const std::shared_ptr<ProcessorContext>& context);

private:
    std::shared_ptr<ProcessorContext> context_;
    std::once_flag thread_flag_;
    std::thread thread_;

};

}
}
#endif