// gmail/Gmail.cpp
#include "Gmail.h"
#include <iostream>
using std::string;
using std::cout;
using std::endl;

namespace communication {
    Gmail::Gmail(const string &subiect, const string &destinatar, const char *text)
        : Email(subiect, destinatar, text) {} // apelez const de la email

    // Copy constructor
    Gmail::Gmail(const Gmail &other) : Email(other) {}

    // Move constructor
    Gmail::Gmail(Gmail&& other) noexcept : Email(std::move(other)) {}

    void Gmail::send() const {
        cout << "Gmail trimis catre" << getDestinatar() << "cu textul: " << getText() << endl;
    }

    void Gmail::archive() const {
        cout << "Gmailul de la " << getDestinatar()  << " avand subiectul" << getSubiect() << "a fost arhivat" << endl;
    }

} // namespace communication
