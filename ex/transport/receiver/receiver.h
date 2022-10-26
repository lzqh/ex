#ifndef __TRANSPORT_RECEIVER_H
#define __TRANSPORT_RECEIVER_H

#include <functional>
#include "transport/dispatcher/dispatcher.h"
#include "proto/role_attributes.pb.h"

namespace ex
{

    namespace transport
    {

        template <typename T>
        class Receiver
        {
        public:
            using MessagePtr = std::shared_ptr<T>;
            using MessageListener = std::function<void(const proto::RoleAttributes &attr, const MessagePtr &)>;

            Receiver(const proto::RoleAttributes &attr, const MessageListener &listener);
            virtual ~Receiver();

            virtual bool Enable() = 0;
            virtual bool Disable() = 0;

        protected:
            void OnNewMessage(const MessagePtr &msg);

        protected:
            MessageListener listener_;
            proto::RoleAttributes attr_;
        };

        template <typename T>
        Receiver<T>::Receiver(const proto::RoleAttributes &attr, const MessageListener &listener) : attr_(attr), listener_(listener)
        {
        }

        template <typename T>
        Receiver<T>::~Receiver() {}

        template <typename T>
        void Receiver<T>::OnNewMessage(const MessagePtr &msg)
        {
            if (listener_ != nullptr)
                listener_(attr_, msg);
        }

    } // end transport

} // end ex

#endif
