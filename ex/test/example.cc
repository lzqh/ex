
#include <iostream>
#include <memory>
#include <chrono>
#include <thread>
#include "../proto/role_attributes.pb.h"
#include "../proto/sample.pb.h"
#include "../ex.h"

using ex::proto::RoleAttributes;
using ex::proto::Driver;
using ex::proto::Chatter;


void Callback1(const std::shared_ptr<Driver>& msg)
{
    std::cout << "Callback1 content= "<< msg->content() << "  msg_id= " << msg->msg_id() << std::endl;
}

void Callback2(const std::shared_ptr<Chatter>& msg)
{   
    std::cout << "Callback2 content= "<< msg->content() << "  seq= " << msg->seq() << std::endl;

}



int main(int argc, char **argv)
{
    RoleAttributes attr;
    if(!ex::Init(argv[0]))
    {
        return -1;
    }
    auto node = ex::CreateNode("testnode");
    auto writer1 =node->CreateWriter<Driver>("channel/test1");
    auto reader1 =node->CreateReader<Driver>("channel/test1",Callback1);

    auto writer2 =node->CreateWriter<Chatter>("channel/test2");
    auto reader2 =node->CreateReader<Chatter>("channel/test2",Callback2);
    std::string content("Driver send");
    while(1)
    {
        
        static uint64_t seq = 0;
        auto msg = std::make_shared<Driver>();
        msg->set_msg_id(seq++);
        msg->set_content(content);
        writer1->Write(msg);

        auto msg1 = std::make_shared<Chatter>();
        msg1->set_content("Talker send");
        msg1->set_seq(seq++);
        writer2->Write(msg1);
        
        std::this_thread::sleep_for(std::chrono::seconds(1));

    }
    ex::Shutdown();
    
    return 0;
}
