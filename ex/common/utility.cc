#include <functional>
#include "utility.h"


namespace ex{

    namespace common{

        uint64_t Hash(const std::string& name)
        {
            return std::hash<std::string> {}(name);
        }

    }
}