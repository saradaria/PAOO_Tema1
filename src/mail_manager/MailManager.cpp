// mail_manager/MailManager.cpp
#include "MailManager.h"
#include<memory>
#include<iostream>
namespace communication {

template<typename EmailType>
void MailManager<EmailType>::adaugaMail(const std::string& subiect, const std::string& destinatar, const char *text) {
    emailuri.push_back(std::make_unique<EmailType>(subiect, destinatar, text));
}

template<typename EmailType>
void MailManager<EmailType>::trimiteMailuri() {
    for (const auto& email : emailuri) {
        email->send();
    }
    std::cout << "Mail-urile au fost trimise" << std::endl;
}

template<typename EmailType>
void MailManager<EmailType>::stergeMailuri() {
    emailuri.clear();
    std::cout << "Mail-urile au fost sterse" << std::endl;
}

template<typename EmailType>
void MailManager<EmailType>::afiseazaMailuri() {
    for (const auto& email : emailuri) {
        email->showObjInfo();
    }
}

template class MailManager<Email>;
template class MailManager<Gmail>;

} // namespace communication
