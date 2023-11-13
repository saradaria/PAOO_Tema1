#include "Email.h"
#include <cstring>
#include <sstream>
#include <vector>
#include <memory>
#include <iostream>

namespace communication {

    void afiseazaEmailuri(const std::vector<std::unique_ptr<Email>>& emailuri) {
    for (const auto& email : emailuri) {
        email->send();
        }
    }

    void trimiteLaDestinatari(const std::shared_ptr<Email>& email, const std::vector<std::string>& destinatari) {
    for (const auto& destinatar : destinatari) {
        email->setDestinatar(destinatar);
        email->send();
        }
    }
  Email::Email(const std::string &subiect, const std::string &destinatar, const char *textSrc) {
        this->subiect = subiect;
        this->destinatar = destinatar;
        text = new char[strlen(textSrc) + 1];
        strcpy(text, textSrc);
    }

    /*
    //constructor fara parametrii
    public:
        Email() {
            subiect = "";
            destinatar = "";
            text = nullptr;
        }
    */

    // Copy constructor
    Email::Email(const Email &altEmail) {
        subiect = altEmail.subiect;
        destinatar = altEmail.destinatar;
        text = new char[strlen(altEmail.text) + 1];
        strcpy(text, altEmail.text);
        std::cout << "Copy constructor apelat" << std::endl;
    }

    // Move constructor
    Email::Email(Email &&altEmail) noexcept {
        subiect = std::move(altEmail.subiect);
        destinatar = std::move(altEmail.destinatar);
        text = altEmail.text;
        altEmail.text = nullptr;
        std::cout << "Move constructor apelat"<< std::endl;
    }

    // Destructor
    Email::~Email() {
        delete[] text;
    }

    // Overload la assign op
    Email& Email::operator=(const Email &altEmail) {
        if (this != &altEmail) { // Self-assignment check
            subiect = altEmail.subiect;
            destinatar = altEmail.destinatar;

            delete[] text; // Deallocate old text
            text = new char[strlen(altEmail.text) + 1];
            strcpy(text, altEmail.text);
        }
        return *this;
    }


    void Email::setText(const char *newText){
        if(newText != NULL){
        delete[] text;
        text = new char[strlen(newText) + 1];
        strcpy(text, newText);
        }
    }

    void Email::setSubject(const std::string newSubject){
            subiect = newSubject;
    }

    const char* Email::getText() const {
        return text;
    }

    std::string Email::getDestinatar() const {
        return destinatar;
    }

    void Email::setDestinatar(const std::string& nouDestinatar) {
        destinatar = nouDestinatar;
    }

    std::string Email::getSubiect() const {
        return subiect;
    }

    void Email::setSubiect(const std::string& nouSubiect) {
        subiect = nouSubiect;
    }

    // Metoda modificată pentru a afișa informații despre obiectul actual
    void Email::showObjInfo() const {
        std::cout << "Destinatar: " << this->destinatar << std::endl;
        std::cout << "Subiect: " << this->subiect << std::endl;
        std::cout << "Text: " << this->text << std::endl;
    }

    // Functie ce trb implementata
    void Email::send() const {
        std::cout << "Email trimis catre " << destinatar << " cu textul: " << text << std::endl;
    }
}

