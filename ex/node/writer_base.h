#ifndef __WRITER_BASE_H
#define __WRITER_BASE_H

#include "proto/role_attributes.pb.h"

namespace ex{

class WriterBase{
public:
    WriterBase(const proto::RoleAttributes& attr):writer_attr_(attr) {}
    virtual ~WriterBase() {}
protected:
    proto::RoleAttributes writer_attr_;
};

}
#endif
