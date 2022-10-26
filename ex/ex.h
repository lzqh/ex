#ifndef __EX_H
#define __EX_H

#include <string>
#include "node/node.h"
#include "common/log.h"


namespace ex{

auto CreateNode(const std::string &node_name, const std::string &node_space ="")->std::unique_ptr<Node>;

bool Init(const char* argv);
void Shutdown();

}
#endif
