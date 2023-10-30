#include <iostream>
#include <cstring>
#include "main.h"
using namespace std;

class Email {
private:
    string subiect;
    string destinatar;
    char* text;  // ca sa fac cv cu destructorul
public:
    Email(const string &subiect, const string &destinatar, const char *textSrc) {
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
    Email(const Email &altEmail) {
        subiect = altEmail.subiect;
        destinatar = altEmail.destinatar;
        text = new char[strlen(altEmail.text) + 1];
        strcpy(text, altEmail.text);
        cout<<"Copy constructor apelat";
    }

    // Destructor
    ~Email() {
        delete[] text;
    }

    // Overload la assign op
    Email& operator=(const Email &altEmail) {
        if (this == &altEmail)  // sa nu fie acelasi ob
            return *this;
        subiect = altEmail.subiect;
        destinatar = altEmail.destinatar;
        delete[] text;
        text = new char[strlen(altEmail.text) + 1];
        strcpy(text, altEmail.text);

        return *this;
    }


    void setText(const char *newText){
        if(newText != NULL){
        delete[] text;
        text = new char[strlen(newText) + 1];
        strcpy(text, newText);
        }
    }

    void setSubject(const string newSubject){
            subiect = newSubject;
    }

    const char* getText() {
        return text;
    }

    // Metoda modificată pentru a afișa informații despre obiectul actual
    void showObjInfo() const {
        cout << "Destinatar: " << this->destinatar << endl;
        cout << "Subiect: " << this->subiect << endl;
        cout << "Text: " << this->text << endl;
    }

};

int main() {


    Email email1("Sedinta daily", "sara.daria@yahoo.ro", "Avem daily la 10");
    Email email2 = email1; // apeleaza copy constructor

    cout << endl;
    email2.setText("Sedinta s-a mutat la 11:00");
    email2.setSubject("Schimbare ora sedinta");


    cout << "Email 2 Text: " << email2.getText() << endl;
    cout << "Email 1 Text: " << email1.getText() << endl;

    cout << endl;

    email1.showObjInfo();
    cout << endl;
    email2.showObjInfo();

    /*
    // nu se apeleaza copy const dar am eroare daca nu am un default constructor
    Email emailNoCopy1("Salut", "destinatar@yahoo.com", "Buna ziua!");
    Email emailNoCopy2;
    emailNoCopy2 = emailNoCopy1;  // Nu se apelează copy constructorul, ci operatorul de atribuire
    */


    return 0;
}
