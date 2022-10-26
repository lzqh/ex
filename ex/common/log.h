#ifndef EX_COMMON_LOG_H
#define EX_COMMON_LOG_H

#include <glog/logging.h>

namespace ex{
namespace common{
    bool InitLog(const char* argv);
    void ShutdownLog();
}
}

#endif