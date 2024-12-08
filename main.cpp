#include <iostream>
#include <string>

//*class Book {
/*  std::string title;
    int pages;

public:
    // Constructor
    Book(const std::string& title, int pages) : title(title), pages(pages) {}

    // Operatorul de atribuire
    Book& operator=(const Book& other) {
        // Copiem datele obiectului `other` în `*this`
        title = other.title;
        pages = other.pages;
        return *this; // Returnăm o referință la obiectul curent
    }

    // Afișare
    void display() const {
        std::cout << "Book: " << title << ", Pages: " << pages << '\n';
    }
};
*/

class Tren {
    std::string nume;
    int vagoane;

public:
    Tren(const std::string& nume, int vagoane)
        : nume(nume), vagoane(vagoane) {}

// Operatorul de atribuire
    Tren& operator=(const Tren& other) {
        // Copiem datele obiectului `other` în `*this`
        nume = other.nume;
        vagoane = other.vagoane;
        return *this; // Returnăm o referință la obiectul curent
    }

    void afiseaza() const {
        std::cout << "Nume tren: " << nume << ", Vagoane: " << vagoane << "\n";
    }
};

int main() {
    Tren t1("IR 797", 4);
    Tren t2("R 13708", 6);
    
    t1 = t2; // Atribuire
    t1.afiseaza(); // Arată datele lui `t2` copiate în `t1`

    return 0;
}
