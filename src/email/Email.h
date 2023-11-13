#pragma once
#include "../common/IEmail.h"
#include <string>
#include<vector>
#include<memory>
#include<sstream>

namespace communication {


class Email : public IEmail {
private:
    std::string subiect;
    std::string destinatar;
    char* text;

public:
    Email(const std::string &subiect, const std::string &destinatar, const char *textSrc);
    Email(const Email &altEmail);
    Email(Email &&altEmail) noexcept;
    Email& operator=(const Email &altEmail);
    virtual ~Email();

    void setText(const char *newText);
    void setSubject(const std::string newSubject);
    const char* getText() const;
    std::string getDestinatar() const;
    void setDestinatar(const std::string& nouDestinatar);
    std::string getSubiect() const;
    void setSubiect(const std::string& nouSubiect);
    void showObjInfo() const;
    void send() const override;

    template<typename SufixType>
    void adaugaSufixLaSubiect(const SufixType& sufix) {
        std::ostringstream stringNou;
        stringNou << getSubiect() << sufix;
        setSubiect(stringNou.str());
    }
};

    void afiseazaEmailuri(const std::vector<std::unique_ptr<Email>>& emailuri);
    void trimiteLaDestinatari(const std::shared_ptr<Email>& email, const std::vector<std::string>& destinatari);

} // namespace communication

