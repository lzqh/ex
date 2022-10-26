#include "ex.h"
#include "node/node.h"
#include "common/log.h"


namespace ex{

auto CreateNode(const std::string &node_name,  const std::string &node_space)->std::unique_ptr<Node>
{
   return std::unique_ptr<Node>(new Node(node_name,node_space));
}

bool Init(const char* argv)
{
	common::InitLog(argv);
    return true;
}

void Shutdown()
{
	common::ShutdownLog();
}
}
