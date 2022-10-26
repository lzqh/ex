#ifndef EX_DATA_VISITOR_BASE_H
#define EX_DATA_VISITOR_BASE_H

#include "data/data_notifier.h"

namespace ex{
namespace data{

using data::Notifier;
class DataVisitorBase{
public:
    DataVisitorBase():notifier_(new Notifier()) {}

    virtual ~DataVisitorBase() {}

    void RegisterNotifierCallback(std::function<void()>&& func)
    {
        notifier_->callback_ = func;
    }
protected:
    std::shared_ptr<data::Notifier> notifier_;
    

};

}
}

#endif