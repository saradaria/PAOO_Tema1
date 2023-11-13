#pragma once
#include "../email/Email.h"

namespace communication {

class Gmail : public Email {
public:
    Gmail(const std::string &subiect, const std::string &destinatar, const char *text);
    Gmail(const Gmail &other);
    Gmail(Gmail&& other) noexcept;
    void send() const override;
    void archive() const;
};

} // namespace communication
