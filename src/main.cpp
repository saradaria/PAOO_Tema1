#include "email/Email.h"
#include "gmail/Gmail.h"
#include "mail_manager/MailManager.h"
#include <iostream>
using std::cout;
using std::string;
using std::endl;
#include <vector>
#include <memory>


int main() {

    std::vector<std::unique_ptr<communication::Email>> emailuri;

    // Adăugarea unui Email
    emailuri.push_back(std::make_unique<communication::Email>("Subiect 1", "sara.daria@yahoo.com", "Mesaj 1"));

    // Adăugarea unui Gmail
    emailuri.push_back(std::make_unique<communication::Gmail>("Subiect 2", "ana.maria2@gmail.com", "Mesaj 2"));

    // Afișarea emailurilor
    communication::afiseazaEmailuri(emailuri);

    cout<<endl;

    std::shared_ptr<communication::Email> email = std::make_shared<communication::Email>("Intalnire", "maria.paula@email.com", "Avem daily maine la 11:00");

    std::vector<string> destinatari = {"colega1@yahoo.com", "colega2@yahoo.com", "colega3@yahoo.com"};
    communication::trimiteLaDestinatari(email, destinatari);

    cout<<endl;

    communication::Email email2("Daily Meeting", "sara.baciut@yahoo.ro", "Intalnirea zilnica este la ora 10!!!!");
    communication::Gmail gmail2("Iesire cafea", "sara.daria@yahoo.ro", "Te astept sambata la o cafea in Unirii la 14:00");

    // Adaug un sufix la subiectul emailului, o data string, o data int
    email2.adaugaSufixLaSubiect(" - actualizat");
    gmail2.adaugaSufixLaSubiect(2023);

    // Afisez subiectele actualizate
    cout << "Subiect Email: " << email2.getSubiect() << endl;
    cout << "Subiect Gmail: " << gmail2.getSubiect() << endl;

    cout<<endl;

    cout<<"Cream un manager pt Emailuri"<<endl;

    communication::MailManager<communication::Email> MailManager;
    MailManager.adaugaMail("Subiect 1", "destinatar1@example.com", "Mesajul 1");
    MailManager.adaugaMail("Subiect 2", "destinatar2@example.com", "Mesajul 2");

    MailManager.trimiteMailuri();

    //MailManager.afiseazaEmailuri();

    cout<<endl;
    cout<<"Cream un manager pt Gmailuri"<<endl;

    communication::MailManager<communication::Gmail> gMailManager;
    gMailManager.adaugaMail("Subiect 1", "destinatar1@gmail.com", "Mesajul 1");
    gMailManager.adaugaMail("Subiect 2", "destinatar2@gmail.com", "Mesajul 2");

    gMailManager.stergeMailuri();

    return 0;
}
