// common/IEmail.h
#pragma once

namespace communication {

class IEmail {
public:
    virtual void send() const = 0;
    virtual ~IEmail() {}
};

} // namespace communication

