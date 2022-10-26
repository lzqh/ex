#include <memory>
#include "node.h"
#include "data/global_data.h"
#include "proto/role_attributes.pb.h"
#include "reader.h"
#include "writer.h"

namespace ex{

Node::Node(const std::string &node_name,const std::string &name_space)
{
    node_attr.set_node_id(data::GlobalData::Instance()->RegisterNodeName(node_name));
}

}


