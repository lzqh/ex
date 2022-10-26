#ifndef __EX_PROCESSOR_CONTEXT_H
#define __EX_PROCESSOR_CONTEXT_H

namespace ex{
namespace scheduler{
    
class ProcessorContext{
public:
    virtual void Wait() =0;
    virtual void Process() =0;
};

}
}
#endif