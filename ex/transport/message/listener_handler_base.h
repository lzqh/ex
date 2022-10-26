#ifndef __LISTENER_HANDLER_BASE_H
#define __LISTENER_HANDLER_BASE_H

#include <functional>
#include <memory>

namespace ex{
namespace transport{

class ListenerHandlerBase
{
public:
    ListenerHandlerBase() {}
    virtual ~ListenerHandlerBase() {}
};

}

}
#endif
