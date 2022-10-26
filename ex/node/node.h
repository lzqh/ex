#ifndef _EX_NODE_H
#define _EX_NODE_H

#include <string>
#include <mutex>
#include <map>
#include <functional>
#include "proto/role_attributes.pb.h"
#include "reader.h"
#include "writer.h"
#include "common/utility.h"


namespace ex{
class Node{
public:
    friend auto CreateNode(const std::string& name, const std::string& space)->std::unique_ptr<Node>;

    explicit Node(const std::string &node_name, const std::string &name_space);

    template <typename T>
    auto CreateReader(const std::string& channel_name, const std::function<void(const std::shared_ptr<T>&)>& func)->std::shared_ptr<Reader<T>>;
    template <typename T>
    auto CreateWriter(const std::string& channel_name)->std::shared_ptr<Writer<T>>;
private:
    proto::RoleAttributes node_attr;
};

template <typename T>
auto Node::CreateReader(const std::string& channel_name, const std::function<void(const std::shared_ptr<T>&)>& func)->std::shared_ptr<Reader<T>>
{
    RoleAttributes reader_attr(node_attr);
    reader_attr.set_channel_id(common::Hash(channel_name));
    reader_attr.set_channel_name(channel_name);
    std::shared_ptr<Reader<T>> reader=nullptr;
    reader=std::make_shared<Reader<T>>(reader_attr,func);
    if(!reader->Init())
    {
        return nullptr;
    }
    return  reader;
}

template <typename T>
auto Node::CreateWriter(const std::string& channel_name)->std::shared_ptr<Writer<T>>
{
    RoleAttributes writer_attr(node_attr);
    writer_attr.set_channel_id(common::Hash(channel_name));
    writer_attr.set_channel_name(channel_name);
    std::shared_ptr<Writer<T>> writer =nullptr;
    writer=std::make_shared<Writer<T>>(writer_attr);
    if(!writer->Init())
    {   
        return nullptr;
    }
    return writer;

}


}//end ex namespace




#endif
