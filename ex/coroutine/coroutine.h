#ifndef __EX_COROUTINE_H
#define __EX_COROUTINE_H

#include <functional>
#include "common/log.h"

namespace ex{
namespace coroutine{

using Func =std::function<void()>;
class Coroutine{
public:
    Coroutine(const Func&);
    ~Coroutine();

    void operator()()
    {   
        func_();
        
    }
    uint64_t get_cr_id() const
    {
        return cr_id_;
    }

    void set_cr_id(const uint64_t id)
    {
        cr_id_ =id;
    }
private:
    Func func_;
    uint64_t cr_id_;

};

}
}

#endif