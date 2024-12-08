#include <iostream>
#include <string>

//Item 10: Have assignment operators return a reference to *this.
//Item 11: Handle assignment to self in operator=.
//Item 12: Copy all parts of an object.

class Tren {
    std::string* nume; // Pointer pentru a simula alocarea dinamică
    int vagoane;

public:

    Tren(const std::string& nume, int vagoane)
        : nume(new std::string(nume)), vagoane(vagoane) {}

    //constructor de copiere
    Tren(const Tren& other)
        : nume(new std::string(*other.nume)), vagoane(other.vagoane){
            std::cout << "Ai apelat la copy constructor!" << "\n";
        }
    

//operatorul de atribuire
    Tren& operator=(const Tren& other) {
         if (this == &other) { 
            std::cout << "Ai incercat sa atribui unui obiect pe el insusi!!" << "\n";
            //verific auto-atribuirea
            return *this;
        }

        // eliberez resursele existente
        delete nume;

        //copiez datele obiectului `other`
        nume = new std::string(*other.nume);
        vagoane = other.vagoane;
        return *this; //returnez o referință la obiectul curent
    }

    // Destructor
    ~Tren() {
        delete nume;
    }

    void afiseaza() const {
        std::cout << "Nume tren: " << *nume << ", Vagoane: " << vagoane << "\n";
    }
};

int main() {
    Tren t1("IR 797", 4);
    Tren t2("R 13708", 6);
    
    //item 10
    /*t1 = t2; // Atribuire
    t1.afiseaza(); // Arată datele lui `t2` copiate în `t1`
*/

    //item 11
    /*t1=t1;
    t1.afiseaza();
*/

    //item 12
    t1=t2;          //operatorul de atribuire
    t1.afiseaza();

    Tren t3 = t1;   //constructorul de copiere
    t3.afiseaza();

    return 0;
}
