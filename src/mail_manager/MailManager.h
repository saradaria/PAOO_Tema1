// mail_manager/MailManager.h
#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include <string>
#include "../email/Email.h"
#include "../gmail/Gmail.h"

namespace communication {

template<typename EmailType>
class MailManager {
private:
    std::vector<std::unique_ptr<EmailType>> emailuri;

public:
    void adaugaMail(const std::string& subiect, const std::string& destinatar, const char *text);
    void trimiteMailuri();
    void stergeMailuri();
    void afiseazaMailuri();
};

} // namespace communication
